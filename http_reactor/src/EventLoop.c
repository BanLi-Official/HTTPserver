#include "EventLoop.h"
#include "stdbool.h"
#include "stdlib.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>

struct EventLoop *EventLoopInit()
{
    return EventLoopInitEX(NULL);
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
    }
    else
    {
        // 主线程 -- 告诉子线程处理任务队列中的任务
        // 1. 子线程在工作 2. 子线程被阻塞了:select, poll, epoll
    }

    return 0;
}
