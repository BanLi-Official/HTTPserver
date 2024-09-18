#include "ThreadPool.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "Log.h"
#include <unistd.h>

ThreadPool::ThreadPool(EventLoop* mainLoop,int threadNum)
{
    m_isStart = false;
    m_threadNum = threadNum;
    m_index = 0;
    m_mainEventLoop = mainLoop;
    m_threads.clear();

}

ThreadPool::~ThreadPool()
{
    for(auto item:m_threads)
    {
        delete item;
    }
}

void ThreadPool::threadPoolRun()
{
    assert(m_isStart == false );
    if (m_mainEventLoop->getThreadID() != this_thread::get_id())
    {
        printf("threadPoolRun Error! threadPool->mainEventLoop->threadID=%ld, pthread_self() = %ld\n",m_mainEventLoop->getThreadID(),this_thread::get_id());
        exit(0);
    }

    // 打开开关
    m_isStart = true;
    // 初始化threads当中的工作线程
    if (m_threadNum>0)
    {
        for (int i = 0; i < m_threadNum; i++)
        {
            WorkerThread* workerThread=new WorkerThread(i);

            m_threads.push_back(workerThread);
            workerThread->run();
                                

        }
    }
}

EventLoop *ThreadPool::getEventLoop()
{
    assert( m_isStart == true);
    if (m_index >= m_threadNum)
    {
        printf("getEventLoop Error ! index is wrong \n");
        exit(0);
    }
     
    EventLoop *loop = m_mainEventLoop;
    if (m_threadNum > 0 )
    {
        // 取出需要的EventLoop
        loop = m_threads[m_index]->getEventLoop();
        // 更新指向的index
        m_index = ++m_index % m_threadNum;
    }
    else
    {
        printf("getEventLoop Error ! threadPool->threads is Empty\n");
        return NULL;
    }

    return loop;
}
