cmake_minimum_required(VERSION 3.22.2)
project(src)

set(EXECUTABLE_OUTPUT_PATH ${output})

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} source)

add_executable(main ${source})