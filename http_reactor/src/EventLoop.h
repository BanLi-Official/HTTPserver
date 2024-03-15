#pragma once
#include "Dispatcher.h"

extern struct Dispatcher EpollDispatch;  //从EpollDispatch.c中实例化的一个dispatch变量

struct EventLoop
{
    struct Dispatcher *dispatcher;   //事件调度模块
    void * DispatcherData;    //dispatcher需要的数据，存储的是IO多路复用那三个模型的参数
};