#include "Dispatcher.h"
#include <sys/epoll.h>
#include <stdlib.h>
#include <stdio.h>

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
}

static int Epollremove(struct Channel *channel, struct EventLoop *eventloop)
{
}

static int Epollmodify(struct Channel *channel, struct EventLoop *eventloop)
{
}

static int Epolldispatch(struct EventLoop *eventloop, int Timeout)
{
}

static int Epollclear(struct EventLoop *eventloop)
{
}
