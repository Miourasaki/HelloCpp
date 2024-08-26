cmake_minimum_required(VERSION 3.28)
project(HelloCpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(HelloCpp main.cpp
        lib/IrisLog/IrisLog.cpp
        lib/IrisLog/IrisLog.h
        HelloWorld/main.cpp
        main.h
        ChernoCpp/main.cpp
        ChernoCpp/test.cpp
)