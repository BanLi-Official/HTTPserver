#include "TcpConnection.h"
#include <stdlib.h>
#include <stdio.h>
#include "Log.h"

// #define MSG_SENG_AUTO


//接收客户端发来的数据，存入读缓冲区
int readCallBackFunc(void *arg)
{
    struct TcpConnection* tcpConn=(struct TcpConnection*)arg;
    //读数据
    int count=writeSocketMsgIntoBuffer(tcpConn->readBuffer,tcpConn->channel->fd);

    Debug("接收到的http请求数据: %s ,count=%d", tcpConn->readBuffer->data + tcpConn->readBuffer->readPos,count);

    //解析数据，做出读到了数据后的反应
    if(count>0)
    {
        //接到了来自http的请求
        int socket=tcpConn->channel->fd;
#ifdef MSG_SENG_AUTO
        setWriteable(tcpConn->channel,true);
        EventLoopAddTask(tcpConn->eventloop,tcpConn->channel,MODIFY);
#endif
        
        bool flag=parseHTTPRequest(tcpConn->request,tcpConn->readBuffer,tcpConn->response,tcpConn->writeBuffer,socket);
        Debug("数据解析结束.....");
        printf("request.method=%s,  request.URL=%s,   request.httpVersion=%s,    headKeyNums=%d,   parseState=%d\n",tcpConn->request->method,tcpConn->request->URL,
                                                    tcpConn->request->httpVersion,tcpConn->request->headKeyNum,tcpConn->request->parseState);
        if(!flag)  //解析错误
        {
            char *error="HTTP/1.1 400 BadRequest\r\n\r\n";
            writeStringIntoBuffer(tcpConn->writeBuffer,error);
        }
    }

    //断开连接
#ifndef MSG_SENG_AUTO
    EventLoopAddTask(tcpConn->eventloop,tcpConn->channel,DELETE);
#endif
 
    return 0;
}


//在数据写入缓冲区之后发送数据到客户端
int writeCallBackFunc(void *arg)
{
    Debug("开始发送数据了(基于写事件发送)....");
    struct TcpConnection* tcpConn=(struct TcpConnection*)arg;
    //发送数据
    int count=bufferSendData(tcpConn->writeBuffer,tcpConn->channel->fd);
    if(count>0)
    {
        //判断数据是否全部发送出去了
        if(getReadableSize(tcpConn->writeBuffer)==0)
        {
            //不再检测写事件，修改channel中的保存的事件
            setWriteable(tcpConn->channel,false);
            //修改dispatch检测的集合，添加任务结点
            EventLoopAddTask(tcpConn->eventloop,tcpConn->channel,MODIFY);
            //删除这个结点
            EventLoopAddTask(tcpConn->eventloop,tcpConn->channel,DELETE);
        }
    }

    return 0;

}


int TcpConnectionDestroy(void *arg)
{
    struct TcpConnection* tcpConn = (struct TcpConnection*)arg;
    if(tcpConn)
    {
        if(tcpConn->readBuffer && getReadableSize(tcpConn->readBuffer)==0 && 
        tcpConn->writeBuffer && getWriteAbleSize(tcpConn->writeBuffer)==0)
        {
            //按照顺序销毁内存
            destroyChannel(tcpConn->channel,tcpConn->eventloop);
            bufferDestroy(tcpConn->readBuffer);
            bufferDestroy(tcpConn->writeBuffer);
            destroyHttpRequest(tcpConn->request);
            destroyHttpResponse(tcpConn->response);
            free(tcpConn);

        }
    }
    Debug("连接断开, 释放资源, gameover, connName: %s", tcpConn->name);
    return 0;
}

struct TcpConnection *TcpConnectionInit(int fd,struct EventLoop *eventloop)
{
    struct TcpConnection* tcpConn=(struct TcpConnection *)malloc(sizeof(struct TcpConnection));
    sprintf(tcpConn->name,"TcpConnection-%d",fd);
    //此时读回调函数readCallBackFunc还未实现，具体该函数是用来接收客户端发来的http请求
    tcpConn->readBuffer=bufferInit(10240);
    tcpConn->writeBuffer=bufferInit(10240);
    tcpConn->eventloop = eventloop;
    tcpConn->request = httpRequestInit();
    tcpConn->response = httpResponseInit();


    tcpConn->channel=channelInit(fd,ReadAble,readCallBackFunc,writeCallBackFunc,TcpConnectionDestroy,tcpConn);

    EventLoopAddTask(eventloop, tcpConn->channel, ADD);
    Debug("和客户端建立连接, threadName: %s, threadID:%ld, connName: %s",
        eventloop->threadName, eventloop->threadID, tcpConn->name);
    return tcpConn;
}


