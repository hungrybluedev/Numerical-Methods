cmake_minimum_required(VERSION 3.14)
project(Lagrange_Polynomial_Method C)

set(CMAKE_C_STANDARD 11)

add_executable(Lagrange_Polynomial_Method
        lagrange.c
        main.c)
