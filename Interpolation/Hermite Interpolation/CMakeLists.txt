cmake_minimum_required(VERSION 3.14)
project(Hermite_Interpolation C)

set(CMAKE_C_STANDARD 11)

add_executable(Hermite_Interpolation
        hermite.c
        main.c)
