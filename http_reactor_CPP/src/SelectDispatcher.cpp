#include "SelectDispatcher.h"
#include <sys/select.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


// 初始化select、poll、epoll所需的数据块
SelectDispatcher::SelectDispatcher(EventLoop *eventLoop) : Dispatcher(eventLoop)
{

    readfds = (fd_set *)malloc(sizeof(fd_set));
    if (readfds == NULL)
    {
        printf("selectInit Error! data->readfds == NULL\n");
        return ;
    }
    FD_ZERO(readfds);
    writefds = (fd_set *)malloc(sizeof(fd_set));
    if (writefds == NULL)
    {
        printf("selectInit Error! data->writefds == NULL\n");
        free(readfds);
        return ;
    }
    FD_ZERO(writefds);
    maxFd = 0;
    m_name="select";
    return ;
}


SelectDispatcher::~SelectDispatcher()
{
    delete readfds;
    delete writefds;
    return ;
}

// 添加注册事件
int SelectDispatcher::add()
{
    if (m_channel == NULL || m_eventloop == NULL)
    {
        printf("selectAdd Error! channel == NULL || eventloop == NULL\n");
        return -1;
    }

    if (m_channel->getEvent() & (int)FDevent::ReadAble)
    {
        FD_SET(m_channel->getFD(), readfds);
    }
    if (m_channel->getEvent() & (int)FDevent::WriteAble)
    {
        FD_SET(m_channel->getFD(), writefds);
    }
    if(maxFd < m_channel->getFD())
    {
        maxFd=m_channel->getFD();
    }
    return 1;
}

// 移除注册事件
int SelectDispatcher::remove()
{
    if (m_channel == NULL || m_eventloop == NULL)
    {
        printf("selectRemove Error! channel == NULL || eventloop == NULL\n");
        return -1;
    }


    if (m_channel->getEvent() & (int)FDevent::ReadAble)
    {
        if (FD_ISSET(m_channel->getFD(), readfds) == 0)
        {
            printf("selectRemove Error! channel is not at readfds!\n");
            return 0;
        }
        FD_CLR(m_channel->getFD(), readfds);
    }
    if (m_channel->getEvent() & (int)FDevent::WriteAble)
    {
        if (FD_ISSET(m_channel->getFD(), writefds) == 0)
        {
            printf("selectRemove Error! channel is not at writefds!\n");
            return 0;
        }
        FD_CLR(m_channel->getFD(), writefds);
    }

    //通过channel释放对应的tcpConection资源
    m_channel->destroyCallBack(const_cast<void*>(m_channel->getArg()));

    return 1;
}

// 修改注册事件
int SelectDispatcher::modify()
{
    if (m_channel == NULL || m_eventloop == NULL)
    {
        printf("selectModify Error! channel == NULL || eventloop == NULL\n");
        return -1;
    }

    if(m_channel->getEvent() & (int)FDevent::ReadAble && (FD_ISSET(m_channel->getFD(),readfds)==0))  //可读，但是不在可读的组当中
    {
        FD_SET(m_channel->getFD(),readfds);
        if(maxFd < m_channel->getFD())
        {
            maxFd=m_channel->getFD();
        }
    }
    if(~(m_channel->getEvent() & (int)FDevent::ReadAble == 0x04) && (FD_ISSET(m_channel->getFD(),readfds)==1))  //不可读，但是在可读的组当中
    {
        FD_CLR(m_channel->getFD(),readfds);
    }
    if(m_channel->getEvent() & (int)FDevent::WriteAble && (FD_ISSET(m_channel->getFD(),writefds)==0))  //可写，但是不在可写的组当中
    {
        FD_SET(m_channel->getFD(),writefds);
        if(maxFd < m_channel->getFD())
        {
            maxFd=m_channel->getFD();
        }
    }
    if(~(m_channel->getEvent() & (int)FDevent::WriteAble == 0x02) && (FD_ISSET(m_channel->getFD(),writefds)==1))  //不可读，但是在可读的组当中
    {
        FD_CLR(m_channel->getFD(),writefds);
    }

    return 1;
}

// 事件监测
int SelectDispatcher::dispatch(int Timeout)
{
     if (m_eventloop == NULL)
    {
        printf("selectDispatch Error! eventloop == NULL\n");
        return -1;
    }


    fd_set *readTemp;
    fd_set *writeTemp;
    readTemp = readfds;
    writeTemp = writefds;

    int num = 0;
    struct timeval timeout;
    timeout.tv_sec=Timeout;
    timeout.tv_usec = 0;
    num = select(maxFd+1 , readTemp , writeTemp , NULL , &timeout);

    for(int i=0 ; i < maxFd+1 ; i++)
    {
        if(FD_ISSET(i , readTemp)) //读数组当中有内容
        {
            activateFD(eventloop,i,ReadAble);
        }
        if(FD_ISSET(i , writeTemp)) //写数组当中有内容
        {
            activateFD(eventloop,i,WriteAble);
        }

    }
    return 1;
}
