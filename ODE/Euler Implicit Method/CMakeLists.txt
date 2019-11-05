cmake_minimum_required(VERSION 3.13)
project("Implicit Euler Method in C")

set(CMAKE_C_STANDARD 11)

add_executable(Implicit_Euler main.c euler.c)