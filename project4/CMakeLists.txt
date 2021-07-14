cmake_minimum_required(VERSION 3.16)
project(project4)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(project4
        BinaryTree.cpp
        BinaryTree.h
        NodeInfo.h
        dbc.cpp)
