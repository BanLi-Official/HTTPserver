#pragma once
#include "Dispatcher.h"
#include "Channel.h"
#include <pthread.h>
#include "ChannelMap.h"
#include "stdbool.h"


extern struct Dispatcher EpollDispatch;  //从EpollDispatch.c中实例化的一个dispatch变量
extern struct Dispatcher pollDispatcher;
extern struct Dispatcher selectDispatcher;

//任务单元
struct Task
{
    int type;
    struct Channel *channel;
    struct Task * next;
};


struct EventLoop
{
    int threadID;   //EventLoop的线程号
    bool isRunning;
    char threadName[32];  //线程名称
    pthread_mutex_t mutexForList; //任务队列的互斥锁
    pthread_cond_t condition;   //消费者模型的条件变量


    struct Dispatcher *dispatcher;   //事件调度模块
    void * DispatcherData;    //dispatcher需要的数据，存储的是IO多路复用那三个模型的参数

    //任务队列
    struct Task *head;  //头
    struct Task *tail;  //尾

    struct ChannelMap * channelMap;  //根据线程号找Channel
};

struct EventLoop* EventLoopInit();  //EventLoop的初始化函数
struct EventLoop* EventLoopInitEX(const char *name);   //eventloop带名称的初始化函数