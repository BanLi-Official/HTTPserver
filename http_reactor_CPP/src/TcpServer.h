#pragma once
#include "EventLoop.h"
#include "ThreadPool.h"



struct listener
{
    int lfd;
    unsigned short port;
};

struct tcpServer
{
    int threadNum;
    struct EventLoop* mainLoop;
    struct listener* listener;
    struct ThreadPool* pool;
};


//初始化tcpServer
struct tcpServer* tcpServerInit(unsigned short port , int threadNum);
//初始化监听服务器
struct listener* listenerInit(unsigned short port);
//启动TcpServer
int tcpServerRun(struct tcpServer* tcpServer);