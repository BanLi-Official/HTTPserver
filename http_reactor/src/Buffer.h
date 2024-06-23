#pragma once 
#include <sys/socket.h>
#include <stdbool.h>


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
// 得到剩余的可读的内存容量
int getReadableSize(struct buffer* buffer);
//写数据到buffer中： 1.正常写  2.socket接收
int writeMsgIntoBuffer(struct buffer* buffer , const char* msg , int size);
int writeStringIntoBuffer(struct buffer* buffer, const char* data);
//socket收
int writeSocketMsgIntoBuffer(struct buffer* buffer, int fd);
//查找第一行的结束位置
char* findFirstLine(struct buffer* buffer);
//发送buffer中的数据发送出去
int bufferSendData(struct buffer* buffer,int socket);
//销毁buffer
bool bufferDestroy(struct buffer* buffer);