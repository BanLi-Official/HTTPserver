#pragma once
#include "EventLoop.h"
#include "Channel.h"
#include <string>

using namespace std;


//继承父类模板，重写函数
class EpollDispatcher : public Dispatcher
{
public:
    //初始化select、poll、epoll所需的数据块
    EpollDispatcher(EventLoop* eventLoop);
    ~EpollDispatcher();
    //添加注册事件
    int add();  //struct EventLoop * eventloop向外取DispatcherData
    //移除注册事件
    int remove();
    //修改注册事件
    int modify();
    //事件监测
    int dispatch(int Timeout=2); //以秒为单位
private:
    // 文件描述符
    int m_epfd;
    // 事件数组
    struct epoll_event *m_events;
    //定义的宏放类中，便于管理
    const int Max=500;
};