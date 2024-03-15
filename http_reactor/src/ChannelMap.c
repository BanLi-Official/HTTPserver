#include "ChannelMap.h"
#include <stdlib.h>
#include <string.h>

struct ChannelMap *ChannelMapInit(int size)
{
    struct ChannelMap *map = (struct ChannelMap *)malloc(sizeof(struct ChannelMap));
    map->size=size;
    map->list=(struct Channel**)malloc(sizeof(struct Channel *) * size);
    return map;
}

bool clearChannelMap(struct ChannelMap *map)
{
    //判断是否为空
    if(map!=NULL)
    {
        //循环free
        for(int i=0;i<map->size;i++)
        {
            if(map->list[i]!=NULL)
            {
                free(map->list[i]);
            }
        }
        free(map->list);
        map->list=NULL;
        map->size=0;
    }

    return false;
}

bool reshapeChannelMap(struct ChannelMap *map, int newsize)
{
    if(newsize>map->size)
    {
        int tempsize=map->size;
        //判断应该扩大到什么程度
        while (newsize >tempsize)
        {
            tempsize=tempsize*2;
        }
        //扩大内存
        struct Channel **newptr= realloc(map->list,tempsize*sizeof(struct Channel *));
        if(newptr==NULL)
        {
            return false;
        }
        map->list = newptr;
        memset(&map->list[map->size],0,(tempsize-map->size)*sizeof(struct Channel *));  //&map->list[map->size]第n位的地址，后面赋值为0
        map->size = tempsize;
        
    }
    return true;
}
