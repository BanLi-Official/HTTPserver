#include "HTTPResponse.h"
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>

#define maxHeadersNum 16


struct httpResponse *httpResponseInit()
{
    struct httpResponse* response = (struct httpResponse*)malloc(sizeof(struct httpResponse));

    //状态行
    response->stateCode=Unknown;
    bzero(response->statusMsg,sizeof(response->statusMsg));
    bzero(response->fileName,sizeof(response->fileName));

    //键值对行
    response->headers=(struct httpHeader *)malloc(sizeof(struct httpHeader )*maxHeadersNum);
    response->headersNum=0;
    bzero(response->headers,sizeof(struct httpHeader )*maxHeadersNum);

    //回调函数
    response->sendDataFunc=NULL;

    return response;
}

void destroyHttpResponse(struct httpResponse *response)
{
    if(response!=NULL)
    {
        free(response->headers);
        free(response);
    }
}

bool addHttpResponseHeader(struct httpResponse *response, const char *key, const char *value)
{
    if(response==NULL || key==NULL || value==NULL)
    {
        return false;
    }

    strcpy(response->headers[response->headersNum].key , key);
    strcpy(response->headers[response->headersNum].value , value);
    response->headersNum++;


    return true;
}

void httpResponsePrepareMsg(struct httpResponse *response, struct buffer *sendBuffer, int socket)
{
    //声明一个临时的数组用于存放组织的内容
    char temp[2048]={0};
    //状态行
    sprintf(temp,"HTTP %d %s\r\n",response->stateCode,response->statusMsg);
    writeStringIntoBuffer(sendBuffer,temp);

    //键值对头
    for(int i=0;i<response->headersNum;i++)
    {
        sprintf(temp,"%s:%s\r\n",response->headers[i].key,response->headers[i].value);
        writeStringIntoBuffer(sendBuffer,temp);
    }

    //空行
    writeStringIntoBuffer(sendBuffer,"\r\n");

    //数据块
    response->sendDataFunc(response->fileName,sendBuffer,socket);
}
