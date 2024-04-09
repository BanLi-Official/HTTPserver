#include "TcpConnection.h"
#include <stdlib.h>
#include <stdio.h>


//接收客户端发来的数据，存入读缓冲区
int readCallBackFunc(void *arg)
{
    struct TcpConnection* tcpConn=(struct TcpConnection*)arg;
    //读数据
    writeSocketMsgIntoBuffer(tcpConn->readBuffer,tcpConn->channel->fd);


    //解析数据，做出读到了数据后的反应



    
    return 0;
}

struct TcpConnection *TcpConnectionInit(int fd,struct EventLoop *eventloop)
{
    struct TcpConnection* tcpConn=(struct TcpConnection *)malloc(sizeof(struct TcpConnection));
    sprintf(tcpConn->name,"TcpConnection-%d",fd);
    //此时读回调函数readCallBackFunc还未实现，具体该函数是用来接收客户端发来的http请求
    tcpConn->channel=channelInit(fd,ReadAble,readCallBackFunc,NULL,NULL,tcpConn);
    tcpConn->readBuffer=bufferInit(10240);
    tcpConn->writeBuffer=bufferInit(10240);
    tcpConn->eventloop = eventloop;
    return tcpConn;
}
