#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Buffer.h"
#include <stdbool.h>
#include <string.h>
#include "HTTPResponse.h"

enum parseState
{
    paresStop,
    parseLine,
    parseHead,
    parseBody,
    parseDone
};

//请求头的键值对
struct headKey
{
    char* key;
    char* value;
};

//http请求
struct httpRequest  
{
    char* method;
    char* URL;
    char* httpVersion;
    struct headKey* headKeys;
    int headKeyNum;
    enum parseState parseState;
};


//初始化http请求
struct httpRequest* httpRequestInit();
//重置http请求内容 ,将请求头和解析状态重置
int resetHttp(struct httpRequest* request);
//包含释放内存的重置
int freeAndResetHttp(struct httpRequest* request);
//销毁http请求
int destroyHttpRequest(struct httpRequest* request);
//获取http解析状态
enum parseState getHttpParseState(struct httpRequest* request);
//添加请求头键值对
int addHttpHeadKeyAndValue(struct httpRequest* request ,const char* key, const char* value);
//查找请求头键值对
char* getHttpHeadValue(struct httpRequest* request ,const char* key);
//解析请求行
bool parseHeadLine(struct httpRequest* request, struct buffer* readBuffer);
//解析请求头键值对
bool parseHeader(struct httpRequest* request , struct buffer* readBuffer);
//解析整个httpRequest
bool parseHTTPRequest(struct httpRequest* request,struct buffer* readBuffer,struct httpResponse* response , struct buffer* sendBuffer , int socket);
//处理httpRequest
bool processHTTPRequest(struct httpRequest* request);
//解码包括中文字符在内的编码
void DecodeMsg(char *from, char *to);