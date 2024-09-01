#pragma once 
#include "EventLoop.h"
#include "WorkerThread.h"

struct ThreadPool
{
    bool isStart;
    int threadNum;
    int index;
    struct EventLoop* mainEventLoop;
    struct WorkerThread* threads;
};

//初始化线程池
struct ThreadPool* threadPoolInit(struct EventLoop *mainEventLoop , int threadNum);
//启动线程池
void threadPoolRun(struct ThreadPool* threadPool);
//获取线程池中的某个WorkerThread中的EventLoop
struct EventLoop* getEventLoop(struct ThreadPool * threadPool);