cmake_minimum_required(VERSION 3.14)
project(opmirror C)

set(CMAKE_C_STANDARD 11)

add_executable(opmirror
        main.c net.c net.h protocol.h protocol.c awindib-protocol.h awindlib-protocol.c)

project(packet-dissector C)
set(CMAKE_C_STANDARD 11)

add_executable(packet-dissector packet-dissector.c awindib-protocol.h awindlib-protocol.c)

project(server C)
set(CMAKE_C_STANDARD 11)

add_executable(server server.c net.h net.c protocol.h protocol.c)
