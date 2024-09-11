#include "HTTPResponse.h"
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/sendfile.h>
#include <assert.h>
#include <unistd.h>


#define maxHeadersNum 16



httpResponse::httpResponse()
{
    //状态行
    m_stateCode=httpStateCode::Unknown;
    m_fileName=string();
    m_headers.clear();

    //回调函数
    sendDataFunc=nullptr;
}

httpResponse::~httpResponse()
{
}

bool httpResponse::addHttpResponseHeader(const string key, const string value)
{
    if(key.empty()||value.empty())
        return false;
    
    m_headers.insert(make_pair(key,value));
    return true;
}

void httpResponse::httpResponsePrepareMsg(buffer *sendBuffer, int socket)
{
    //声明一个临时的数组用于存放组织的内容
    char temp[2048]={0};
    //状态行
    int code=static_cast<int>(m_stateCode);
    sprintf(temp,"HTTP %d %s\r\n",m_stateCode,m_info.at(code).data());
    sendBuffer->writeStringIntoBuffer(temp);

    //键值对头
    for(auto it=m_headers.begin();it!=m_headers.end();it++)
    {
        sprintf(temp,"%s:%s\r\n",it->first,it->second);
        sendBuffer->writeStringIntoBuffer(temp);

    }

    //空行
    sendBuffer->writeStringIntoBuffer("\r\n");
#ifndef MSG_SENG_AUTO
    sendBuffer->bufferSendData(socket);
#endif

    //数据块
    sendDataFunc(m_fileName,sendBuffer,socket);
}
