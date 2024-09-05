#pragma once
#include "EventLoop.h"
#include <thread>
#include <condition_variable>

using namespace std;

//工作线程，一个工作线程中一个EventLoop
class WorkerThread
{
public:
    WorkerThread(int index);
    ~WorkerThread();

    int run();
    inline EventLoop* getEventLoop(){return m_loop;}

private:
    void createEventLoopRunning();
private:
    thread* m_thread;
    thread::id m_threadId;
    string m_threadName;
    EventLoop *m_loop ;
    mutex m_mutex;
    condition_variable condition;  
};


