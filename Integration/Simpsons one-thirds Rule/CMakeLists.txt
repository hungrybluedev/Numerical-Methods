cmake_minimum_required(VERSION 3.13)
project("Integration with Simpson's 1/2 Rule in C")

set(CMAKE_C_STANDARD 11)

add_executable(One_Thirds_Rule main.c onethirds.c)