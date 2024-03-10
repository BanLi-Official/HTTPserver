cmake_minimum_required(VERSION 3.28.2)
project(http_C)

# 设置C编译器标准为GNU C11


set(output ${CMAKE_CURRENT_SOURCE_DIR}/output)


add_subdirectory(src)
add_subdirectory(client)