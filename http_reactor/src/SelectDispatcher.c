#include "Dispatcher.h"
#include <sys/select.h>
#include <stdlib.h>
#include <stdio.h>

struct selectDispatcherData
{
    int maxFd;
    fd_set *readfds;
    fd_set *writefds;
};

// 初始化select、poll、epoll所需的数据块
static void * selectInit();
// 添加注册事件
static int selectAdd(struct Channel *channel, struct EventLoop *eventloop); // struct EventLoop * eventloop向外取DispatcherData
// 移除注册事件
static int selectRemove(struct Channel *channel, struct EventLoop *eventloop);
// 修改注册事件
static int selectModify(struct Channel *channel, struct EventLoop *eventloop);
// 事件监测
static int selectDispatch(struct EventLoop *eventloop, int Timeout); // 以秒为单位
// 清除内存（析构）
static int selectClear(struct EventLoop *eventloop);

struct Dispatcher selectDispatcher = {
                                         selectInit,
                                         selectAdd,
                                         selectRemove,
                                         selectModify,
                                         selectDispatch,
                                         selectClear
};
                                         
// 初始化select、poll、epoll所需的数据块
static void * selectInit()
{
    struct selectDispatcherData *data = (struct selectDispatcherData *)malloc(sizeof(struct selectDispatcherData));
    if (data == NULL)
    {
        printf("selectInit Error! data == NULL\n");
        return NULL;
    }
    data->readfds = (fd_set *)malloc(sizeof(fd_set));
    if (data->readfds == NULL)
    {
        printf("selectInit Error! data->readfds == NULL\n");
        free(data);
        return NULL;
    }
    FD_ZERO(data->readfds);
    data->writefds = (fd_set *)malloc(sizeof(fd_set));
    if (data->writefds == NULL)
    {
        printf("selectInit Error! data->writefds == NULL\n");
        free(data->readfds);
        free(data);
        return NULL;
    }
    FD_ZERO(data->writefds);
    data->maxFd = 0;
    return data;
}
// 添加注册事件
static int selectAdd(struct Channel *channel, struct EventLoop *eventloop)
{
    if (channel == NULL || eventloop == NULL)
    {
        printf("selectAdd Error! channel == NULL || eventloop == NULL\n");
        return -1;
    }
    struct selectDispatcherData *data = (struct selectDispatcherData *)eventloop->DispatcherData;
    if (channel->event & ReadAble)
    {
        FD_SET(channel->fd, data->readfds);
    }
    if (channel->event & WriteAble)
    {
        FD_SET(channel->fd, data->writefds);
    }
    if(data->maxFd < channel->fd)
    {
        data->maxFd=channel->fd;
    }
    return 1;
}
// 移除注册事件
static int selectRemove(struct Channel *channel, struct EventLoop *eventloop)
{
    if (channel == NULL || eventloop == NULL)
    {
        printf("selectRemove Error! channel == NULL || eventloop == NULL\n");
        return -1;
    }
    struct selectDispatcherData *data = (struct selectDispatcherData *)eventloop->DispatcherData;

    if (channel->event & ReadAble)
    {
        if (FD_ISSET(channel->fd, data->readfds) == 0)
        {
            printf("selectRemove Error! channel is not at readfds!\n");
            return 0;
        }
        FD_CLR(channel->fd, data->readfds);
    }
    if (channel->event & WriteAble)
    {
        if (FD_ISSET(channel->fd, data->writefds) == 0)
        {
            printf("selectRemove Error! channel is not at writefds!\n");
            return 0;
        }
        FD_CLR(channel->fd, data->writefds);
    }

    return 1;
}
// 修改注册事件
static int selectModify(struct Channel *channel, struct EventLoop *eventloop)
{
    if (channel == NULL || eventloop == NULL)
    {
        printf("selectModify Error! channel == NULL || eventloop == NULL\n");
        return -1;
    }
    struct selectDispatcherData *data = (struct selectDispatcherData *)eventloop->DispatcherData;

    if(channel->event & ReadAble && (FD_ISSET(channel->fd,data->readfds)==0))  //可读，但是不在可读的组当中
    {
        FD_SET(channel->fd , data ->readfds);
        if(data->maxFd < channel->fd)
        {
            data->maxFd=channel->fd;
        }
    }
    if(~(channel->event & ReadAble == 0x04) && (FD_ISSET(channel->fd,data->readfds)==1))  //不可读，但是在可读的组当中
    {
        FD_CLR(channel->fd , data ->readfds);
    }
    if(channel->event & WriteAble && (FD_ISSET(channel->fd,data->writefds)==0))  //可写，但是不在可写的组当中
    {
        FD_SET(channel->fd , data ->writefds);
        if(data->maxFd < channel->fd)
        {
            data->maxFd=channel->fd;
        }
    }
    if(~(channel->event & WriteAble == 0x02) && (FD_ISSET(channel->fd,data->writefds)==1))  //不可读，但是在可读的组当中
    {
        FD_CLR(channel->fd , data ->writefds);
    }

    return 1;
}
// 事件监测
static int selectDispatch(struct EventLoop *eventloop, int Timeout)
{
    if (eventloop == NULL)
    {
        printf("selectDispatch Error! eventloop == NULL\n");
        return -1;
    }
    struct selectDispatcherData *data = (struct selectDispatcherData *)eventloop->DispatcherData;

    fd_set *readTemp;
    fd_set *writeTemp;
    readTemp = data->readfds;
    writeTemp = data->writefds;

    int num = 0;
    struct timeval timeout;
    timeout.tv_sec=Timeout;
    timeout.tv_usec = 0;
    num = select(data->maxFd+1 , readTemp , writeTemp , NULL , &timeout);

    for(int i=0 ; i < data->maxFd+1 ; i++)
    {
        if(FD_ISSET(i , readTemp)) //读数组当中有内容
        {

        }
        if(FD_ISSET(i , writeTemp)) //写数组当中有内容
        {

        }
    }
    return 1;
    
}
// 清除内存（析构）
static int selectClear(struct EventLoop *eventloop)
{
    struct selectDispatcherData *data = (struct selectDispatcherData *)eventloop->DispatcherData;
    free(data->readfds);
    data->readfds =NULL;
    free(data->writefds);
    data->writefds =NULL;
    free(data);
    return 1;
}