#pragma once
#include "Dispatcher.h"
#include "Channel.h"
#include <pthread.h>
#include "ChannelMap.h"
#include "stdbool.h"

extern struct Dispatcher EpollDispatch;  //从EpollDispatch.c中实例化的一个dispatch变量
extern struct Dispatcher pollDispatcher;
extern struct Dispatcher selectDispatcher;


enum Elemtype{
    ADD,
    DELETE,
    MODIFY
};


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
    int socketPairFds[2];   //控制同一个socket的文件描述符对   
                            //规定：loop->socketPairFds[1]读 ，loop->socketPairFds[0]写    loop->socketPairFds[0] -----发送内容----->loop->socketPairFds[1]
                            //将loop->socketPairFds[1]放入dispatcher，这样就可以通过0来唤醒1
};

struct EventLoop* EventLoopInit();  //EventLoop的初始化函数
struct EventLoop* EventLoopInitEX(const char *name);   //eventloop带名称的初始化函数
int EventLoopRun(struct EventLoop* loop); //eventloop开始运行
int activateFD(struct EventLoop* loop , int fd , int event); //fd激活后启动对应的回调函数
int EventLoopAddTask(struct EventLoop *loop , struct Channel *channel , int type);     //向eventloop中添加task任务
int EventLoopListProcess(struct EventLoop *loop); //处理task任务
int EventLoopChannelAdd(struct Channel *channel ,struct EventLoop *loop);  //向EventLoop中添加channel