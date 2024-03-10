#pragma once

//初始化监听的套接字
int initListenFd(unsigned short port);

//启动epoll
int epollRun(int lfd);

//添加客户端连接
int connectClient(int cfd,int epfd);

//接收http请求函数
int rescvHTTPRequest(int cfd ,int epfd);

//解析HTTP内容
int parseHTTPRequest(const char * line ,int cfd);

//发送文件
int sendFile(int cfd ,const char *file);

//发送http头
int sendHeadResponse(int cfd, int state , const char *destribe , const char * ContentType , int length);

//获取文件和Content-Type的对应关系
const char* getFileType(const char* name);

//发送文件夹
int sendDir(int cfd,const char *Dir);