#pragma once 



//缓冲区用来存储tcp发送的和接受的内容
struct buffer
{
    char *data;
    int capacity;
    int readPos;
    int writePos;
};


//初始化缓冲区
struct buffer* bufferInit(int size);
//扩容缓冲区
int bufferExtend(struct buffer* buffer , int size);
//求解可写区域大小
int getWriteAbleSize(struct buffer* buffer );