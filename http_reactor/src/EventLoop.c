#include "EventLoop.h"
#include "stdbool.h"
#include "stdlib.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

struct EventLoop *EventLoopInit()
{
    return EventLoopInitEX(NULL);
}

int readMsgLocal(void *arg)
{
    struct EventLoop *loop = (struct EventLoop *)arg;
    char buf[256];
    read(loop->socketPairFds[1], buf, sizeof(buf));
    return 0;
}

int writeMsgLocal(struct EventLoop *loop)
{
    char *msg = "wakeup!";
    write(loop->socketPairFds[0], msg, strlen(msg));
    return 0;
}

struct EventLoop *EventLoopInitEX(const char *name)
{
    // 初始化空间
    struct EventLoop *loop = (struct EventLoop *)malloc(sizeof(struct EventLoop));

    // 几个基础的属性变量
    loop->threadID = pthread_self();                              // EventLoop的线程号
    loop->isRunning = false;                                      // 运行状态
    strcpy(loop->threadName, name == NULL ? "MainThread" : name); // EventLoop名称
    pthread_mutex_init(&loop->mutexForList, NULL);                // TaskList的mutex
    // pthread_cond_init(&loop->condition,&loop->mutexForList);   //TaskList的条件变量

    loop->dispatcher = &EpollDispatch;               // 分发器
    loop->DispatcherData = loop->dispatcher->init(); // 初始化数据区（分发器要用的东西）

    loop->head = loop->tail = NULL; // tasklist的指针

    loop->channelMap = ChannelMapInit(128); // 根据fd找channel的map

    int res = socketpair(AF_UNIX, SOCK_STREAM, 0, loop->socketPairFds); // 初始化socketpair数组
    // 规定：loop->socketPairFds[1]读 ，loop->socketPairFds[0]写
    if (res == -1)
    {
        perror("EventLoopInitEX error! res == -1\n");
        exit(0);
    }
    // 将读的文件描述符封装到channel中 ,让dispatcher能够接受到事件，从而唤醒dispatch
    struct Channel *channel = channelInit(loop->socketPairFds[1], ReadAble, readMsgLocal, NULL, NULL, loop);
    // 将这个channel加入task列表当中
    res = EventLoopAddTask(loop, channel, ReadAble);

    return loop;
}

int EventLoopRun(struct EventLoop *loop)
{
    if (loop == NULL)
    {
        printf("EventLoopRun Error!loop == NULL\n");
    }
    assert(loop != NULL);

    struct Dispatcher *dispatcher = loop->dispatcher;
    if (dispatcher == NULL)
    {
        printf("EventLoopRun Error!dispatcher == NULL\n");
    }

    while (loop->isRunning)
    {
        dispatcher->dispatch(loop, 2);
        // 这里还要添加一个将tasklist中任务挂载到dispatch中的函数
        EventLoopListProcess(loop);
    }

    return 0;
}

int activateFD(struct EventLoop *loop, int fd, int event)
{
    if (fd < 0 || loop == NULL)
    {
        printf("activateFD Error! fd<0 || loop==NULL\n");
        return -1;
    }
    // 从map中取出channel
    struct Channel *channel = loop->channelMap->list[fd];
    // 断言：channel中的fd必须和形参fd对应
    assert(channel->fd == fd);

    // 根据事件类型调用对应的回调函数
    if (event & ReadAble && channel->readCallBack != NULL)
    {
        channel->readCallBack(channel->arg);
    }
    if (event & WriteAble && channel->writeCallBack != NULL)
    {
        channel->writeCallBack(channel->arg);
    }

    return 0;
}

int EventLoopAddTask(struct EventLoop *loop, struct Channel *channel, int type)
{
    pthread_mutex_lock(&loop->mutexForList); // 为任务list加个互斥锁
    struct Task *task = (struct Task *)malloc(sizeof(struct Task));
    task->type = type;
    task->channel = channel;
    task->next = NULL;
    // 添加任务，有可能list为空，也有可能不为空
    if (loop->head == NULL)
    {
        // 链表为空
        loop->head = loop->tail = task;
    }
    else
    {
        // 链表不为空
        loop->tail->next = task;
        loop->tail = task;
    }
    pthread_mutex_unlock(&loop->mutexForList);

    // 处理节点
    /*
     * 细节:
     *   1. 对于链表节点的添加: 可能是当前线程也可能是其他线程(主线程)
     *       1). 修改fd的事件, 当前子线程发起, 当前子线程处理
     *       2). 添加新的fd, 添加任务节点的操作是由主线程发起的
     *   2. 不能让主线程处理任务队列, 需要由当前的子线程取处理
     */

    if (loop->threadID == pthread_self())
    {
        // 当前子线程(基于子线程的角度分析)
        EventLoopListProcess(loop);
    }
    else
    {
        // 主线程 -- 告诉子线程处理任务队列中的任务
        // 1. 子线程在工作 2. 子线程被阻塞了:select, poll, epoll
        writeMsgLocal(loop);
    }

    return 0;
}

int EventLoopListProcess(struct EventLoop *loop)
{
    pthread_mutex_lock(&loop->mutexForList);
    struct Task *task = loop->head;
    while (task != NULL)
    {
        struct Channel *channel = task->channel;
        if (task->type == ADD)
        {
            // 添加Channel的任务
            EventLoopChannelAdd(channel, loop);
        }
        else if (task->type == DELETE)
        {
            // 删除Channel的任务
            EventLoopChannelRemove(channel, loop);
        }
        else if (task->type == MODIFY)
        {
            // 修改Channel的任务
            EventLoopChannelModify(channel, loop);
        }
        struct Task *temp = task;
        task = task->next;
        free(temp);
    }
    loop->head = loop->tail = NULL;
    pthread_mutex_unlock(&loop->mutexForList);

    return 0;
}

int EventLoopChannelAdd(struct Channel *channel, struct EventLoop *loop)
{
    int fd = channel->fd;
    struct ChannelMap *map = loop->channelMap;
    if (fd >= map->size)
    {
        int res = reshapeChannelMap(map, fd);
        if (res == -1)
        {
            perror("EventLoopChannelAdd Error!");
            exit(0);
        }
    }
    // 找到要插入的位置，确定是否有内容
    if (map->list[fd] != NULL)
    {
        // 当前位置有内容
        printf("EventLoopChannelAdd error! 当前位置有内容\n");
        return -1;
    }
    else
    {
        // 当前位置没有内容
        map->list[fd] = channel;
        loop->dispatcher->add(channel, loop);
    }
    return 0;
}

int EventLoopChannelRemove(struct Channel *channel, struct EventLoop *loop)
{
    int fd = channel->fd;
    struct ChannelMap *map = loop->channelMap;
    if (fd >= map->size) // 文件描述符不在map当中
    {
        return -1;
    }
    loop->dispatcher->remove(channel, loop);
    return 0;
}

int EventLoopChannelModify(struct Channel *channel, struct EventLoop *loop)
{
    int fd = channel->fd;
    struct ChannelMap *map = loop->channelMap;
    if (loop->channelMap->list[channel->fd] == NULL)
    {
        printf("channelmap当中不存在该channel\n");
        return -1;
    }
    loop->dispatcher->modify(channel, loop);

    return 0;
}

int destroy(struct Channel *channel, struct EventLoop *loop)
{
    // 将该channel从channelmap当中除去
    loop->channelMap->list[channel->fd] = NULL;
    close(channel->fd);
    free(channel);
    return 0;
}
