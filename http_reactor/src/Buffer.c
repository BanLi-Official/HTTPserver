#include "Buffer.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


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