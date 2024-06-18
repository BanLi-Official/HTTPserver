#pragma once
#include "Buffer.h"

//http回复状态码
enum httpStateCode
{
    Unknown,
    OK = 200,                   //成功返回
    NoContent = 204,            //请求处理成功，但是没有资源可以返回
    MovedPermanently = 301,     //永久性重定向，该状态码表示请求的资源已经被分配了新的URI
    MovedTemporarily = 302,     //临时性重定向
    BadRequest = 400,           //请求报文中存在语法错误
    NotFound = 404,              //服务器没有请求的资源
    InternalServerError = 500    //服务器错误
};

struct httpHeader
{
    char key[32];
    char value[128];
};

//定义一个函数指针，用于处理回复给客户端浏览器的数据块
typedef void (*respondeBody)(const char* fileName,struct buffer* buffer,int socket);


//http回复内容
struct httpResponse
{
    //状态码
    enum httpStateCode stateCode;
    char statusMsg[128];
    char fileName[128];
    //键值对
    struct httpHeader* headers;
    int headersNum;
    //回调函数处理回复报文的主体内容
    respondeBody sendDataFunc;


};

//初始化一个httpResponse
struct httpResponse* httpResponseInit();
