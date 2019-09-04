cmake_minimum_required(VERSION 3.13)
project(Polynomials C)

set(CMAKE_C_STANDARD 11)

add_executable(Polynomials
        main.c
        polynomial.c)

target_link_libraries(Polynomials m)
