#include "ThreadPool.h"

struct ThreadPool *threadPoolInit(struct EventLoop *mainEventLoop, int threadNum)
{
    struct ThreadPool* pool = (struct ThreadPool *)malloc(sizeof(struct ThreadPool));
    pool->isStart = false;
    pool->threadNum = threadNum;
    pool->index = 0;
    pool->mainEventLoop = mainEventLoop;
    pool->threads = (struct WorkerThread *)malloc(threadNum * sizeof(struct WorkerThread *));
    return pool;
}

void threadPoolRun(struct ThreadPool *threadPool)
{
    assert(threadPool && !threadPool->isStart);
    if (threadPool->mainEventLoop->threadID != pthread_self())
    {
        exit(0);
    }
    threadPool->isStart = true;
    if (threadPool->threadNum)
    {
        for (int i = 0; i < threadPool->threadNum; ++i)
        {
            workerThreadInit(&threadPool->threads[i], i);
            workerThreadRun(&threadPool->threads[i]);
        }
    }
}

struct EventLoop* getEventLoop(struct ThreadPool * threadPool)
{
    return nullptr;
}