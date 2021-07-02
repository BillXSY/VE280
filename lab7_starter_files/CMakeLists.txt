cmake_minimum_required(VERSION 3.16)
project(lab7_starter_files)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab7_starter_files
        simpletest.cpp
        course.cpp
        course.h)
