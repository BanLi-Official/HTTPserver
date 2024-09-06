#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Buffer.h"
#include <stdbool.h>
#include <string.h>
#include "HTTPResponse.h"
#include <string>

using namespace std;

enum class parseState : char
{
    paresStop,
    parseLine,
    parseHead,
    parseBody,
    parseDone
};


//http请求
class httpRequest  
{
public:
    //初始化http请求
    httpRequest();
    ~httpRequest();
    //重置http请求内容 ,将请求头和解析状态重置
    int reset();
    //包含释放内存的重置
    int freeAndResetHttp();
    //获取http解析状态
    parseState getHttpParseState();
    //添加请求头键值对
    int addHttpHead(const string key, const string value);
    //查找请求头键值对
    string getHeadValue(const string key);
    //解析请求行
    bool parseHeadLine(buffer* readBuffer);
    //解析请求头键值对
    bool parseHeader(buffer* readBuffer);
    //解析整个httpRequest
    bool parseHTTPRequest(buffer* readBuffer,httpResponse* response ,buffer* sendBuffer , int socket);
    //处理httpRequest
    bool processHTTPRequest(httpResponse* response);
    //解码包括中文字符在内的编码
    string DecodeMsg(string from);
    //获取对应文件的类型
    string getFileType(string name);

private:
    char* m_method;
    char* m_URL;
    char* m_httpVersion;
    struct headKey* m_headKeys;
    int m_headKeyNum;
    enum parseState m_parseState;
};


