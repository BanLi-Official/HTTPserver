#include "EventLoop.h"
#include "stdbool.h"
#include "stdlib.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include "Log.h"
#include "SelectDispatcher.h"
#include "PollDispatcher.h"
#include "EpollDispatcher.h"
#include "Channel.h"


int EventLoop::readMsgLocal(void *arg)
{
    //readMsgLocal函数中不能直接访问类的非静态成员变量，也不能直接调用非静态成员函数
    EventLoop *loop = (struct EventLoop *)arg;
    char buf[256];
    read(loop->m_socketPairFds[1], buf, sizeof(buf));
    return 0;
}

int EventLoop::readMsg()
{
    char buf[256];
    read(m_socketPairFds[1], buf, sizeof(buf));
    return 0;
}

int EventLoop::writeMsgLocal()
{
    char *msg = "wakeup!";
    write(m_socketPairFds[0], msg, strlen(msg));
    return 0;
}



EventLoop::EventLoop() : EventLoop(string())  //委托构造函数，委托形参有字符串的构造函数进行构造
{
}

EventLoop::EventLoop(const string ThreadName)
{

    // 几个基础的属性变量
    m_threadID = this_thread::get_id();                              // EventLoop的线程号
    m_isRunning = false;                                      // 运行状态
    m_threadName= ThreadName == string() ? "MainThread" : ThreadName; // EventLoop名称

    //loop->dispatcher = &EpollDispatch;               // 分发器
    //m_dispatcher=new PollDispatcher(this);
    m_dispatcher=new EpollDispatcher(this);
    //loop->dispatcher=&selectDispatcher;

    m_channelMap.clear();

    int res = socketpair(AF_UNIX, SOCK_STREAM, 0, m_socketPairFds); // 初始化socketpair数组
    // 规定：loop->socketPairFds[1]读 ，loop->socketPairFds[0]写
    if (res == -1)
    {
        perror("EventLoopInitEX error! res == -1\n");
        exit(0);
    }
    // 将读的文件描述符封装到channel中 ,让dispatcher能够接受到事件，从而唤醒dispatch
#if 0
    struct Channel *channel =new Channel(m_socketPairFds[1], FDevent::ReadAble, readMsgLocal, NULL, NULL, this);
#else
    //绑定-bind   function不能对类的非静态成员函数进行打包，通过绑定器间接完成
    /* 
    std::function 本身是一个函数对象封装器，可以包装可调用的实体（函数指针、成员函数指针、lambda表达式等），但是在包装类的时候需要保证调用方式的一致性。

    非静态成员函数属于特定的类对象实例，并且它在调用时需要接收一个类对象实例作为参数（通过 this 指针传递），而普通的函数和静态成员函数不需要类对象实例作为参数。

    因此，直接通过std::function 尝试捕获一个非静态成员函数时，无法避免这个参数传递，而 std::function 不支持这种隐式参数传递。为了解决这个问题，可以使
    用 std::bind，它可以捕获额外的参数（包括类对象实例 this）并将其传递给成员函数。
    简单来说就是函数对象封装器接受的输入只能是readMsg，但是要用这个函数得这样写EventLoop::readMsg
    */
    auto obj=bind(&EventLoop::readMsg,this);
    struct Channel *channel =new Channel(m_socketPairFds[1], FDevent::ReadAble, obj, NULL, NULL, this);
#endif
    // 将这个channel加入task列表当中
    res = AddTask( channel,Elemtype::ADD);
    m_isRunning=true;
}

EventLoop::~EventLoop()
{
}

int EventLoop::Run()
{
    Dispatcher *dispatcher = m_dispatcher;
    if (dispatcher == NULL)
    {
        printf("EventLoopRun Error!dispatcher == NULL\n");
    }
    while (m_isRunning)
    {
        //Debug("进入循环，开始running");
        
        dispatcher->dispatch();
        
        // 这里还要添加一个将tasklist中任务挂载到dispatch中的函数
        EventLoopListProcess();
        //printf("EventLoopListProcess end\n");sleep(1);
    }
   

    return 0;
}

int EventLoop::activateFD(int fd, int event)
{
    if (fd < 0)
    {
        printf("activateFD Error! fd<0 || loop==NULL\n");
        return -1;
    }
    // 从map中取出channel
    struct Channel *channel = m_channelMap[fd];
    // 断言：channel中的fd必须和形参fd对应
    assert(channel->getFD() == fd);

    // 根据事件类型调用对应的回调函数
    if (event & (int)FDevent::ReadAble && channel->readCallBack != NULL)
    {
        channel->readCallBack(const_cast<void*>(channel->getArg()));
    }
    if (event & (int)FDevent::WriteAble && channel->writeCallBack != NULL)
    {
        channel->writeCallBack(const_cast<void*>(channel->getArg()));
    }

    return 0;
}

int EventLoop::AddTask(Channel *channel, Elemtype type)
{
    m_mutexForList.lock() ;// 为任务list加个互斥锁
    Task *task = new Task();
    task->type = type;
    task->channel = channel;
    m_taskQ.push(task);
    m_mutexForList.unlock();

    // 处理节点
    /*
     * 细节:
     *   1. 对于链表节点的添加: 可能是当前线程也可能是其他线程(主线程)
     *       1). 修改fd的事件, 当前子线程发起, 当前子线程处理
     *       2). 添加新的fd, 添加任务节点的操作是由主线程发起的
     *   2. 不能让主线程处理任务队列, 需要由当前的子线程取处理
     */

    if (m_threadID == this_thread::get_id())
    {
        // 当前子线程(基于子线程的角度分析)
        EventLoopListProcess();
    }
    else
    {
        // 主线程 -- 告诉子线程处理任务队列中的任务
        // 1. 子线程在工作 2. 子线程被阻塞了:select, poll, epoll
        writeMsgLocal();
    }

    return 0;
}

int EventLoop::EventLoopListProcess()
{
    
    
    while (!m_taskQ.empty())
    {
        m_mutexForList.lock();
        //把task队列最前面的东西弄出来
        Task *task = m_taskQ.front();
        m_taskQ.pop();
        m_mutexForList.unlock();
        Channel *channel = task->channel;
        if (task->type == Elemtype::ADD)
        {
            // 添加Channel的任务
            Add(channel);
        }
        else if (task->type == Elemtype::DELETE)
        {
            // 删除Channel的任务
            Remove(channel);
        }
        else if (task->type == Elemtype::MODIFY)
        {
            // 修改Channel的任务
            Modify(channel);
        }
        

        delete task ;
    }

    return 0;
}



int EventLoop::Add(Channel *channel)
{
    int fd = channel->getFD();
    // 找到要插入的位置，确定是否有内容
    if (m_channelMap.find(fd)!=m_channelMap.end())
    {
        // 当前位置有内容
        printf("EventLoopChannelAdd error! 当前位置有内容\n");
        return -1;
    }
    else
    {
        // 当前位置没有内容
        m_channelMap.insert(make_pair(fd,channel));
        m_dispatcher->setChannel(channel);
        int res=m_dispatcher->add();
        return res;
    }
    return 0;
}

int EventLoop::Remove(Channel *channel)
{
    int fd = channel->getFD();
    if (m_channelMap.find(fd)==m_channelMap.end()) // 文件描述符不在map当中
    {
        return -1;
    }
    m_dispatcher->setChannel(channel);
    m_dispatcher->remove();
    return 0;
}



int EventLoop::Modify(Channel *channel)
{
    int fd = channel->getFD();

    if (m_channelMap.find(fd)==m_channelMap.end())
    {
        printf("channelmap当中不存在该channel\n");
        return -1;
    }
    m_dispatcher->setChannel(channel);
    m_dispatcher->modify();
    return 0;
}





int EventLoop::destroyChannel(Channel *channel)
{
    // 将该channel从channelmap当中除去
    auto it=m_channelMap.find(channel->getFD());
    if(it != m_channelMap.end())
    {
        m_channelMap.erase(it);
        close(channel->getFD());
        delete channel;
    }
    return 0;
}









int destroyChannel(struct Channel *channel, struct EventLoop *loop)
{

}