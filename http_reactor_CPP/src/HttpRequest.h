#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Buffer.h"
#include <stdbool.h>
#include <string.h>
#include "HTTPResponse.h"
#include <string>
#include <map>
#include <functional>
#include <sys/sendfile.h>
#include <dirent.h>

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
    const string getFileType(string name);
    //修改属性元素
    inline void setMethod(string method){m_method=method;}
    inline void setURL(string URL){m_URL=URL;}
    inline void sethttpVersion(string httpVersion){m_httpVersion=httpVersion;}
    //编写一个函数，功能要求：以某一个字符串分割headline中的元素，分别将元素存储在request结构体的对应位置，并返回一次分割后的剩余内容起始位置
    char* splitHeadLine(char* start , char* end , const char* substr , function<void(string)> callback);
    //// 发送的是一个html文件的内容
    void sendDir(const char* Dir,struct buffer* buffer,int socket);
    //发送文件
    void sendFile(const char* fileName,struct buffer* buffer,int socket);



private:
    //设置解析状态
    inline void setState(parseState state){m_parseState=state;};



private:
    string m_method;
    string m_URL;
    string m_httpVersion;
    map<string,string> m_httpHeads;
    parseState m_parseState;
};


