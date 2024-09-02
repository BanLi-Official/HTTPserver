#pragma once   //使得头文件可以相互调用
#include "EventLoop.h"
#include "Channel.h"
#include <string>

using namespace std;


struct EventLoop;  //前向声明的作用是在类型还没有完全定义的情况下引入类型的存在
//定义一个Dispatcher的模板，后面用select、poll、epoll来实现
class Dispatcher  
{
public:
    //初始化select、poll、epoll所需的数据块
    Dispatcher(EventLoop* eventLoop);
    virtual ~Dispatcher();
    //添加注册事件
    virtual int add();  //struct EventLoop * eventloop向外取DispatcherData
    //移除注册事件
    virtual int remove();
    //修改注册事件
    virtual int modify();
    //事件监测
    virtual int dispatch(int Timeout=2); //以秒为单位
    //设置channel
    inline void setChannel(Channel* channel){m_channel=channel;}
    
protected:
    Channel* m_channel;
    EventLoop* m_eventloop; 
    string m_name=string();
};