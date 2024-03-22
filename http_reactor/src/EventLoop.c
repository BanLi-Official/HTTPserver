#include "EventLoop.h"
#include "stdbool.h"
#include "stdlib.h"
#include <string.h>

struct EventLoop* EventLoopInit()
{
    return EventLoopInitEX(NULL);
}

struct EventLoop* EventLoopInitEX(const char *name)
{
    //初始化空间
    struct EventLoop *loop = (struct EventLoop *)malloc(sizeof(struct EventLoop));

    //几个基础的属性变量
    loop->threadID=pthread_self();  //EventLoop的线程号
    loop->isRunning=false;          //运行状态
    strcpy(loop->threadName,name == NULL ? "MainThread" : name);   //EventLoop名称
    pthread_mutex_init(&loop->mutexForList,NULL);           //TaskList的mutex
    //pthread_cond_init(&loop->condition,&loop->mutexForList);   //TaskList的条件变量


    loop->dispatcher=&EpollDispatch;  // 分发器
    loop->DispatcherData= loop->dispatcher->init(); //初始化数据区（分发器要用的东西）

    loop->head=loop->tail=NULL;  //tasklist的指针

    loop->channelMap=ChannelMapInit(128);  //根据fd找channel的map



    return loop;
}
