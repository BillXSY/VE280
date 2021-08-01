cmake_minimum_required(VERSION 3.16)
project(lab9_starter_files)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab9_starter_files
        test/simpletest.cpp
        mylist.h
        mylist_impl.h)
