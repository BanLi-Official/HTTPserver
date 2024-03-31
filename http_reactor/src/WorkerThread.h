#pragma once
#include "EventLoop.h"
#include <pthread.h>

//工作线程，一个工作线程中一个EventLoop
struct WorkerThread
{
    pthread_t threadId;
    char threadName[24];
    struct EventLoop *loop ;
    pthread_mutex_t mutex;
    pthread_cond_t condition;  
};

//初始化一个工作线程
int workerThreadInit(struct WorkerThread * workerThread,int index);

//启动工作线程
int workerThreadRun(struct WorkerThread * workerThread);

