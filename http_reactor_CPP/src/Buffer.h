#pragma once 
#include <sys/socket.h>
#include <stdbool.h>


//缓冲区用来存储tcp发送的和接受的内容
class buffer
{
public:
    //初始化缓冲区
    buffer(int size);
    //销毁buffer
    ~buffer();
    //扩容缓冲区
    int bufferExtend(int size);
    //求解可写区域大小
    int getWriteAbleSize();
    // 得到剩余的可读的内存容量
    int getReadableSize();
    //写数据到buffer中： 1.正常写  2.socket接收
    int writeStringIntoBuffer(const char* msg , int size);
    int writeStringIntoBuffer(const char* data);
    //socket收
    int writeSocketMsgIntoBuffer(int fd);
    //查找第一行的结束位置
    char* findFirstLine();
    //发送buffer中的数据发送出去
    int bufferSendData(int socket);

private:
    char *m_data;
    int m_capacity;
    int m_readPos;
    int m_writePos;
};


