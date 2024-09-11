#pragma once
#include "EventLoop.h"
#include "Channel.h"
#include "Buffer.h"
#include "HTTPResponse.h"
#include "HttpRequest.h"

class TcpConnection
{
public:
    TcpConnection(int fd,EventLoop* eventloop);
    ~TcpConnection();

    static int TcpConnectionDestroy(void *arg);
    static int writeCallBackFunc(void *arg);
    static int readCallBackFunc(void *arg);

    //获取私有数据
    inline Channel* getChannel(){return channel;}
private:
    string name;
    Channel * channel;
    buffer* readBuffer;
    buffer* writeBuffer;
    EventLoop* eventloop;

    //http协议
    httpRequest* request;
    httpResponse* response;

};

