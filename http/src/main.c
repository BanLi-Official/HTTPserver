#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "server.h" 
int main(int argc , char *argv[])  //参数：1.项目名称 2.端口 3.根目录 
{
    if (argc < 3)
    {
        printf("short of various!\n");
        return -1;
    }
    
    unsigned short port = atoi(argv[1]);//获取第二个参数，第一个参数为项目名称
    chdir(argv[2]);//修改项目地址为指定地址
    int lfd = initListenFd(port);
    epollRun(lfd);
    return 0;
}