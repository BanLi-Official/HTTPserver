#include "Dispatcher.h"
#include <sys/epoll.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include "EpollDispatcher.h"




EpollDispatcher::EpollDispatcher(EventLoop *eventLoop) : Dispatcher(eventLoop)
{
    int epfd = epoll_create(1);
    if (epfd == -1)
    {
        printf("EpollInit error! epfd is -1!\n");
    }
    m_epfd = epfd;
    m_events = (struct epoll_event *)calloc(Max, sizeof(struct epoll_event));
    if (m_events == NULL)
    {
        printf("EpollInit error! data->events is NULL!\n");
    }
    m_name="Epoll";

}

EpollDispatcher::~EpollDispatcher()
{
    close(m_epfd);
    delete []m_events;
}

int EpollDispatcher::add()
{
    if (m_channel == NULL)
    {
        printf("Epolladd error ! channel == NULL\n");
    }
    //包装事件类型
    struct epoll_event event ;
    event.data.fd = m_channel->getFD();
    //设置检测读写事件
    int ev=0;
    if(m_channel->getEvent() & static_cast<int>(FDevent::WriteAble))
    {
        ev |= EPOLLOUT;
    }
    if(m_channel->getEvent() & static_cast<int>(FDevent::ReadAble))
    {
        ev |= EPOLLIN;
    }
    event.events=ev;

    //将文件描述符挂载到红黑树上
    int res=epoll_ctl(m_epfd , EPOLL_CTL_ADD , m_channel->getFD() , &event);
    if(res == -1)
    {
        printf("Epolladd error ! epoll_ctl error\n");
        return -1;
    }
    return 0;

}

int EpollDispatcher::remove()
{
    if (m_channel == NULL)
    {
        printf("Epollremove error ! channel == NULL\n");
    }


    int res = epoll_ctl(m_epfd , EPOLL_CTL_DEL ,m_channel->getFD(),NULL);
    if(res == -1)
    {
        printf("Epollremove error ! epoll_ctl error\n");
        return -1;
    }

    //清除channel中对应的data数据
    m_channel->destroyCallBack(const_cast<void*>(m_channel->getArg()));
     
    return 0;
}

int EpollDispatcher::modify()
{
    if (m_channel == NULL)
    {
        printf("Epollremove error ! channel == NULL\n");
    }
    //包装事件类型
    struct epoll_event event ;
    event.data.fd = m_channel->getFD();
    //设置检测读写事件
    int ev=0;
    if(m_channel->getEvent() & static_cast<int>(FDevent::WriteAble))
    {
        ev |= EPOLLOUT;
    }
    if(m_channel->getEvent() & static_cast<int>(FDevent::ReadAble))
    {
        ev |= EPOLLIN;
    }
    event.events=ev;

    int res = epoll_ctl(m_epfd,EPOLL_CTL_MOD,m_channel->getFD(),&event);
    if(res == -1)
    {
        printf("Epollmodify error ! epoll_ctl error\n");
        return -1;
    }
    return 0;

}

int EpollDispatcher::dispatch(int Timeout)
{

    int epfd=m_epfd;
    struct epoll_event *events=m_events;
    int num=epoll_wait(epfd,events,Max,Timeout * 1000);
    for(int i=0;i<num;i++)
    {
        //处理每一个检测到的文件标识符
        int fd =events[i].data.fd;
        int event = events[i].events;
        
        if(event & EPOLLERR || event & EPOLLHUP)
        {
            //用户断开连接
            //struct Channel * channel = eventloop->channelMap->list[fd];
            //assert(channel->fd == fd);
            //Epollremove(channel,eventloop);
            continue;
        }
        if(event & EPOLLIN)
        {
            //读事件
            m_eventloop->activateFD(fd,(int)FDevent::ReadAble);
        }
        if(event & EPOLLOUT)
        {
            //写事件
            m_eventloop->activateFD(fd,(int)FDevent::WriteAble);
        }

    }
    return 0;
}
