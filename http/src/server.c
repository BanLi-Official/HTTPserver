#include "server.h"
#include <arpa/inet.h>
#include <stdio.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

int initListenFd(unsigned short port)
{
    //创建监听fd
    int lfd=socket(AF_INET,SOCK_STREAM,0);
    if(lfd==-1)
    {
        printf("socket error!\n");
        return -1;
    }
    //设置端口复用
    int apt=1;
    int res=setsockopt(lfd,SOL_SOCKET, SO_REUSEADDR, &apt,sizeof(apt));  //该套接字完成关闭后，即使还有其他套接字仍然在使用它绑定的地址和端口，新的套接字仍然可以绑定到相同的地址和端口上。
    if(res==-1)
    {        
        printf("setsockopt error!\n");
        return -1; 
    }
    //绑定
    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_port=htons(port);
    addr.sin_addr.s_addr=INADDR_ANY;

    res=bind(lfd,(struct sockaddr *)&addr,sizeof(struct sockaddr));
    if(res==-1)
    {        
        printf("bind error!\n");
        return -1; 
    }
    //监听
    res=listen(lfd,128);
    if(res==-1)
    {        
        printf("listen error!\n");
        return -1; 
    }
    //返回
    printf("initListenFd 初始化监听套接字成功\n");
    return lfd;
}


int connectClient(int lfd, int epfd)
{
    if(lfd == -1)
    {
        printf("connectClient error ! , lfd is NULL\n");
        return -1;
    } 
    //接收传来的连接
    struct sockaddr_in add;
    int size = sizeof(add);
    int cfd = accept(lfd,(struct sockaddr *)&add,(socklen_t *)&size);
    //int cfd = accept(lfd,NULL,NULL);
    if(cfd == -1)
    {
        printf("connectClient error ! , accept  error\n");
        return -1;
    }
    //将连接设置为非阻塞状态
    int flag = fcntl(cfd,F_GETFL);
    flag |= O_NONBLOCK;
    int res = fcntl(cfd,F_SETFL,flag);
    if (res == -1)
    {
        printf("connectClient error ! , fcntl  error\n");
        return -1;
    }
    
    //将这个连接放入epoll中
    struct epoll_event ev;
    ev.data.fd = cfd;
    ev.events = EPOLLIN | EPOLLET;
    res = epoll_ctl(epfd,EPOLL_CTL_ADD,cfd,&ev);
    if (res == -1)
    {
        printf("connectClient error ! , epoll_ctl EPOLL_CTL_ADD error\n");
        return -1;
    }

    printf("成功添加socket客户连接：%s , 端口为：%d\n",inet_ntoa(add.sin_addr),ntohs(add.sin_port));
    return 0;
}

int rescvHTTPRequest(int cfd, int epfd)
{
    if (cfd == -1 || epfd ==-1)
    {
        printf("rescvHTTPRequest error! cfd || epfd IS NULL\n");
        return -1;
    }

    char buf[4096] = {0};
    char temp[1024] = {0};
    int len;
    int total=0;
    while ((len=recv(cfd,temp,sizeof temp ,0))>0) //边沿epoll导致需要将其不断循环读出来
    {
        memcpy(buf+total,temp,sizeof temp);
        total += sizeof temp;
        if(total>sizeof buf)
        {
            printf("rescvHTTPRequest error! out length of buf\n");
            break;
        }
    }
    if (len == -1 && errno == EAGAIN)
    {
        printf("data recv finish! data = %s\n",buf);
        parseHTTPRequest("GET /user/floder 1.1",cfd);

    }
    else if( len== 0)
    {
        printf("client offLine\n");
        return -1;
    }
    else
    {
        printf("Unknown error\n");
        return -1;
    }
    return 1;
}

int parseHTTPRequest(const char *line, int cfd)
{
    char type[15];
    char path[1024];
    char *file;
    int res=sscanf(line , "%[^ ] %[^ ] ",type,path);  //利用正则表达式将http表头的第一行取出来
    printf("type = %s  ,path = %s \n",type,path);
    if(strcasecmp(type,"get")==0) //判断表头的类型
    {
        //get类型 
        //将地址转化为相对地址
        if(strcmp(path,"/")==0)
        {
            file="./";
        }
        else
        {
            file=path+1;
        }

        //读取这个文件/夹
        struct stat st;   /////////////
        int res = stat(file,&st);
        if (res == -1)
        {
            printf("404 file is not Found!\n");
            return -1;
        }
        
        if(S_ISDIR(st.st_mode))   /////////////////
        {
            //把文件夹的内容发送给客户端；
            printf("this path is dir! path=%s\n",file);
            
        }
        else
        {
            //把文件的内容发送给客户端；
            printf("this path is file! path=%s\n",file);
        }
    }
    else
    {
        //其他类型
        printf("无法处理的http请求类型\n");
        return -1;
    }

    return 0;
}

int epollRun(int lfd)
{
    //创建epoll实例
    int epfd=epoll_create(1);
    if(epfd==-1)
    {
        printf("epoll_create error !\n");
        return -1;
    }

    //将lfd添加到epoll里面的红黑树当中
    struct epoll_event ev;
    ev.data.fd=lfd;
    ev.events=EPOLLIN;
    int res=epoll_ctl(epfd,EPOLL_CTL_ADD,lfd,&ev);
    if(res==-1)
    {
        printf("epoll_ctl error !\n");
        return -1;
    }


    struct epoll_event events[1024];
    int size=sizeof(events) / sizeof(struct epoll_event);
    //开始检测有无事件发生
    while (1)
    {
        //epoll检测
        printf("epoll 开始等待！\n");
        int num=epoll_wait(epfd,events,size,-1);
        for(int i=0;i<num;i++)
        {
            if(events[i].data.fd == lfd)
            {
                //连接客户端
                res = connectClient(lfd,epfd);
            }
            else
            {
                //客户端的数据交流
                res=rescvHTTPRequest(events[i].data.fd , epfd);
            }
        }
    }
    

    return 0;
}
