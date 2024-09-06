#pragma once
#include "EventLoop.h"
#include "ThreadPool.h"


class tcpServer
{
public:
    tcpServer(unsigned short port , int threadNum);
    ~tcpServer();

    //初始化监听服务器
    void listenerInit(unsigned short port);
    //启动TcpServer
    int Run();
    //接收连接，使用静态函数，便于传递函数参数
    static int acceptConnect(void *arg);

private:
    int m_threadNum;
    EventLoop* m_mainLoop;
    ThreadPool* m_pool;

    int m_lfd;
    unsigned short m_port;
};


