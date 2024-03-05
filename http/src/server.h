#pragma once

//初始化监听的套接字
int initListenFd(unsigned short port);

//启动epoll
int epollRun(int lfd);

//添加客户端连接
int connectClient(int cfd,int epfd);