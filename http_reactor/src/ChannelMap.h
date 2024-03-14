#pragma once
#include "Channel.h" 
#include <stdbool.h>

//利用数组完成map的功能
struct ChannelMap 
{
    //map容量
    int size;
    //map存储的数组
    struct Channel **list;
};


//初始化map
struct ChannelMap * ChannelMapInit(int size);
//清空map
bool clearChannelMap(struct ChannelMap *map);
//扩容
bool reshapeChannelMap(struct ChannelMap *map ,int newsize);