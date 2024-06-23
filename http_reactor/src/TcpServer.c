#include "TcpServer.h"
#include <arpa/inet.h>
#include <sys/socket.h>
#include "EventLoop.h"
#include "Channel.h"
#include <stdio.h>
#include <stdlib.h>
#include "TcpConnection.h"
#include "Log.h"

struct tcpServer *tcpServerInit(unsigned short port, int threadNum)
{
    struct tcpServer* tcpServer = (struct tcpServer*)malloc(sizeof(struct tcpServer));
    if(tcpServer == NULL)
    {
        printf("tcpServerInit Error!tcpServer == NULL\n");
        exit(0);
    }

    tcpServer->listener = listenerInit(port);
    tcpServer->mainLoop = EventLoopInit();
    tcpServer->threadNum = threadNum;
    tcpServer->pool = threadPoolInit(tcpServer->mainLoop , threadNum);
    return tcpServer;
}


struct listener* listenerInit(unsigned short port)
{
    struct listener * listener = (struct listener *)malloc(sizeof(struct listener));
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
    listener->lfd = lfd;
    listener->port = port;
    return listener;
}   

int acceptConnect(void *arg)
{
    struct tcpServer* tcpServer= (struct tcpServer*)arg;
    int cfd=accept(tcpServer->listener->lfd,NULL,NULL);
    //从线程池中取出一个EventLoop去处理这个连接
    struct EventLoop* tempLoop= getEventLoop(tcpServer->pool);
    //接下来将这个cfd挂入tempLoop当中，完成dispacher的挂载 
    //先将这个cfd封装到channel当中，然后再将channel和EventLoop和buffer、http等相关内容封装到TCPConnection当中，之后的数据交流就再TCPConnection进行
    struct TcpConnection* tcpConn = TcpConnectionInit(cfd,tempLoop);





    return 0;
}

int tcpServerRun(struct tcpServer* tcpServer)
{
    //启动线程池
    threadPoolRun(tcpServer->pool);

    //将lfd添加到主loop当中
    struct Channel *channel = channelInit(tcpServer->listener->lfd,ReadAble,acceptConnect,NULL,NULL,tcpServer);
    EventLoopAddTask(tcpServer->mainLoop,channel,ADD);
    //启动mainEventLoop
    EventLoopRun(tcpServer->mainLoop);
    Debug("服务器程序已经启动了....");

}


