#include "TcpConnection.h"
#include <stdlib.h>
#include <stdio.h>

struct TcpConnection *TcpConnectionInit(int fd,struct EventLoop *eventloop)
{
    struct TcpConnection* tcpConn=(struct TcpConnection *)malloc(sizeof(struct TcpConnection));
    sprintf(tcpConn->name,"TcpConnection-%d",fd);
    //此时读回调函数readCallBackFunc还未实现，具体该函数是用来接收客户端发来的http请求
    tcpConn->channel=channelInit(fd,ReadAble,NULL,NULL,NULL,NULL);
    tcpConn->readBuffer=bufferInit(10240);
    tcpConn->writeBuffer=bufferInit(10240);
    tcpConn->eventloop = eventloop;
    return tcpConn;
}
