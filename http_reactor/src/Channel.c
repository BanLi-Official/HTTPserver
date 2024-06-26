#include "Channel.h"
#include <stdlib.h>

struct Channel *channelInit(int fd, int event, handleFunc readFunc, handleFunc writeFunc,handleFunc destroyCallBack, void *arg)
{
    struct Channel *channel = (struct Channel *)malloc(sizeof(struct Channel));
    channel->fd = fd;
    channel->event=event;
    channel->readCallBack=readFunc;
    channel->writeCallBack=writeFunc;
    channel->destroyCallBack=destroyCallBack;
    channel->arg=arg;
    return channel;
}

int setWriteable(struct Channel *channel, bool flag)
{
    if(flag)
    {
        channel->event |= WriteAble;
    }
    else
    {
        channel->event = channel->event & ~WriteAble;
    }
    return 0;
}

bool checkWriteable(struct Channel *channel)
{
    return channel->event & WriteAble;
}
