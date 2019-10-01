cmake_minimum_required(VERSION 3.13)
project("Integration with Simpson's 3/8 Rule in C")

set(CMAKE_C_STANDARD 11)

add_executable(Three_Eighths_Rule main.c threeeighths.c)