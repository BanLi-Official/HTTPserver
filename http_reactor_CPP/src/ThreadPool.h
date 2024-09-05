#pragma once 
#include "EventLoop.h"
#include "WorkerThread.h"

class ThreadPool
{
public:
    ThreadPool(EventLoop* mainLoop,int threadNum);
    ~ThreadPool();
    //启动线程池
    void threadPoolRun();
    //获取线程池中的某个WorkerThread中的EventLoop
    struct EventLoop* getEventLoop();

private:
    bool m_isStart;
    int m_threadNum;
    int m_index;
    EventLoop* m_mainEventLoop;
    vector<WorkerThread*> m_threads;

};
