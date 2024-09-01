#include "Dispatcher.h"

Dispatcher::Dispatcher(EventLoop* eventLoop)
{
    m_eventloop=eventLoop;
}

Dispatcher::~Dispatcher()
{
}

int Dispatcher::add()
{
    return 0;
}

int Dispatcher::remove()
{
    return 0;
}

int Dispatcher::modify()
{
    return 0;
}

int Dispatcher::dispatch(int Timeout)
{
    return 0;
}
