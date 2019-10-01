cmake_minimum_required(VERSION 3.13)
project("Integration with Trapezoidal Rule in C")

set(CMAKE_C_STANDARD 11)

add_executable(Trapezoidal_Rule main.c trapezoidal.c)