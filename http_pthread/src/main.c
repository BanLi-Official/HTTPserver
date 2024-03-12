#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "server.h"

//./main 10000 ../RunningSpace
int main(int argc, char *argv[]) // 参数：1.项目名称 2.端口 3.根目录
{
#if 1
    //主程序运行区
    if (argc < 3)
    {
        printf("short of various!\n");
        return -1;
    }

    unsigned short port = atoi(argv[1]); // 获取第二个参数，第一个参数为项目名称
    chdir(argv[2]);                      // 修改项目地址为指定地址
    char buffer[100];
    if (getcwd(buffer, sizeof(buffer)) != NULL)
    {
        printf("当前程序运行的文件空间：%s\n", buffer);
    }
    else
    {
        perror("获取当前路径失败");
        return EXIT_FAILURE;
    }
    int lfd = initListenFd(port);
    epollRun(lfd);
    return 0;
#else
    //函数测试区
    char c='A';
    printf("%c to Dec is %d\n",c,hexToDec(c));
#endif
}