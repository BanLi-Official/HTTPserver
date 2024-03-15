#pragma once   //使得头文件可以相互调用
#include "EventLoop.h"
#include "Channel.h"


struct EventLoop;  //前向声明的作用是在类型还没有完全定义的情况下引入类型的存在
  
struct Dispatcher  //定义一个Dispatcher的模板，后面用select、poll、epoll来实现
{
    //初始化select、poll、epoll所需的数据块
    void * (*init)();
    //添加注册事件
    int (*add)(struct Channel *channel , struct EventLoop * eventloop);  //struct EventLoop * eventloop向外取DispatcherData
    //移除注册事件
    int (*remove)(struct Channel *channel , struct EventLoop * eventloop);
    //修改注册事件
    int (*modify)(struct Channel *channel , struct EventLoop * eventloop);
    //事件监测
    int (*dispatch)(struct EventLoop * eventloop , int Timeout); //以秒为单位
    //清除内存（析构）
    int (*clear)(struct EventLoop * eventloop);
};