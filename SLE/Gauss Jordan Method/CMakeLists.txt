cmake_minimum_required(VERSION 3.13)
project("Gauss Jordan in C")

set(CMAKE_C_STANDARD 11)

add_executable(Gauss_Jordan main.c gaussjordan.c matrix.c)