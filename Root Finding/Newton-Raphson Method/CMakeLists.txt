cmake_minimum_required(VERSION 3.13)
project(Newton_Raphson_Method C)

set(CMAKE_C_STANDARD 11)

add_executable(Newton_Raphson_Method
        main.c
        newtonraphson.c
        newtonraphson.h)

target_link_libraries(Newton_Raphson_Method m)
