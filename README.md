# Numerical Methods in C

## Introduction

This repository contains implementations of different numerical algorithms. All of the implementation is in C (unfortunately), because our professor is proficient in only that language for some reason. However, I've tried my best to make the implementations as readable and accessible as possible. All of the algorithms are self contained in their own directories with their own CMakeLists.txt.

## Usage

1. Clone the repository.
2. `cd` into the directory that you want.
3. Build with CMake.
    - Make sure that you have CMake installed.
    - From the directory of the implementation, run `mkdir build && cd build` (or whatever you want your build directory to be)
    - Run `cmake -G "Unix Makefiles" ..`
    - Rune `make`
    - You should have an executable with the same name as the Algorithm. Run it normally as you would on the command line.

## Links to the Algorithms

I'll be adding links to the Algorithms as I go on implementing them.

### Root Finding

1. [Bisection Method](https://github.com/hungrybluedev/Numerical-Methods/tree/master/Root%20Finding/Bisection%20Method)
2. [Regula-Falsi Method](https://github.com/hungrybluedev/Numerical-Methods/tree/master/Root%20Finding/Regula-Falsi%20Method)

## Contact

In case of any problems, you may find me on Twitter ([@HungryBlueDev](https://twitter.com/hungrybluedev)).