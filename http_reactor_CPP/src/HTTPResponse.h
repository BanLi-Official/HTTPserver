#pragma once
#include "Buffer.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <map>
#include <functional>


using namespace std;

//http回复状态码
enum class httpStateCode
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



//http回复内容
class httpResponse
{
public:
    //构造函数
    httpResponse();
    ~httpResponse();
    //添加一个键值对到首部字段
    bool addHttpResponseHeader( const string key , const string value);
    //组织http响应数据
    void httpResponsePrepareMsg(buffer* sendBuffer , int socket);

    //回调函数处理回复报文的主体内容
    function<void(const string ,buffer* ,int )> sendDataFunc;
    //设置私有属性的操作接口
    inline void setStateCode(httpStateCode code){m_stateCode=code;}
    inline void setFilename(string name){m_fileName=name;}
private:
    //状态码
    httpStateCode m_stateCode;
    string m_fileName;
    //键值对
    map<string,string> m_headers;
    //状态信息
    map<int,string> m_info={
        {200,"OK"},
        {204,"NoContent"},
        {301,"MovedPermanently"},
        {302,"MovedTemporarily"},
        {400,"BadRequest"},
        {404,"NotFound"},
        {500,"InternalServerError"}
    };



};


