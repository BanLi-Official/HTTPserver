#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Buffer.h"
#include <stdbool.h>
#include <string.h>

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
//解析请求头
bool parseHeadLine(struct httpRequest* request, struct buffer* readBuffer);