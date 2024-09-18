cmake_minimum_required(VERSION 3.22.2)
project(src)
set(CMAKE_CXX_STANDARD 11)  #设置支持c++11
set(CMAKE_CXX_STANDARD_REQUIRED ON)  #设置编译器必须支持C++
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")  
set(EXECUTABLE_OUTPUT_PATH ${output})

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} source)

find_package(Threads REQUIRED)

add_executable(main2 ${source})
target_link_libraries(main2 Threads::Threads)