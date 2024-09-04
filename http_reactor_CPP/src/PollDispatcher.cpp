#include "PollDispatcher.h"
#include <sys/poll.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>







PollDispatcher::PollDispatcher(EventLoop *eventLoop) : Dispatcher(eventLoop)
{
    fds = new struct pollfd[MaxNode];
    if (fds == NULL)
    {
        printf("PollInit Error ! data->fds ==NULL\n");
        return ;
    }
    for (int i = 0; i < MaxNode; i++) // 将所有文件描述符先初始化为-1
    {
        fds[i].fd = -1;
    }
    return ;
}

PollDispatcher::~PollDispatcher()
{
    delete []fds;
}

// 添加注册事件
int PollDispatcher::add()
{
    if (m_channel == NULL)
    {
        printf("PollAdd Error ! channel == NULL\n");
        return -1;
    }

    // 遍历整个文件描述符数组，寻找没有被赋值的内容
    for (int i = 0; i < MaxNode; i++)
    {
        if (fds[i].fd != -1)
        {
            continue;
        }
        fds[i].fd = m_channel->getFD();
        int ev = 0;
        if (m_channel->getEvent() & static_cast<int>(FDevent::WriteAble))
        {
            ev |= POLLOUT;
        }
        if (m_channel->getEvent() & static_cast<int>(FDevent::ReadAble))
        {
            ev |= POLLIN;
        }
        fds[i].events = ev;
        return 0;
    }
    return 1;
}

// 移除注册事件
int PollDispatcher::remove()
{
    if (m_channel == NULL)
    {
        printf("PollRemove Error ! channel == NULL\n");
        return -1;
    }

    // 遍历整个文件描述符数组，寻找指定内容，并将其删除
    for (int i = 0; i < MaxNode; i++)
    {
        if (fds[i].fd == m_channel->getFD())
        {
            fds[i].fd = -1;
            fds[i].events = 0;
            fds[i].revents = 0;
            return 0;
        }
    }
    //通过channel释放对应的tcpConection资源
    m_channel->destroyCallBack(const_cast<void*>(m_channel->getArg()));

    return -1;
}

// 修改注册事件
int PollDispatcher::modify()
{
    if (m_channel == NULL)
    {
        printf("PollRemove Error ! channel == NULL\n");
        return -1;
    }

    // 遍历整个文件描述符数组，寻找指定内容，并将其删除
    for (int i = 0; i < MaxNode; i++)
    {
        if (fds[i].fd == m_channel->getFD())
        {
            int ev = 0;
            if (m_channel->getEvent() & static_cast<int>(FDevent::WriteAble))
            {
                ev |= POLLOUT;
            }
            if (m_channel->getEvent() & static_cast<int>(FDevent::ReadAble))
            {
                ev |= POLLIN;
            }
            fds[i].events = ev;
            return 0;
        }
    }
    return -1;
}

int PollDispatcher::dispatch(int Timeout)
{

    struct pollfd *fds= fds;
    int num = poll(fds,MaxNode+1,Timeout*1000);
    if(num == -1)
    {
        printf("PollDispatche error ! num == -1\n");
    }
    for (int i = 0; i < MaxNode; i++)
    {
        if ( fds[i].fd!=-1 )
        {
            if(fds[i].revents & POLLERR || fds[i].revents & POLLHUP)
            {
                //客户端断开,remove
                //struct Channel * channel = m_eventloop->channelMap->list[fds[i].fd];
                //assert(channel->fd == fds[i].fd);
                //PollRemove(channel,eventloop);
                remove();
            }
            if (fds[i].revents & POLLIN)
            {
                //读事件
                m_eventloop->activateFD(fds[i].fd,(int)FDevent::ReadAble);
            }
            if(fds[i].revents & POLLOUT)
            {
                //写事件
                m_eventloop->activateFD(fds[i].fd,(int)FDevent::WriteAble);
            } 
        }
        
    }

    return 0;
}
