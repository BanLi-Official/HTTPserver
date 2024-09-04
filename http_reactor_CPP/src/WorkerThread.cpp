#include "WorkerThread.h"
#include <stdio.h>
#include "Log.h"

int workerThreadInit(struct WorkerThread *workerThread,int index)
{
    workerThread->loop=NULL;
    workerThread->threadId=0;
    sprintf(workerThread->threadName,"thread-%d",index);
    pthread_mutex_init(&workerThread->mutex,NULL);
    pthread_cond_init(& workerThread->condition,NULL);
    return 0;
}

void * createEventLoopRunning(void * arg)
{
    struct WorkerThread *workerThread = (struct WorkerThread *) arg;
    pthread_mutex_lock(&workerThread->mutex);
    workerThread->loop=EventLoopInitEX(workerThread->threadName);
    pthread_mutex_unlock(&workerThread->mutex);
    pthread_cond_signal(&workerThread->condition);
    EventLoopRun(workerThread->loop);
    return NULL;
}

int workerThreadRun(struct WorkerThread * workerThread)
{
    //创建一个线程运行EventLoop
    pthread_create(&(workerThread->threadId),NULL,createEventLoopRunning,workerThread);
    //等待EventLoop创建完毕
    pthread_mutex_lock(&workerThread->mutex);
    while (workerThread->loop == NULL)
    { 
        pthread_cond_wait(&workerThread->condition,&workerThread->mutex);
    }
    pthread_mutex_unlock(&workerThread->mutex);  
    
    return 0;
}
