cmake_minimum_required(VERSION 3.13)
project(Secant_Method C)

set(CMAKE_C_STANDARD 11)

add_executable(Secant_Method
        main.c
        secant.c
        secant.h)

target_link_libraries(Secant_Method m)