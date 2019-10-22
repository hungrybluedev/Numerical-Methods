cmake_minimum_required(VERSION 3.13)
project("Jacobi and Seidel Method in C")

set(CMAKE_C_STANDARD 11)

add_executable(Jacobi_And_Seidel_Method main.c jacobi.c seidel.c matrix.c)