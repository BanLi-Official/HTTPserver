#include "Dispatcher.h"
#include <sys/epoll.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>

#define Max 500

struct EpolldispatchData
{
    // 文件描述符
    int epfd;
    // 事件数组
    struct epoll_event *events;
};

// 声明要实现的函数  static将结构体类型的函数隐藏在当前文件中，防止其他文件直接调用和访问
// 初始化select、poll、epoll所需的数据块
static void *EpollInit();
// 添加注册事件
static int Epolladd(struct Channel *channel, struct EventLoop *eventloop);
// 移除注册事件
static int Epollremove(struct Channel *channel, struct EventLoop *eventloop);
// 修改注册事件
static int Epollmodify(struct Channel *channel, struct EventLoop *eventloop);
// 事件监测
static int Epolldispatch(struct EventLoop *eventloop, int Timeout); // 以秒为单位
// 清除内存（析构）
static int Epollclear(struct EventLoop *eventloop);

// 实现赋值EpollDispatcher，全局变量可以传到EventLoop当中
struct Dispatcher EpollDispatch = {
    EpollInit,
    Epolladd,
    Epollremove,
    Epollmodify,
    Epolldispatch,
    Epollclear
};

static void *EpollInit()
{
    // 申请data内存，并赋值给其中的变量
    struct EpolldispatchData *data = (struct EpolldispatchData *)malloc(sizeof(struct EpolldispatchData));
    if (data == NULL)
    {
        printf("EpollInit error! data is NULL!\n");
    }
    int epfd = epoll_create(1);
    if (epfd == -1)
    {
        printf("EpollInit error! epfd is -1!\n");
    }
    data->epfd = epfd;
    data->events = (struct epoll_event *)calloc(Max, sizeof(struct epoll_event));
    if (data->events == NULL)
    {
        printf("EpollInit error! data->events is NULL!\n");
    }
    return data;
}

static int Epolladd(struct Channel *channel, struct EventLoop *eventloop)
{
    if (channel == NULL)
    {
        printf("Epolladd error ! channel == NULL\n");
    }
    //包装事件类型
    struct epoll_event event ;
    event.data.fd = channel->fd;
    //设置检测读写事件
    int ev=0;
    if(channel->event & WriteAble)
    {
        ev |= EPOLLOUT;
    }
    if(channel->event & ReadAble)
    {
        ev |= EPOLLIN;
    }
    event.events=ev;

    //将文件描述符挂载到红黑树上
    int res=epoll_ctl(((struct EpolldispatchData *)eventloop->DispatcherData)->epfd , EPOLL_CTL_ADD , channel->fd , &event);
    if(res == -1)
    {
        printf("Epolladd error ! epoll_ctl error\n");
        return -1;
    }
    return 0;

    
}

static int Epollremove(struct Channel *channel, struct EventLoop *eventloop)
{
    if (channel == NULL)
    {
        printf("Epollremove error ! channel == NULL\n");
    }


    int res = epoll_ctl(((struct EpolldispatchData *)eventloop->DispatcherData)->epfd , EPOLL_CTL_DEL ,channel->fd,NULL);
    if(res == -1)
    {
        printf("Epollremove error ! epoll_ctl error\n");
        return -1;
    }

    //清除channel中对应的data数据
    channel->destroyCallBack(channel->arg);

    return 0;
     
    

}

static int Epollmodify(struct Channel *channel, struct EventLoop *eventloop)
{
    if (channel == NULL)
    {
        printf("Epollremove error ! channel == NULL\n");
    }
    //包装事件类型
    struct epoll_event event ;
    event.data.fd = channel->fd;
    //设置检测读写事件
    int ev=0;
    if(channel->event & WriteAble)
    {
        ev |= EPOLLOUT;
    }
    if(channel->event & ReadAble)
    {
        ev |= EPOLLIN;
    }
    event.events=ev;

    int res = epoll_ctl(((struct EpolldispatchData *)eventloop->DispatcherData)->epfd,EPOLL_CTL_MOD,channel->fd,&event);
    if(res == -1)
    {
        printf("Epollmodify error ! epoll_ctl error\n");
        return -1;
    }
    return 0;
}

static int Epolldispatch(struct EventLoop *eventloop, int Timeout)
{
    struct EpolldispatchData *dispatcherData=(struct EpolldispatchData *)eventloop->DispatcherData;
    int epfd=dispatcherData->epfd;
    struct epoll_event *events=(struct epoll_event *)dispatcherData->events;
    int num=epoll_wait(epfd,events,Max,Timeout * 1000);
    for(int i=0;i<num;i++)
    {
        //处理每一个检测到的文件标识符
        int fd =events[i].data.fd;
        int event = events[i].events;
        
        if(event & EPOLLERR || event & EPOLLHUP)
        {
            //用户断开连接
            struct Channel * channel = eventloop->channelMap->list[fd];
            assert(channel->fd == fd);
            Epollremove(channel,eventloop);
        }
        if(event & EPOLLIN)
        {
            //读事件
            activateFD(eventloop,fd,ReadAble);
        }
        if(event & EPOLLOUT)
        {
            //写事件
            activateFD(eventloop,fd,WriteAble);
        }

    }
    return 0;
}

static int Epollclear(struct EventLoop *eventloop)
{
    struct EpolldispatchData * epollData = eventloop->DispatcherData;
    struct epoll_event *events = epollData->events;
    free(events);  //先释放事件组 
    close(epollData->epfd);   //关闭epoll
    free(epollData); //释放data空间
    return 0;
}
