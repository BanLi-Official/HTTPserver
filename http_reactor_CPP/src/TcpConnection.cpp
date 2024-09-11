#include "TcpConnection.h"
#include <stdlib.h>
#include <stdio.h>
#include "Log.h"

// #define MSG_SENG_AUTO


int TcpConnection::TcpConnectionDestroy(void *arg)
{
    TcpConnection* conn = static_cast<TcpConnection*>(arg);
    if (conn != nullptr)
    {
        delete conn;
    }
    return 0;
}


//接收客户端发来的数据，存入读缓冲区
int TcpConnection::readCallBackFunc(void *arg)
{
    struct TcpConnection* tcpConn=(struct TcpConnection*)arg;
    //读数据
    int count=tcpConn->readBuffer->writeSocketMsgIntoBuffer(tcpConn->getChannel()->getFD());

    Debug("接收到的http请求数据: %s", tcpConn->readBuffer->getReadPosition());

    //解析数据，做出读到了数据后的反应
    if(count>0)
    {
        //接到了来自http的请求
        int socket=tcpConn->getChannel()->getFD();
#ifdef MSG_SENG_AUTO
        //setWriteable(tcpConn->channel,true);
        tcpConn->channel->setWriteable(true);
        //EventLoopAddTask(tcpConn->eventloop,tcpConn->channel,MODIFY);
        tcpConn->eventloop->AddTask(tcpConn->channel,Elemtype::DELETE);
#endif
        
        bool flag=tcpConn->request->parseHTTPRequest(tcpConn->readBuffer,tcpConn->response,tcpConn->writeBuffer,socket);
        Debug("数据解析结束.....");
        //printf("request.method=%s,  request.URL=%s,   request.httpVersion=%s,    headKeyNums=%d,   parseState=%d\n",tcpConn->request->method,tcpConn->request->URL,
                                                    //tcpConn->request->httpVersion,tcpConn->request->headKeyNum,tcpConn->request->parseState);
        if(!flag)  //解析错误
        {
            char *error="HTTP/1.1 400 BadRequest\r\n\r\n";
            tcpConn->writeBuffer->writeStringIntoBuffer(error);
        }
    }

    //断开连接
#ifndef MSG_SENG_AUTO
    tcpConn->eventloop->AddTask(tcpConn->channel,Elemtype::DELETE);
#endif
 
    return 0;
}


//在数据写入缓冲区之后发送数据到客户端
int TcpConnection::writeCallBackFunc(void *arg)
{
    Debug("开始发送数据了(基于写事件发送)....");
    struct TcpConnection* tcpConn=(struct TcpConnection*)arg;
    //发送数据
    int count=tcpConn->writeBuffer->bufferSendData(tcpConn->channel->getFD());
    if(count>0)
    {
        //判断数据是否全部发送出去了
        if(tcpConn->writeBuffer->getReadableSize()==0)
        {
            //不再检测写事件，修改channel中的保存的事件
            tcpConn->channel->setWriteable(false);
            //修改dispatch检测的集合，添加任务结点
            tcpConn->eventloop->AddTask(tcpConn->channel,Elemtype::MODIFY);
            //删除这个结点
            tcpConn->eventloop->AddTask(tcpConn->channel,Elemtype::DELETE);
        }
    }

    return 0;

}


TcpConnection::TcpConnection(int fd, EventLoop *eventloop)
{
    name="TcpConnection-"+to_string(fd);
    //此时读回调函数readCallBackFunc还未实现，具体该函数是用来接收客户端发来的http请求
    readBuffer=new buffer(10240);
    writeBuffer=new buffer(10240);
    eventloop = eventloop;
    request = new httpRequest();
    response = new httpResponse();


    channel=new Channel(fd,FDevent::ReadAble,readCallBackFunc,writeCallBackFunc,TcpConnectionDestroy,this);

    eventloop->AddTask(channel,Elemtype::ADD);
    Debug("和客户端建立连接, threadName: %s, threadID:%ld, connName: %s",
        eventloop->getThreadName(), eventloop->getThreadID(), name);

}

TcpConnection::~TcpConnection()
{
   if(readBuffer && readBuffer->getReadableSize()==0 &&
        writeBuffer && writeBuffer->getReadableSize()==0)
        {
            delete readBuffer;
            delete writeBuffer;
            delete request;
            delete response;
            eventloop->destroyChannel(channel);
        } 
    Debug("连接断开, 释放资源, gameover, connName: %s", name);
}
