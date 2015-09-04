cmake_minimum_required(VERSION 3.0)
project(wordsMorph)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/converter.cpp
    src/converter.h
    src/hlpr.h
    src/main.cpp
    src/utest.cpp
    src/utest.h)

add_executable(wordsMorph ${SOURCE_FILES})