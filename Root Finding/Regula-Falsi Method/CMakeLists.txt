cmake_minimum_required(VERSION 3.14)
project("Regula-Falsi Method in C")

set(CMAKE_C_STANDARD 11)

add_executable(Regula_Falsi_Method
        main.c
        regulafalsi.c
        regulafalsi.h)
