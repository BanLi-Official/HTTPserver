#include "WorkerThread.h"
#include <stdio.h>
#include "Log.h"

WorkerThread::WorkerThread(int index)
{
    m_loop=nullptr;
    m_thread=nullptr;
    m_threadId=thread::id();  //先赋值一个无效的id
    m_threadName="thread-"+to_string(index);

}

WorkerThread::~WorkerThread()
{
    if(m_loop!=nullptr)
    {
        delete m_loop;
    }
}

int WorkerThread::run()
{
    //创建一个线程运行EventLoop
    m_thread=new thread(&WorkerThread::createEventLoopRunning,this);
    //等待EventLoop创建完毕
    unique_lock<mutex> locker(m_mutex);
    while (m_loop == NULL)
    { 
        condition.wait(locker);
    }
  

    return 0;
}

void WorkerThread::createEventLoopRunning()
{
    m_mutex.lock();
    m_loop=new EventLoop(m_threadName);
    m_mutex.unlock();
    condition.notify_one();
    m_loop->Run();

}
