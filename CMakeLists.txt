cmake_minimum_required(VERSION 3.20)

project(cpp_study)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test test.cpp
        p4449.cpp
        p3289.cpp
        p3876.cpp
        p2280.cpp
        p2250.cpp
        p2282.cpp)