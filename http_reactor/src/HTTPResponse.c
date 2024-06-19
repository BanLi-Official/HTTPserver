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


struct httpResponse *httpResponseInit()
{
    struct httpResponse* response = (struct httpResponse*)malloc(sizeof(struct httpResponse));

    //状态行
    response->stateCode=Unknown;
    bzero(response->statusMsg,sizeof(response->statusMsg));
    bzero(response->fileName,sizeof(response->fileName));

    //键值对行
    response->headers=(struct httpHeader *)malloc(sizeof(struct httpHeader )*maxHeadersNum);
    response->headersNum=0;
    bzero(response->headers,sizeof(struct httpHeader )*maxHeadersNum);

    //回调函数
    response->sendDataFunc=NULL;

    return response;
}

void destroyHttpResponse(struct httpResponse *response)
{
    if(response!=NULL)
    {
        free(response->headers);
        free(response);
    }
}

bool addHttpResponseHeader(struct httpResponse *response, const char *key, const char *value)
{
    if(response==NULL || key==NULL || value==NULL)
    {
        return false;
    }

    strcpy(response->headers[response->headersNum].key , key);
    strcpy(response->headers[response->headersNum].value , value);
    response->headersNum++;


    return true;
}

void httpResponsePrepareMsg(struct httpResponse *response, struct buffer *sendBuffer, int socket)
{
    //声明一个临时的数组用于存放组织的内容
    char temp[2048]={0};
    //状态行
    sprintf(temp,"HTTP %d %s\r\n",response->stateCode,response->statusMsg);
    writeStringIntoBuffer(sendBuffer,temp);

    //键值对头
    for(int i=0;i<response->headersNum;i++)
    {
        sprintf(temp,"%s:%s\r\n",response->headers[i].key,response->headers[i].value);
        writeStringIntoBuffer(sendBuffer,temp);
    }

    //空行
    writeStringIntoBuffer(sendBuffer,"\r\n");

    //数据块
    response->sendDataFunc(response->fileName,sendBuffer,socket);
}




void sendFile(const char* fileName,struct buffer* buffer,int socket)
{

    int fd = open(fileName, O_RDONLY);
    assert(fd > 0); // 加个断言，判断文件成功打开

#if 1
    //常规方法
    char buf[1024] = { 0 };
    int len=read(fd , buf ,sizeof buf);
    while (len > 0)
    {
        
        usleep(10);  //中间空出点时间，掌握好发送节奏
        // send(cfd,buf,sizeof buf ,0);
        //将数据传到buffer中
        writeMsgIntoBuffer(buffer,buf,len);
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


int compare(const struct dirent **a, const struct dirent **b)
{
    return strcoll(((struct dirent **)a)[0]->d_name, ((struct dirent **)b)[0]->d_name);
}


void sendDir(const char* Dir,struct buffer* buffer,int socket) // 发送的是一个html文件的内容
{
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
    //send(cfd, html, strlen(html), 0);
    //将buf中的内容传递到待发送区域Buffer中
    writeStringIntoBuffer(buffer,html);
    free(namelist);

}
