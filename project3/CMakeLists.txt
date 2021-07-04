cmake_minimum_required(VERSION 3.16)
project(project3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(project3
        card.cpp
        card.h
        deck.h
        deck.cpp
        hand.h
        player.h
        rand.cpp
        rand.h
        main.cpp
        hand.cpp
        player.cpp)
