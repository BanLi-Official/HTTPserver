#include "server.h"
#include <arpa/inet.h>
#include <stdio.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/sendfile.h>
#include <assert.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <pthread.h>

int initListenFd(unsigned short port)
{
    // 创建监听fd
    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    if (lfd == -1)
    {
        printf("socket error!\n");
        return -1;
    }
    // 设置端口复用
    int apt = 1;
    int res = setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &apt, sizeof(apt)); // 该套接字完成关闭后，即使还有其他套接字仍然在使用它绑定的地址和端口，新的套接字仍然可以绑定到相同的地址和端口上。
    if (res == -1)
    {
        printf("setsockopt error!\n");
        return -1;
    }
    // 绑定
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    res = bind(lfd, (struct sockaddr *)&addr, sizeof(struct sockaddr));
    if (res == -1)
    {
        printf("bind error!\n");
        return -1;
    }
    // 监听
    res = listen(lfd, 128);
    if (res == -1)
    {
        printf("listen error!\n");
        return -1;
    }
    // 返回
    //printf("initListenFd 初始化监听套接字成功\n");
    return lfd;
}

int connectClient(int lfd, int epfd)
{
    if (lfd == -1)
    {
        printf("connectClient error ! , lfd is NULL\n");
        return -1;
    }
    // 接收传来的连接
    struct sockaddr_in add;
    int size = sizeof(add);
    int cfd = accept(lfd, (struct sockaddr *)&add, (socklen_t *)&size);
    // int cfd = accept(lfd,NULL,NULL);
    if (cfd == -1)
    {
        printf("connectClient error ! , accept  error\n");
        return -1;
    }
    // 将连接设置为非阻塞状态
    int flag = fcntl(cfd, F_GETFL);
    flag |= O_NONBLOCK;
    int res = fcntl(cfd, F_SETFL, flag);
    if (res == -1)
    {
        printf("connectClient error ! , fcntl  error\n");
        return -1;
    }

    // 将这个连接放入epoll中
    struct epoll_event ev;
    ev.data.fd = cfd;
    ev.events = EPOLLIN | EPOLLET;
    res = epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &ev);
    if (res == -1)
    {
        printf("connectClient error ! , epoll_ctl EPOLL_CTL_ADD error\n");
        return -1;
    }

    //printf("成功添加socket客户连接：%s , 端口为：%d\n", inet_ntoa(add.sin_addr), ntohs(add.sin_port));
    return 0;
}

int rescvHTTPRequest(int cfd, int epfd)
{
    if (cfd == -1 || epfd == -1)
    {
        printf("rescvHTTPRequest error! cfd || epfd IS NULL\n");
        return -1;
    }

    char buf[4096] = {0};
    char temp[1024] = {0};
    int len;
    int total = 0;
    while ((len = recv(cfd, temp, sizeof temp, 0)) > 0) // 边沿epoll导致需要将其不断循环读出来，在这里不需要完全存入缓冲区也可以，因为只需要http 请求的头一行
    {
        memcpy(buf + total, temp, sizeof temp);
        total += sizeof temp;
        if (total > sizeof buf)
        {
            printf("rescvHTTPRequest error! out length of buf\n");
            // break;
        }
    }
    if (len == -1 && errno == EAGAIN)
    {
        // 找到第一行的结尾
        char *point = strstr(buf, "\r\n");
        int index = point - buf; // 找到差的长度
        // 在第一行结尾设置一个/0，因为只需要第一行
        buf[index] = '\0';
        //printf("data recv finish! data = %s\n", buf);
        // parseHTTPRequest("GET /user/floder 1.1",cfd);  //这里后期要修改为buf内容
        parseHTTPRequest(buf, cfd); // 这里后期要修改为buf内容
    }
    else if (len == 0)
    {
        //printf("client offLine\n");
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
    int res = sscanf(line, "%[^ ] %[^ ] ", type, path); // 利用正则表达式将http表头的第一行取出来
    //printf("type = %s  ,path = %s \n", type, path);
    DecodeMsg(path,path);
    //printf("type = %s  ,path = %s \n", type, path);
    if (strcasecmp(type, "get") == 0) // 判断表头的类型
    {
        // get类型
        // 将地址转化为相对地址
        if (strcmp(path, "/") == 0)
        {
            file = "./";
        }
        else
        {
            file = path + 1;
        }

        // 读取这个文件/夹
        struct stat st;
        int res = stat(file, &st);
        if (res == -1)
        {
            //printf("404 file is not Found!\n");
            sendHeadResponse(cfd, 404, "Not Found!", getFileType(".html"), -1);
            sendFile(cfd, "404.html");
            return -1;
        }

        if (S_ISDIR(st.st_mode))
        {
            // 把文件夹的内容发送给客户端；
            //printf("this path is dir! path=%s\n", file);
            sendHeadResponse(cfd, 200, "OK", getFileType(".html"), -1);
            sendDir(cfd, file);
        }
        else
        {
            // 把文件的内容发送给客户端；
            //printf("this path is file! path=%s  st_size = %d\n  ", file,(int)st.st_size);
            sendHeadResponse(cfd, 200, "OK", getFileType(file), st.st_size);
            sendFile(cfd, file);
        }
    }
    else
    {
        // 其他类型
        printf("无法处理的http请求类型\n");
        return -1;
    }

    return 0;
}

int sendFile(int cfd, const char *file)
{
    //printf("file send start\n");
    if (cfd == -1)
    {
        printf("sendFile Error ! cfd unknown\n");
        return -1;
    }
    int fd = open(file, O_RDONLY);
    assert(fd > 0); // 加个断言，判断文件成功打开

#if 0
    //常规方法
    char buf[1024] = { 0 };
    int len=read(fd , buf ,sizeof buf);
    while (len > 0)
    {
        
        usleep(10);  //中间空出点时间，掌握好发送节奏
        send(cfd,buf,sizeof buf ,0);
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
        return -1;
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
    return 0;
}

int sendHeadResponse(int cfd, int state, const char *destribe, const char *ContentType, int length)
{
    
    if (cfd == -1)
    {
        printf("sendHeadResponse ERROR ! cfd unknown\n");
        return -1;
    }
    char head[2048] = {0};
    sprintf(head, "HTTP/1.1 %d %s\r\n", state, destribe);
    sprintf(head + strlen(head), "Content-Type:%s\r\n", ContentType);
    sprintf(head + strlen(head), "Content_Length:%d\r\n\r\n", length);

    send(cfd, head, strlen(head), 0);
    //printf("headResponse send end ,ContentType=%s\n",ContentType);
    return 0;
}

int epollRun(int lfd)
{
    // 创建epoll实例
    int epfd = epoll_create(1);
    if (epfd == -1)
    {
        printf("epoll_create error !\n");
        return -1;
    }

    // 将lfd添加到epoll里面的红黑树当中
    struct epoll_event ev;
    ev.data.fd = lfd;
    ev.events = EPOLLIN;
    int res = epoll_ctl(epfd, EPOLL_CTL_ADD, lfd, &ev);
    if (res == -1)
    {
        printf("epoll_ctl error !\n");
        return -1;
    }

    struct epoll_event events[1024];
    int size = sizeof(events) / sizeof(struct epoll_event);
    // 开始检测有无事件发生
    while (1)
    {
        // epoll检测
        //printf("epoll 开始等待！\n");
        int num = epoll_wait(epfd, events, size, -1);
        for (int i = 0; i < num; i++)
        {
            if (events[i].data.fd == lfd)
            {
                // 连接客户端
                res = connectClient(lfd, epfd);
            }
            else
            {
                // 客户端的数据交流
                res = rescvHTTPRequest(events[i].data.fd, epfd);
            }
        }
    }

    return 0;
}

const char *getFileType(const char *name)
{
    // a.jpg a.mp4 a.html
    // 自右向左查找‘.’字符, 如不存在返回NULL
    const char *dot = strrchr(name, '.');
    if (dot == NULL)
        return "text/plain; charset=utf-8"; // 纯文本
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
    if (strcmp(dot, ".mp4") ==0)
        return "video/mpeg4";

    return "text/plain; charset=utf-8";
}

int compare(const struct dirent **a, const struct dirent **b)
{
    return strcoll(((struct dirent **)a)[0]->d_name, ((struct dirent **)b)[0]->d_name);
}

int sendDir(int cfd, const char *Dir) // 发送的是一个html文件的内容
{
    if (cfd == -1)
    {
        printf("sendDir ERROR! cfd is unknown!");
        return -1;
    }

    char html[4096] = {0};
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
        free(namelist[i]);
    }
    // 补充html文件剩下的内容
    sprintf(html + strlen(html), "</table></body></html>");
    send(cfd, html, strlen(html), 0);
    free(namelist);
    return 0;
}

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

void DecodeMsg(char *from, char *to)
{
    for(;from[0] != '\0';from++,to++)
    {
        //printf("from[0]=%c\n",from[0]);
        if(from[0] == '%' && from[1]!='\0' && from[2]!='\0')
        {
            to[0]=hexToDec(from[1])*16+hexToDec(from[2]); //检测到%E2%A1这一类的编码则转为中文
            from=from+2;
        }
        else
        {
            to[0]=from[0];
        }
    }
    to[0]=from[0];
}
