#pragma once


//定义函数指针 handleFunc 是一个指针类型，它可以指向一个接受 void* 类型的参数并返回 int 类型的函数。在C++11之后的标准里，推荐使用using关键字来定义别名
//typedef int (*handleFunc)(void *arg);
using handleFunc = int(*)(void*);


//不使用"class"关键字创建的枚举类只能在全局作用域内使用，枚举值会被隐式转换为整数类型，存在一定的类型安全隐患。
//"enum class"创建的枚举类的枚举值在类作用域内
enum class FDevent
{
    TimeOut=0x01,
    WriteAble=0x02,
    ReadAble=0x04
};

//封装fd与其回调函数到Channel中
class Channel  
{
public:
    //构造函数,初始化函数
    Channel(int fd , FDevent event ,handleFunc readFunc ,handleFunc writeFunc ,handleFunc destroyCallBack,void *arg);
    //读函数
    handleFunc readCallBack;
    //写函数
    handleFunc writeCallBack;
    //释放arg的内存
    handleFunc destroyCallBack; 
    //获取私有成员内容
    inline int getFD(){return m_fd;}
    inline int getEvent(){return m_event;}
    inline const void* getArg(){return m_arg;}

    //设置写函数是否有效函数
    int setWriteable(bool flag);
    //判断写函数是否有效函数
    bool checkWriteable();

private:
    //文件描述符
    int m_fd;
    //读写事件标志
    int m_event;
    //读写函数的参数
    void * m_arg;
};



