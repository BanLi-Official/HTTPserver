cmake_minimum_required(VERSION 3.28.2)
project(src)

# 设置C编译器标准为GNU C11


aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} source)

set(EXECUTABLE_OUTPUT_PATH ${output})

add_executable(main ${source})
