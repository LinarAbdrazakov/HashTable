cmake_minimum_required(VERSION 3.8)
project(Task)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp HashTable.h HashTable.cpp)
add_executable(Task ${SOURCE_FILES})