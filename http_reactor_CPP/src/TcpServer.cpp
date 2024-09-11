#include "TcpServer.h"
#include <arpa/inet.h>
#include <sys/socket.h>
#include "EventLoop.h"
#include "Channel.h"
#include <stdio.h>
#include <stdlib.h>
#include "TcpConnection.h"
#include "Log.h"


 

int tcpServer::acceptConnect(void *arg)
{
    tcpServer* TcpServer= static_cast<tcpServer*>(arg);
    int cfd=accept(TcpServer->m_lfd,NULL,NULL);
    //从线程池中取出一个EventLoop去处理这个连接
    EventLoop* tempLoop= TcpServer->m_pool->getEventLoop();
    //接下来将这个cfd挂入tempLoop当中，完成dispacher的挂载 
    //先将这个cfd封装到channel当中，然后再将channel和EventLoop和buffer、http等相关内容封装到TCPConnection当中，之后的数据交流就再TCPConnection进行

    TcpConnection* tcpConn = new TcpConnection(cfd,tempLoop);

    return 0;
}



tcpServer::tcpServer(unsigned short port, int threadNum)
{
    listenerInit(port);
    m_mainLoop = new EventLoop();
    m_threadNum = threadNum;
    m_pool = new ThreadPool(m_mainLoop,m_threadNum);
}

void tcpServer::listenerInit(unsigned short port)
{
    int lfd = socket(AF_INET,SOCK_STREAM,0);
    if(lfd == -1)
    {
        printf("listenerInit Error! lfd =-1\n");
        exit(0);
    }
    //设置端口复用
    int opt = 1;
    int ret = setsockopt(lfd,SOL_SOCKET, SO_REUSEADDR, &opt, sizeof opt);
    //绑定
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr= INADDR_ANY;
    addr.sin_port=htons(port);
    int res = bind(lfd,(struct sockaddr *)&addr,sizeof(addr));
    if(res == -1)
    {
        printf("listenerInit Error! bind Failed!\n");
        exit(0);
    }
    //监听
    res = listen(lfd , 128);
    if(res == -1)
    {
        printf("listenerInit Error! listen Failed!\n");
        exit(0);
    }
    //赋值
    m_lfd = lfd;
    m_port = port;
}

int tcpServer::Run()
{
    //启动线程池
    m_pool->threadPoolRun();

    //将lfd添加到主loop当中
    Channel *channel = new Channel(m_lfd,FDevent::ReadAble,acceptConnect,NULL,NULL,this);
    m_mainLoop->AddTask(channel,Elemtype::ADD);
    //启动mainEventLoop
    m_mainLoop->Run();
    Debug("服务器程序已经启动了....");
    return 0;
}
