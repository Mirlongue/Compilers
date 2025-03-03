cmake_minimum_required(VERSION 3.29)
project(lib)

set(CMAKE_CXX_STANDARD 20)

add_library(multiply STATIC multiply.cpp)

add_library(divition SHARED divition.cpp)
