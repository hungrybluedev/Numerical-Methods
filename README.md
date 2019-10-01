# Numerical Methods in C

![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/hungrybluedev/Numerical-Methods)
![GitHub](https://img.shields.io/github/license/hungrybluedev/Numerical-Methods)
![GitHub top language](https://img.shields.io/github/languages/top/hungrybluedev/Numerical-Methods)

## Introduction

This repository contains implementations of different numerical algorithms. All of the implementation is in C (unfortunately), because our professor is proficient in only that language for some reason. However, I've tried my best to make the implementations as readable and accessible as possible. All of the algorithms are self contained in their own directories with their own CMakeLists.txt.

## Usage

1. Clone the repository.
2. `cd` into the directory that you want.
3. Build with CMake.
    - Make sure that you have CMake installed.
    - From the directory of the implementation, run `mkdir build && cd build` (or whatever you want your build directory to be)
    - Run `cmake -G "Unix Makefiles" ..`
    - Run `make`
    - You should have an executable with the same name as the Algorithm. Run it normally as you would on the command line.

## Links to the Algorithms

I'll be adding links to the Algorithms as I go on implementing them.

### Root Finding

1. [Bisection Method](https://github.com/hungrybluedev/Numerical-Methods/tree/master/Root%20Finding/Bisection%20Method)
2. [Regula-Falsi Method](https://github.com/hungrybluedev/Numerical-Methods/tree/master/Root%20Finding/Regula-Falsi%20Method)
3. [Secant Method](https://github.com/hungrybluedev/Numerical-Methods/tree/master/Root%20Finding/Secant%20Method)
4. [Newton-Raphson Method](https://github.com/hungrybluedev/Numerical-Methods/tree/master/Root%20Finding/Newton-Raphson%20Method)

### Interpolation

1. [Lagrange Interpolation](https://github.com/hungrybluedev/Numerical-Methods/tree/master/Interpolation/Lagrange%20Polynomial%20Method)
2. [Newton's method of Forward and Backward Differences](https://github.com/hungrybluedev/Numerical-Methods/tree/master/Interpolation/Newton%20Divided%20Difference)
3. [Hermite Interpolation](https://github.com/hungrybluedev/Numerical-Methods/tree/master/Interpolation/Hermite%20Interpolation)

### Numeric Integration

1. Trapezoidal Rule
2. Simpson's 1/3rd rule
3. Simpson's 3/8th rule

## Contact and Support

In case of any problems, you may find me on Twitter ([@HungryBlueDev](https://twitter.com/hungrybluedev)).

![Twitter Follow](https://img.shields.io/twitter/follow/hungrybluedev?style=social)

If you feel that my work has been helpful to you and maybe you're in the mood to give then you may make a small donation to me on PayPal, or become a regular supporter on Patreon.

[![PayPal - HungryBlueDev](https://img.shields.io/badge/PayPal-HungryBlueDev-blue)](https://www.paypal.me/hungrybluedev)
[![Become a Patreon!](https://img.shields.io/badge/Patreon-HungryBlueDev-red)](https://www.patreon.com/bePatron?u=24185563)
