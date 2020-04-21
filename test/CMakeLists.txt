cmake_minimum_required(VERSION 3.12)
project(swoole_test)

set(CMAKE_CXX_STANDARD 11)

add_executable(swoole_test demo38.cpp)
#target_link_libraries(swoole_test pthread)