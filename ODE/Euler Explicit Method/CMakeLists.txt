cmake_minimum_required(VERSION 3.13)
project("Explicit Euler Method in C")

set(CMAKE_C_STANDARD 11)

add_executable(Explicit_Euler main.c euler.c)