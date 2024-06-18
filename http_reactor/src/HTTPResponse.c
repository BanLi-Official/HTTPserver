#include "HTTPResponse.h"
#include <stdlib.h>
#include <strings.h>

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
