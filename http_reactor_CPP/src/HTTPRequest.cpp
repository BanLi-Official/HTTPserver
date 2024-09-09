#include "HttpRequest.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "Log.h"
#include <asm-generic/fcntl.h>
#include <fcntl.h>
#include <cassert>

#define headKeySize 12




int hexToDec(char c)
{
    if(c >= '0' && c <= '9')
        return c-'0';
    if(c >= 'a' && c <= 'z')
        return c-'a'+10;
    if(c >= 'A' && c <= 'Z')
        return c-'A'+10;
    return 0;
}



const char* getFileType(const char* name)
{
    
}




httpRequest::httpRequest()
{
    reset();
    return;
}

httpRequest::~httpRequest()
{

}

int httpRequest::reset()
{
    m_method = string();
    m_URL    = string();
    m_httpVersion=string();
    m_parseState = parseState::parseLine;
    m_httpHeads.clear();
    return 0;
}

int httpRequest::freeAndResetHttp()
{
    reset();
    return 0;
}

parseState httpRequest::getHttpParseState()
{
    return this->m_parseState;
}

int httpRequest::addHttpHead(const string key, const string value)
{
    m_httpHeads.insert(make_pair(key,value));
    return 0;
}

string httpRequest::getHeadValue(const string key)
{
    auto iter=m_httpHeads.find(key);
    if(iter==m_httpHeads.end())
    {
        return string();
    }
    
    return m_httpHeads[key];
}


//编写一个函数，功能要求：以某一个字符串分割headline中的元素，分别将元素存储在request结构体的对应位置，并返回一次分割后的剩余内容起始位置
char* httpRequest::splitHeadLine(char* start , char* end , const char* substr , function<void(string)> callback)
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
    int containtLength = subLocation-start;    //计算分割的内容的长度
    callback(string(start,containtLength));
                                //将被分割的内容赋值到对应的目标位置，这里的ptr是一个二级指针
    return subLocation+1;
}


bool httpRequest::parseHeadLine(buffer *readBuffer)
{
        //   get /xxxxx/xxxx http/1.1
    //先找到第一行的结束位置

    //Debug("parseHeadLine里面的readBuffer数据: %s ", readBuffer->data + readBuffer->readPos);

    char *end = readBuffer->findFirstLine();
    char *start=readBuffer->getReadPosition();
    int headLineSize = end - start;

    //代码优化版本
    if(headLineSize)
    {
        auto methodFunc=bind(&httpRequest::setMethod,this,placeholders::_1);
        start = splitHeadLine(start,end," ",methodFunc);    //解析方法
        auto urlFunc=bind(&httpRequest::setURL,this,placeholders::_1);
        start = splitHeadLine(start,end," ",urlFunc);       //解析文件地址
        auto httpVersionFunc=bind(&httpRequest::sethttpVersion,this,placeholders::_1);
        splitHeadLine(start,end,NULL,httpVersionFunc);      //解析http版本

        //为后面解析请求头做准备
        setstate((char*)parseState::parseHead);
        readBuffer->setReadPosition(headLineSize+2);
        return true;
    }
    return false;
}

bool httpRequest::parseHeader(buffer *readBuffer)
{
    //每一行的样子：   key: value
    //该行的结束位置
    //Debug("readBuffer=%s",readBuffer->data+readBuffer->readPos);
    char* end=readBuffer->findFirstLine();
    if(end!=NULL)
    {
        char* start=readBuffer->getReadPosition();
        int lineLength=end-start;
        //根据： 分割该行
        char* splitPosition=strstr(start,": ");
        if(splitPosition==NULL)
        {
            //请求头已经被检查完了，跳到下一行
            readBuffer->setReadPosition(2);
            //修改状态(这里默认使用get模式，直接跳过第三部分)
            setstate((char*)parseState::parseDone);
            Debug("请求头已经被检查完了，跳到下一行");
            return true;
        }
        //找key
        int keyLen=splitPosition-start;
        int valueLen=end-splitPosition-2;
        if(keyLen>0 && valueLen>0)
        {
            string key(start,keyLen);
            string value(splitPosition,valueLen);
            addHttpHead(key,value);
        }

        //移动读取位置，移动到下一行
        readBuffer->setReadPosition(lineLength+2);

        return true;
    }
    else
    {
        //请求头已经被检查完了，跳到下一行
        readBuffer->setReadPosition(2);
        //修改状态(这里默认使用get模式，直接跳过第三部分)
        setstate((char*)parseState::parseDone);
        Debug("请求头已经被检查完了，跳到下一行");
        return true;
    }

    return false;
}

bool httpRequest::parseHTTPRequest(buffer *readBuffer, httpResponse *response, buffer *sendBuffer, int socket)
{
    
    
    bool flag=true;
    while(m_parseState!=parseState::parseDone)
    {
        switch(m_parseState)
        {
        case parseState::parseLine:
            flag=parseHeadLine(readBuffer);
            break;
        case parseState::parseHead:
            flag=parseHeader(readBuffer);
            break;
        case parseState::parseBody:
            break;
        default:
            break;
        }

        //如果出现错误则返回错误状态
        if(!flag)
        {
            return flag;
        }

        //如果解析结束，则准备回复的数据
        
        
        //printf("request.method=%s,  request.URL=%s,   request.httpVersion=%s,    headKeyNums=%d,   parseState=%d\n",request->method,request->URL,request->httpVersion,request->headKeyNum,request->parseState);


        if(m_parseState==parseState::parseDone)
        {
            //1.根据解析出来的数据，对客户端的请求做出处理
            processHTTPRequest(response);
            //2.组织响应数据并发送给客户端
            httpResponsePrepareMsg(response , sendBuffer , socket);
        }
    }

    //将request的解析状态还原，保证下一次解析能够正确进行
    setstate((char*)parseState::parseLine);

    return flag;
}

bool httpRequest::processHTTPRequest(httpResponse *response)
{
    //基于Get的request请求处理函数
    //解码请求中的所请求的文件路径
    m_URL=DecodeMsg(m_URL);
    //printf("type = %s  ,path = %s \n", type, path);
    const char * file=NULL;
    if (strcasecmp(m_method.data(), "get") == 0) // 判断表头的类型
    {
        // get类型
        // 将地址转化为相对地址
        if (strcmp(m_URL.data(), "/") == 0)
        {
            file = "./";
        }
        else
        {
            file = m_URL.data() + 1;
        }
        

        // 读取这个文件/夹  https://blog.csdn.net/qq_48383456/article/details/136544350?spm=1001.2014.3001.5502
        struct stat st;
        int res = stat(file, &st);
        if (res == -1)
        {
            //printf("404 file is not Found!\n");
            // sendHeadResponse(cfd, 404, "Not Found!", getFileType(".html"), -1);
            // sendFile(cfd, "404.html");


            //构建httpResponse
            //状态行
            strcpy(response->fileName,"404.html");
            response->stateCode=NotFound;
            strcpy(response->statusMsg,"FileNotFound");

            //响应头
            addHttpResponseHeader(response , "Content-type",getFileType(".html"));
            response->sendDataFunc=sendFile;

            return -1;
        }

        //找到了该文件（夹）则发送过去
        strcpy(response->fileName, file);
        response->stateCode=OK;
        strcpy(response->statusMsg, "OK");

        

        if (S_ISDIR(st.st_mode))
        {
            // 把文件夹的内容发送给客户端；
            printf("this path is dir! path=%s\n", file);
            // sendHeadResponse(cfd, 200, "OK", getFileType(".html"), -1);
            // sendDir(cfd, file);

            //添加对应的键值对，响应头
            addHttpResponseHeader(response , "Content-type",getFileType(".html"));

            //设置数据块发送方式
            response->sendDataFunc=sendDir;
        }
        else
        {
            // 把文件的内容发送给客户端；
            printf("this path is file! path=%s  st_size = %d\n  ", file,(int)st.st_size);
            // sendHeadResponse(cfd, 200, "OK", getFileType(file), st.st_size);
            // sendFile(cfd, file);


            //添加键值对,响应头
            char temp[1024];
            sprintf(temp,"%ld",st.st_size);
            addHttpResponseHeader(response,"Content-Length",temp);
            addHttpResponseHeader(response , "Content-type",getFileType(file));

            //设置数据块发送方式
            response->sendDataFunc=sendFile;
        }


    }
    else
    {
        // 其他类型
        printf("无法处理的http请求类型\n");
        return -1;
    }


    return false;
}

string httpRequest::DecodeMsg(string name)
{
    const char* from=name.data();
    string res;
    for(;from[0] != '\0';from++)
    {
        //printf("from[0]=%c\n",from[0]);
        if(from[0] == '%' && from[1]!='\0' && from[2]!='\0')
        {
            res.append(1,hexToDec(from[1])*16+hexToDec(from[2]));
            from=from+2;
        }
        else
        {
            res.append(1,from[0]);
        }
    }
    res.append(1,'\0');
    return res;
}

const string httpRequest::getFileType(string name)
{
    // a.jpg a.mp4 a.html
    // 自右向左查找‘.’字符, 如不存在返回NULL
    const char* dot = strrchr(name.data(), '.');
    if (dot == NULL)
        return "text/plain; charset=utf-8";	// 纯文本
    if (strcmp(dot, ".html") == 0 || strcmp(dot, ".htm") == 0)
        return "text/html; charset=utf-8";
    if (strcmp(dot, ".jpg") == 0 || strcmp(dot, ".jpeg") == 0)
        return "image/jpeg";
    if (strcmp(dot, ".gif") == 0)
        return "image/gif";
    if (strcmp(dot, ".png") == 0)
        return "image/png";
    if (strcmp(dot, ".css") == 0)
        return "text/css";
    if (strcmp(dot, ".au") == 0)
        return "audio/basic";
    if (strcmp(dot, ".wav") == 0)
        return "audio/wav";
    if (strcmp(dot, ".avi") == 0)
        return "video/x-msvideo";
    if (strcmp(dot, ".mov") == 0 || strcmp(dot, ".qt") == 0)
        return "video/quicktime";
    if (strcmp(dot, ".mpeg") == 0 || strcmp(dot, ".mpe") == 0)
        return "video/mpeg";
    if (strcmp(dot, ".vrml") == 0 || strcmp(dot, ".wrl") == 0)
        return "model/vrml";
    if (strcmp(dot, ".midi") == 0 || strcmp(dot, ".mid") == 0)
        return "audio/midi";
    if (strcmp(dot, ".mp3") == 0)
        return "audio/mpeg";
    if (strcmp(dot, ".ogg") == 0)
        return "application/ogg";
    if (strcmp(dot, ".pac") == 0)
        return "application/x-ns-proxy-autoconfig";

    return "text/plain; charset=utf-8";
}





int compare(const struct dirent **a, const struct dirent **b)
{
    return strcoll(((struct dirent **)a)[0]->d_name, ((struct dirent **)b)[0]->d_name);
}


void httpRequest::sendDir(const char *Dir, buffer *buffer, int socket)
{
     char html[4096] = {0};
    printf("开始发送文件夹！\n");
    sprintf(html, "<!DOCTYPE html><html lang=\"en\"><head><title>%s</title></head><body><table>", Dir);

    struct dirent **namelist;
    int num = scandir(Dir, &namelist, NULL, compare); // 设置C编译器标准为GNU C11

    for (int i = 0; i < num; i++) // 遍历所有内容
    {
        char *name = namelist[i]->d_name; // 获取子文件名称
        struct stat st;
        char subDir[1024] = {0};
        sprintf(subDir, "%s/%s", Dir, name); // 补充文件地址，用于判断对应的子文件属性
        int res = stat(subDir, &st);
        if (S_ISDIR(st.st_mode))
        {
            // 文件夹内容
            sprintf(html + strlen(html), "<tr><td><a href=\"%s/\">%s</a></td><td>%ld</td></tr>", name, name, st.st_size);
        }
        else
        {
            // 文件内容
            sprintf(html + strlen(html), "<tr><td><a href=\"%s\">%s</a></td><td>%ld</td></tr>", name, name, st.st_size);
        }
        //printf("html=%s\n",html);
        //writeStringIntoBuffer(buffer,html);
        buffer->writeStringIntoBuffer(html);
        
#ifndef MSG_SENG_AUTO
        //bufferSendData(buffer,socket);
        buffer->bufferSendData(socket);
#endif
        memset(html , 0 , sizeof html); //将缓冲池中的数据清零
        free(namelist[i]);
    }
    // 补充html文件剩下的内容
    sprintf(html + strlen(html), "</table></body></html>");
    //send(cfd, html, strlen(html), 0);
    //将buf中的内容传递到待发送区域Buffer中
    //writeStringIntoBuffer(buffer,html);
    buffer->writeStringIntoBuffer(html);
#ifndef MSG_SENG_AUTO
    //bufferSendData(buffer,socket);
    buffer->bufferSendData(socket);
#endif
    memset(html , 0 , sizeof html); //将缓冲池中的数据清零
    free(namelist);
}

void httpRequest::sendFile(const char *fileName, buffer *buffer, int socket)
{
    
    int fd = open(fileName, O_RDONLY);
    assert(fd > 0); // 加个断言，判断文件成功打开

#if 1
    //常规方法
    char buf[1024] = { 0 };
    int len=read(fd , buf ,sizeof buf);
    while (len > 0)
    {
        
        //usleep(10);  //中间空出点时间，掌握好发送节奏
        // send(cfd,buf,sizeof buf ,0);
        //将数据传到buffer中
        //writeMsgIntoBuffer(buffer,buf,len);
        buffer->writeStringIntoBuffer(buf,len);
#ifndef MSG_SENG_AUTO
        buffer->bufferSendData(socket);
#endif
        memset(buf , 0 , sizeof buf); //将缓冲池中的数据清零
        len=read(fd , buf ,sizeof buf);
    }
    if (len == 0)
    {
        printf("file is READ END\n\n");
    }
    else
    {
        printf("READ ERROR!\n\n");

    }

#else
    // 简单的调函数sendFile（）；
    int fileSize = lseek(fd, 0, SEEK_END); // 此时文件的指针已经指向了末尾，所以需要将指针重新移动回到前面
    lseek(fd, 0, SEEK_SET);
    off_t offset = 0;
    while (offset < fileSize)
    {
        int res = sendfile(cfd, fd, &offset, fileSize - offset); // 这个函数的发送缓冲区也只有200k不到，所以依然需要不断循环发送，发送完成之后会修改offset的值
        if (res == -1 && errno ==EAGAIN)
        {
            //perror("file error:");
        }
        else if(res == -1)
        {
            perror("file error:");
        }
        else
        {
            //printf("sendfile发送了一次... offset = %d\n", (int)offset);
        }
    }
    
#endif
    close(fd);
}

