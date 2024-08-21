cmake_minimum_required(VERSION 3.28)
project(HelloCpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS -static)

add_executable(HelloCpp main.cpp
        lib/IrisLog/IrisLog.cpp
        lib/IrisLog/IrisLog.h
        HelloWorld/main.cpp
        main.h
        qttest/main.cpp
        ChernoCpp/main.cpp
)
