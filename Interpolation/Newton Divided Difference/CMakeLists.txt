cmake_minimum_required(VERSION 3.14)
project(Newton_Divided_Difference C)

set(CMAKE_C_STANDARD 11)

add_executable(Newton_Divided_Difference
        newton.c
        newton.h
        main.c)
