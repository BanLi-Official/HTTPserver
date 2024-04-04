#pragma once
#include "EventLoop.h"
#include "Channel.h"
#include "Buffer.h"


struct TcpConnection
{
    char name[24];
    struct Channel * channel;
    struct buffer* readBuffer;
    struct buffer* writeBuffer;
    struct EventLoop* eventloop;
};

struct TcpConnection* TcpConnectionInit(int fd,struct EventLoop* eventloop);