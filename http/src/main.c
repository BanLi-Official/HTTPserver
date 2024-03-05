#include <stdio.h>
#include "server.h" 
int main()
{
    printf("hello world!\n");
    int lfd = initListenFd(10000);
    epollRun(lfd);
    return 0;
}