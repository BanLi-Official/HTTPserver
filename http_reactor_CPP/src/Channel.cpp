#include "Channel.h"
#include <stdlib.h>


Channel::Channel(int fd, int event, handleFunc readFunc, handleFunc writeFunc,handleFunc destroyCallBack, void *arg)
{
    m_fd = fd;
    m_event=event;
    readCallBack=readFunc;
    writeCallBack=writeFunc;
    destroyCallBack=destroyCallBack;
    m_arg=arg;
}



int Channel::setWriteable(bool flag)
{
    if(flag)
    {
        m_event |=static_cast<int>(FDevent::WriteAble) ;
    }
    else
    {
        m_event = m_event & ~static_cast<int>(FDevent::WriteAble) ;
    }
    return 0;
}

bool Channel::checkWriteable()
{
    return m_event & static_cast<int>(FDevent::WriteAble) ;
}
