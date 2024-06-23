#include "Dispatcher.h"
#include <sys/poll.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define Max 500

struct PollDispatcherData
{
    struct pollfd *fds; // 文件描述符队列
};

// 初始化select、poll、epoll所需的数据块
static void *PollInit();
// 添加注册事件
static int PollAdd(struct Channel *channel, struct EventLoop *eventloop); // struct EventLoop * eventloop向外取DispatcherData
// 移除注册事件
static int PollRemove(struct Channel *channel, struct EventLoop *eventloop);
// 修改注册事件
static int PollModify(struct Channel *channel, struct EventLoop *eventloop);
// 事件监测
static int PollDispatche(struct EventLoop *eventloop, int Timeout); // 以秒为单位
// 清除内存（析构）
static int PollClear(struct EventLoop *eventloop);

struct Dispatcher pollDispatcher = {
    PollInit,
    PollAdd,
    PollRemove,
    PollModify,
    PollDispatche,
    PollClear};

// 初始化select、poll、epoll所需的数据块
static void *PollInit()
{
    struct PollDispatcherData *data = (struct PollDispatcherData *)malloc(sizeof(struct PollDispatcherData));
    data->fds = (struct pollfd *)malloc(sizeof(struct pollfd) * Max);
    if (data->fds == NULL)
    {
        printf("PollInit Error ! data->fds ==NULL\n");
        return NULL;
    }
    for (int i = 0; i < Max; i++) // 将所有文件描述符先初始化为-1
    {
        data->fds[i].fd = -1;
    }
    return data;
}
// 添加注册事件
static int PollAdd(struct Channel *channel, struct EventLoop *eventloop)
{
    if (channel == NULL)
    {
        printf("PollAdd Error ! channel == NULL\n");
        return -1;
    }
    // 先将eventloop的data提出来
    struct PollDispatcherData *data = (struct PollDispatcherData *)eventloop->DispatcherData;
    // 遍历整个文件描述符数组，寻找没有被赋值的内容
    for (int i = 0; i < Max; i++)
    {
        if (data->fds[i].fd != -1)
        {
            continue;
        }
        data->fds[i].fd = channel->fd;
        int ev = 0;
        if (channel->event & WriteAble)
        {
            ev |= POLLOUT;
        }
        if (channel->event & ReadAble)
        {
            ev |= POLLIN;
        }
        data->fds[i].events = ev;
        return 0;
    }
    return 1;
}
// 移除注册事件
static int PollRemove(struct Channel *channel, struct EventLoop *eventloop)
{
    if (channel == NULL)
    {
        printf("PollRemove Error ! channel == NULL\n");
        return -1;
    }
    // 先将eventloop的data提出来
    struct PollDispatcherData *data = (struct PollDispatcherData *)eventloop->DispatcherData;
    // 遍历整个文件描述符数组，寻找指定内容，并将其删除
    for (int i = 0; i < Max; i++)
    {
        if (data->fds[i].fd == channel->fd)
        {
            data->fds[i].fd = -1;
            data->fds[i].events = 0;
            data->fds[i].revents = 0;
            return 0;
        }
    }
    //通过channel释放对应的tcpConection资源
    channel->destroyCallBack(channel->arg);

    return -1;
}
// 修改注册事件
static int PollModify(struct Channel *channel, struct EventLoop *eventloop)
{
    if (channel == NULL)
    {
        printf("PollRemove Error ! channel == NULL\n");
        return -1;
    }
    // 先将eventloop的data提出来
    struct PollDispatcherData *data = (struct PollDispatcherData *)eventloop->DispatcherData;
    // 遍历整个文件描述符数组，寻找指定内容，并将其删除
    for (int i = 0; i < Max; i++)
    {
        if (data->fds[i].fd == channel->fd)
        {
            int ev = 0;
            if (channel->event & WriteAble)
            {
                ev |= POLLOUT;
            }
            if (channel->event & ReadAble)
            {
                ev |= POLLIN;
            }
            data->fds[i].events = ev;
            return 0;
        }
    }
    return -1;
}
// 事件监测
static int PollDispatche(struct EventLoop *eventloop, int Timeout)
{
    struct PollDispatcherData * data = (struct PollDispatcherData *)eventloop->DispatcherData;
    struct pollfd *fds= data->fds;
    int num = poll(fds,Max+1,Timeout*1000);
    if(num == -1)
    {
        printf("PollDispatche error ! num == -1\n");
    }
    for (int i = 0; i < Max; i++)
    {
        if ( fds[i].fd!=-1 )
        {
            if(fds[i].revents & POLLERR || fds[i].revents & POLLHUP)
            {
                //客户端断开,remove
                struct Channel * channel = eventloop->channelMap->list[fds[i].fd];
                assert(channel->fd == fds[i].fd);
                PollRemove(channel,eventloop);
            }
            if (fds[i].revents & POLLIN)
            {
                //读事件
                activateFD(eventloop,fds[i].fd,ReadAble);
            }
            if(fds[i].revents & POLLOUT)
            {
                //写事件
                activateFD(eventloop,fds[i].fd,WriteAble);
            } 
        }
        
    }

    return 0;
    

}
// 清除内存（析构）
static int PollClear(struct EventLoop *eventloop)
{
    struct PollDispatcherData * data = (struct PollDispatcherData *)eventloop->DispatcherData;
    struct pollfd *fds= data->fds;
    free(fds);   //释放事件组
    data->fds = NULL;   //防止成为野指针
    free(data);  //释放data数据
    eventloop->DispatcherData=NULL; //防止成为野指针
    return 0;
}