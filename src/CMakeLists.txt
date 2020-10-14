cmake_minimum_required(VERSION 3.18)
project(src C)

set(CMAKE_C_STANDARD 11)

add_executable(src
        main.c net.c net.h)
