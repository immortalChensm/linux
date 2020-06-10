cmake_minimum_required(VERSION 3.12)
project(swoole_test)

set(CMAKE_CXX_STANDARD 11)
set(SRC_LIST find.cpp)
add_executable(test ${SRC_LIST})
#target_link_libraries(swoole_test pthread)