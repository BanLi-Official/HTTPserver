#include "ThreadPool.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

struct ThreadPool *threadPoolInit(struct EventLoop *mainEventLoop, int threadNum)
{
    struct ThreadPool *pool = (struct ThreadPool *)malloc(sizeof(struct ThreadPool));
    pool->isStart = false;
    pool->threadNum = threadNum;
    pool->index = 0;
    pool->mainEventLoop = mainEventLoop;
    pool->threads = (struct WorkerThread **)malloc(threadNum * sizeof(struct WorkerThread *));
    return pool;
}

void threadPoolRun(struct ThreadPool *threadPool)
{
    assert(threadPool->isStart == false && threadPool);
    if (threadPool->mainEventLoop->threadID != pthread_self())
    {
        printf("threadPoolRun Error! \n");
        exit(0);
    }

    // 打开开关
    threadPool->isStart = true;
    // 初始化threads当中的工作线程
    if (threadPool->threadNum)
    {
        for (int i = 0; i < threadPool->threadNum; i++)
        {
            workerThreadInit(threadPool->threads[i], i);
            workerThreadRun(threadPool->threads[i]);
        }
    }
}

struct EventLoop *getEventLoop(struct ThreadPool *threadPool)
{
    assert(!threadPool && threadPool->isStart == true);
    if (threadPool->index >= threadPool->threadNum)
    {
        printf("getEventLoop Error ! index is wrong \n");
        exit(0);
    }
     
    struct EventLoop *loop = NULL;
    if (threadPool->threadNum > 0 )
    {
        // 取出需要的EventLoop
        loop = threadPool->threads[threadPool->index]->loop;
        // 更新指向的index
        threadPool->index = ++threadPool->index % threadPool->threadNum;
    }
    else
    {
        printf("getEventLoop Error ! threadPool->threads is Empty\n");
        return NULL;
    }

    return loop;
}