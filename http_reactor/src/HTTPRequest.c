#include "HttpRequest.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

#define headKeySize 12
struct httpRequest* httpRequestInit()
{
    struct httpRequest* request = (struct httpRequest*)malloc(sizeof(struct httpRequest));
    if (request==NULL)
    {
        printf("httpRequestInit Error! malloc is NULL\n");
        exit(0);
    }
    
    resetHttp(request);
    request->headKeys = (struct headKey*)malloc(sizeof(struct headKey)*headKeySize);
    request->headKeyNum = headKeySize;

    return request;
}



int resetHttp(struct httpRequest* request)
{
    request->method = NULL;
    request->URL    = NULL;
    request->httpVersion=NULL;
    request->parseState = paresStop;
    request->headKeyNum = 0;
    return 0;
}


int freeAndResetHttp(struct httpRequest* request)
{
    free(request->method);
    free(request->URL);
    free(request->httpVersion);
    //释放键值对的内存
    if(request->headKeys!=NULL)
    {
        for(int i=0;i<request->headKeyNum;i++)
        {
            free(request->headKeys[i].key);
            free(request->headKeys[i].value);
        }
        //free(request->headKeys);
    }
    resetHttp(request);
}

int destroyHttpRequest(struct httpRequest *request)
{
    if(request!=NULL)
    {
        freeAndResetHttp(request);
        if(request->headKeys!=NULL)
        {
            free(request->headKeys);
        }
    }
    free(request);
    return 0;
}


enum parseState getHttpParseState(struct httpRequest* request)
{
    return request->parseState;
}

int addHttpHeadKeyAndValue(struct httpRequest* request ,const char* key, const char* value)
{
    if(request->headKeyNum < headKeySize)
    {
        request->headKeys[request->headKeyNum].key = (char *)key;
        request->headKeys[request->headKeyNum].value = (char *)value;
        request->headKeyNum++;
    }
    else
    {
        printf("addHttpHeadKeyAndValue Error! headKeyNum IS NOT smaller than headKeySize!\n");
        return -1;
    }
    return 0;
}

char* getHttpHeadValue(struct httpRequest* request ,const char* key)
{
    if(request->headKeys ==NULL)
    {
        printf("getHttpHeadValue Error! headKeys is NULL\n");
        return NULL;
    }
    for(int i=0; i<request->headKeyNum;i++)
    {
        if(strncasecmp(request->headKeys[i].key , key ,strlen(key)) == 0)
        {
            return request->headKeys[i].value;
        }
    }
    return NULL;
}

bool parseHeadLine(struct httpRequest *request,struct buffer *readBuffer)
{
    //   get /xxxxx/xxxx http/1.1
    //先找到第一行的结束位置
    char *end = findFirstLine(readBuffer);
    char *start=readBuffer->data+readBuffer->readPos;
    int headLineSize = end - start;

    if(headLineSize) //开始解析第一行
    {
        //先查找空格出现的位置定位method的位置，然后使用strncpy复制到对应位置
        //char* index = memmem(start,headLineSize," ",1);
        char * index = strstr(start," ");
        int methodSize = index - start;
        request->method = (char *)malloc(methodSize + 1);
        strncpy(request->method , start,methodSize);
        request->method[methodSize] = '\0';

        //解析请求的资源
        start = index +1;
        //char* urlIndex = memmem(start , end-start ," ",1);
        char* urlIndex = strstr(start, " ");
        int urlSize = urlIndex - start;
        request->URL = (char *)malloc(urlSize+1);
        strncpy(request->URL , start , urlSize);
        request->URL[urlSize]= '\0';

        //解析html版本
        start = urlIndex+1;
        int httpSize = end - start;
        request->httpVersion = (char *)malloc(httpSize+1);
        strncpy(request->httpVersion,start,httpSize);
        request->httpVersion[httpSize] = '\0';

        //为后面解析请求头做准备
        request->parseState = parseHead;
        readBuffer->readPos += headLineSize;
        readBuffer->readPos += 2;

        return true;
    }


    return false;
}
