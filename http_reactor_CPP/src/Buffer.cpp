#define _GNU_SOURCE 
#include "Buffer.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <sys/uio.h>
#include <unistd.h>





buffer::buffer(int size)
{
    m_data = (char *)malloc(size);
    m_readPos = m_writePos = 0;
    m_capacity = size;
}

buffer::~buffer()
{
    free(m_data);
}

int buffer::bufferExtend(int size)
{
    //剩余可写大于size
    if(getWriteAbleSize()>=size)
    {
        return 0;
    }
    else if(getWriteAbleSize()+ m_readPos >= size)//移动后可写大于size
    {
        int readAbleSize=m_writePos-m_readPos;
        memcpy(m_data , m_data + m_readPos , readAbleSize);
        m_readPos = 0;
        m_writePos = readAbleSize;
    }
    else//可写小于size
    {
        char *temp = (char *)realloc(m_data , size);
        if(temp == NULL)
        {
            printf("realloc Error!\n");
            return -1;
        }
        memset(temp+m_capacity,0,size);
        m_capacity = m_capacity + size;
        m_data = temp;
    }
    return 0;
}

int buffer::getWriteAbleSize()
{
    return m_capacity-m_writePos;
}

int buffer::getReadableSize()
{
    return m_writePos - m_readPos;
}

int buffer::writeStringIntoBuffer(const char *msg, int size)
{
    if(msg==nullptr || size<0)
    {
        printf("writeMsgIntoBuffer Error! buffer==NULL || msg==NULL || size<0\n");
        return -1;
    }
    //先判断空间是否够用，进行扩容
    bufferExtend(size);
    //写数据
    memcpy(m_data+m_writePos , msg ,size);


    m_writePos += size;
    return 0;
}

int buffer::writeStringIntoBuffer(const char *data)
{
    int size = strlen(data);
    writeStringIntoBuffer(data,size);
    return 0;
}

int buffer::writeSocketMsgIntoBuffer(int fd)
{
    if(fd<0)
    {
        printf("writeSocketMsgIntoBuffer Error! buffer==NULL || fd<0\n");
        return -1;
    }
    //声明一个iovec数组,用于存储接收的数据,0号用于直接存储到buffer中 ， 1号暂时先存储到一个堆变量中，后续再扩容写入buffer
    struct iovec iovecs[2];
    int writeAbleSize=getWriteAbleSize();
    iovecs[0].iov_base=m_data+m_writePos;
    iovecs[0].iov_len=writeAbleSize;
    char *temp = (char *)malloc(40960); //堆的长度为40K
    iovecs[1].iov_base=m_data+m_writePos;
    iovecs[1].iov_len=40960;

    //从fd中读取数据
    int result = readv(fd , iovecs ,2);
    if(result == -1)
    {
        printf("writeSocketMsgIntoBuffer Error! readv failed! result=-1");
        return -1;
    }
    else if(result <= writeAbleSize)
    {
        m_writePos+=result;
    }
    else    //此时还有一部分数据在堆中
    {
        // bufferExtend(buffer,result - writeAbleSize);
        // memcpy(buffer->data+buffer->writePos , temp , result - writeAbleSize);
        // buffer->writePos+=result;
        m_writePos = m_capacity;
        writeStringIntoBuffer(temp, result - writeAbleSize);
    }
    free(temp);
    return 1;
}

char *buffer::findFirstLine()
{
    char * local=strstr(m_data+m_readPos,"\r\n");
    return local;
}

int buffer::bufferSendData(int socket)
{
    //判断有无数据
    int readableCount=getReadableSize();
    if(readableCount>0)
    {
        //printf("发送完毕！\n内容如下：\n%s",buffer->data+buffer->readPos);
        int count = send(socket,m_data+m_readPos,readableCount,MSG_NOSIGNAL);
        
        if(count>0)
        {
            m_readPos+=count;
            usleep(1);
        }
        return count;
    }
    return 0;
}
