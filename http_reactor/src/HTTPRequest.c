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

//编写一个函数，功能要求：以某一个字符串分割headline中的元素，分别将元素存储在request结构体的对应位置，并返回一次分割后的剩余内容起始位置
char* splitHeadLine(char* start , char* end , const char* substr , char** ptr)
{
    char* subLocation=end;
    if(substr != NULL)
    {
        subLocation = strstr(start , substr); //查找子字符串的位置
        if(subLocation == NULL)
        {
            printf("splitHeadLine Error! space == NULL\n");
        }
    }
    int containtLength = end-subLocation;    //计算分割的内容的长度
    char* temp=(char *)malloc(containtLength+1);
    strncpy(temp,start,containtLength);     //将内容暂时存储到一个临时变量中
    temp[containtLength]='\0';
    start = subLocation+1;
    *ptr=temp;                              //将被分割的内容赋值到对应的目标位置，这里的ptr是一个二级指针
    return start;
} 

bool parseHeadLine(struct httpRequest *request,struct buffer *readBuffer)
{
    //   get /xxxxx/xxxx http/1.1
    //先找到第一行的结束位置
    char *end = findFirstLine(readBuffer);
    char *start=readBuffer->data+readBuffer->readPos;
    int headLineSize = end - start;

    //代码优化版本
    if(headLineSize)
    {
        start = splitHeadLine(start,end," ",&request->method);    //解析方法
        start = splitHeadLine(start,end," ",&request->URL);       //解析文件地址
        splitHeadLine(start,end,NULL,&request->httpVersion);      //解析http版本

        //为后面解析请求头做准备
        request->parseState = parseHead;
        readBuffer->readPos += headLineSize;
        readBuffer->readPos += 2;

        return true;
    }


#if 0
    //粗略版本

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
#endif

    return false;
}
