#include "Buffer.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/uio.h>


struct buffer *bufferInit(int size)
{
    struct buffer* buffer = (struct buffer*)malloc(sizeof(struct buffer));
    if(buffer == NULL)
    {
        printf("bufferInit Error! buffer is NULL\n");
        return NULL;
    }
    buffer->data = (char *)malloc(size);
    buffer->readPos = buffer->writePos = 0;
    buffer->capacity = size;

    return buffer;
}


int getWriteAbleSize(struct buffer* buffer )
{
    return buffer->capacity-buffer->writePos;
}

int writeMsgIntoBuffer(struct buffer *buffer, const char *msg, int size)
{
    if(buffer==NULL || msg==NULL || size<0)
    {
        printf("writeMsgIntoBuffer Error! buffer==NULL || msg==NULL || size<0\n");
        return -1;
    }
    //先判断空间是否够用，进行扩容
    bufferExtend(buffer , size);
    //写数据
    memcpy(buffer->data+buffer->writePos , msg ,size);
    buffer->writePos += size;
    return 0;
}

int writeStringIntoBuffer(struct buffer *buffer, const char *data)
{
    int size = strlen(data);
    writeMsgIntoBuffer(buffer,data,strlen);
    return 0;
}

int writeSocketMsgIntoBuffer(struct buffer *buffer, int fd)
{
    if(buffer==NULL || fd<0)
    {
        printf("writeSocketMsgIntoBuffer Error! buffer==NULL || fd<0\n");
        return -1;
    }
    //声明一个iovec数组,用于存储接收的数据,0号用于直接存储到buffer中 ， 1号暂时先存储到一个堆变量中，后续再扩容写入buffer
    struct iovec iovecs[2];
    int writeAbleSize=getWriteAbleSize(buffer);
    iovecs[0].iov_base=buffer->data+buffer->writePos;
    iovecs[0].iov_len=writeAbleSize;
    char *temp = (char *)malloc(40960); //堆的长度为40K
    iovecs[1].iov_base=temp;
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
        buffer->writePos+=result;
    }
    else    //此时还有一部分数据在堆中
    {
        bufferExtend(buffer,result - writeAbleSize);
        memcpy(buffer->data+buffer->writePos , temp , result - writeAbleSize);
        buffer->writePos+=result;
    }
    free(temp);
    return 0;
}

char *findFirstLine(struct buffer *buffer)
{
    //char * local=memmem(buffer->data+buffer->readPos,getWriteAbleSize(buffer),"\r\n",2);
    char * local=strstr(buffer->data+buffer->readPos,"\r\n");
    return local;
}

int bufferExtend(struct buffer* buffer , int size)
{
    //剩余可写大于size
    if(getWriteAbleSize(buffer)>=size)
    {
        return 0;
    }
    else if(getWriteAbleSize(buffer)+ buffer->readPos >= size)//移动后可写大于size
    {
        int readAbleSize=buffer->writePos-buffer->readPos;
        memcpy(buffer->data , buffer->data + buffer->readPos , readAbleSize);
        buffer->readPos = 0;
        buffer->writePos = readAbleSize;
    }
    else//可写小于size
    {
        char *temp = (char *)realloc(buffer->data , size);
        if(temp == NULL)
        {
            printf("realloc Error!\n");
            return -1;
        }
        memset(temp+buffer->capacity,0,size);
        buffer->capacity = buffer->capacity + size;
        buffer->data = temp;
    }
    return 0;
}