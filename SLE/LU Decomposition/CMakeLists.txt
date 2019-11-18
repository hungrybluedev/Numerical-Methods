cmake_minimum_required(VERSION 3.13)
project("LU Decomposition in C")

set(CMAKE_C_STANDARD 11)

add_executable(LU_Decomposition main.c lud.c matrix.c)