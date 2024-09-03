#pragma once
#include "Dispatcher.h"
#include "Channel.h"
#include <pthread.h>
#include "stdbool.h"
#include <thread>
#include <mutex>
#include <queue>
#include <map>

using namespace std;

class Dispatcher;
enum class Elemtype:char{
    ADD,
    DELETE,
    MODIFY
};


//任务单元
struct Task
{
    Elemtype type;
    Channel *channel;

};


class EventLoop
{
public:
    EventLoop();
    EventLoop(const string ThreadName);
    ~EventLoop();

    int Run(); //eventloop开始运行
    int activateFD(int fd , int event); //fd激活后启动对应的回调函数
    int AddTask(Channel *channel , int type);     //向eventloop中添加task任务
    int EventLoopListProcess(); //处理task任务
    int Add(Channel *channel );  //向EventLoop中添加channel
    int Remove(Channel *channel ); //向EventLoop中删除channel
    int Modify(Channel *channel ); //向EventLoop中修改channel
    int destroyChannel(Channel *channel ); //除去channel，释放内存

private:
    thread::id m_threadID;   //EventLoop的线程号
    bool m_isRunning;
    string m_threadName;  //线程名称
    mutex m_mutexForList; //任务队列的互斥锁
    pthread_cond_t m_condition;   //消费者模型的条件变量
    Dispatcher *m_dispatcher;   //事件调度模块

    //任务队列
    queue<Task*> m_taskQ;
    map<int,Channel*> m_channelMap;
    int m_socketPairFds[2];   //控制同一个socket的文件描述符对   
                            //规定：loop->socketPairFds[1]读 ，loop->socketPairFds[0]写    loop->socketPairFds[0] -----发送内容----->loop->socketPairFds[1]
                            //将loop->socketPairFds[1]放入dispatcher，这样就可以通过0来唤醒1
};

