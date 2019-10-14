cmake_minimum_required(VERSION 3.13)
project("Assignment_7_Q2")

set(CMAKE_C_STANDARD 11)

add_executable(Q2 main.c onethirds.c)

target_link_libraries(Q2 m)
