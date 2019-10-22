cmake_minimum_required(VERSION 3.13)
project("Gaussian Elimination in C")

set(CMAKE_C_STANDARD 11)

add_executable(Gaussian_Elimination main.c nopivot.c partialpivot.c matrix.c)