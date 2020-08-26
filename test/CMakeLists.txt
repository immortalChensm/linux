cmake_minimum_required(VERSION 3.12)
project(thread10)

set(CMAKE_CXX_STANDARD 11)
set(SRC_LIST async.cpp)
add_executable(test ${SRC_LIST})
#target_link_libraries(swoole_test pthread)