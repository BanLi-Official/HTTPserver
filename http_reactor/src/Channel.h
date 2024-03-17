#pragma once
#include <stdbool.h>

//定义函数指针 handleFunc 是一个指针类型，它可以指向一个接受 void* 类型的参数并返回 int 类型的函数。
typedef int (*handleFunc)(void *arg);

enum FDevent
{
    TimeOut=0x01,
    WriteAble=0x02,
    ReadAble=0x04
};

struct Channel  //封装fd与其回调函数到Channel中，
{
    //文件描述符
    int fd;
    //读写事件标志
    int event;
    //读函数
    handleFunc readCallBack;
    //写函数
    handleFunc writeCallBack;
    //释放arg的内存
    handleFunc destroyCallBack; 
    //读写函数的参数
    void * arg;
};

//初始化Channel函数
struct Channel * channelInit(int fd , int event ,handleFunc readFunc ,handleFunc writeFunc ,handleFunc destroyCallBack,void *arg);
//设置写函数是否有效函数
int setWriteable(struct Channel * channel , bool flag);
//判断写函数是否有效函数
bool checkWriteable(struct Channel *channel);

