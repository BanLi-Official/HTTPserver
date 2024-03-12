cmake_minimum_required(VERSION 3.28.2)
project(src)

# 设置C编译器标准为GNU C11


aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} source)

set(EXECUTABLE_OUTPUT_PATH ${output})

find_package(Threads REQUIRED)   #Threads 变量会根据操作系统和CMake版本的不同，自动选择适用的线程库进行查找和链接。
                                 #如果 REQUIRED 被设置为 REQUIRED，那么在找不到指定的包时，CMake 将产生一个致命错误，并终止构建过程。

add_executable(main ${source})
target_link_libraries(main Threads::Threads)