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
//写数据到buffer中： 1.正常写  2.socket接收
int writeMsgIntoBuffer(struct buffer* buffer , const char* msg , int size);
//socket收
int writeSocketMsgIntoBuffer(struct buffer* buffer, int fd);
//查找第一行的结束位置
char* findFirstLine(struct buffer* buffer);