cmake_minimum_required(VERSION 3.22.2)
project(httpReactor)

set(CMAKE_CXX_STANDARD 11)  #设置支持c++11
set(CMAKE_CXX_STANDARD_REQUIRED ON)  #设置编译器必须支持C++
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")  
#add_compile_options(-std=c++11)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -/usr/include/c++/9")
#include_directories(/usr/include/c++/9)
#include_directories(/usr/include/x86_64-linux-gnu/c++/9)


set(output ${CMAKE_CURRENT_SOURCE_DIR}/output)
set(lib ${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_subdirectory(src)