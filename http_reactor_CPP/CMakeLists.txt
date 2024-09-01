cmake_minimum_required(VERSION 3.22.2)
project(httpReactor)

set(CMAKE_CXX_STANDARD 17)  #设置支持c++11
set(CMAKE_CXX_STANDARD_REQUIRED ON)  #设置编译器必须支持C++
set(output ${CMAKE_CURRENT_SOURCE_DIR}/output)
set(lib ${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_subdirectory(src)