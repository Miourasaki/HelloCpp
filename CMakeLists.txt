cmake_minimum_required(VERSION 3.28)
project(HelloCpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(HelloCpp main.cpp
        log/IrisLog.cpp
        log/IrisLog.h)
