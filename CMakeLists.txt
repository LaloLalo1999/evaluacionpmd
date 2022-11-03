cmake_minimum_required(VERSION 3.23)
project(evaluacionpmd)

set(CMAKE_C_STANDARD 99)

include_directories(.)

add_executable(evaluacionpmd
        archivos/datos.txt
        historico.txt
        library.c
        library.h
        main.c)
