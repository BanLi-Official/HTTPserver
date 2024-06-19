#pragma once
#include "EventLoop.h"
#include "Channel.h"
#include "Buffer.h"
#include "HTTPResponse.h"
#include "HttpRequest.h"

struct TcpConnection
{
    char name[24];
    struct Channel * channel;
    struct buffer* readBuffer;
    struct buffer* writeBuffer;
    struct EventLoop* eventloop;

    //http协议
    struct httpRequest* request;
    struct httpResponse* response;

};

struct TcpConnection* TcpConnectionInit(int fd,struct EventLoop* eventloop);