#pragma once
#include "EventLoop.h"
#include "Channel.h"
#include <string>
#include <sys/select.h>

using namespace std;


//继承父类模板，重写函数
class SelectDispatcher : public Dispatcher
{
public:
    //初始化select、poll、epoll所需的数据块
    SelectDispatcher(EventLoop* eventLoop);
    ~SelectDispatcher();
    //添加注册事件
    int add();  //struct EventLoop * eventloop向外取DispatcherData
    //移除注册事件
    int remove();
    //修改注册事件
    int modify();
    //事件监测
    int dispatch(int Timeout=2); //以秒为单位
private:
    int maxFd;
    fd_set *readfds;
    fd_set *writefds;

};