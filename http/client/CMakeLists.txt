cmake_minimum_required(VERSION 3.28.2)
project(client)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} source)

set(EXECUTABLE_OUTPUT_PATH ${output})

add_executable(client ${source})