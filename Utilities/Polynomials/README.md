# Polynomials Utility

## Introduction

This is a little utility project aimed at expediting the process of
generating data points for custom polynomials. It absolutely beats
writing out a polynomial on paper and calculating the various values
the function takes at different points.

## Usage

### 1. Edit the sources

The desired polynomial to be used is entered in the `polynomial.c` file.
Depending on whether the derivative of the polynomial is also necessary,
you can edit the `f_prime` function. This bit has to be done on paper.

After the polynomials have been entered, the method of printing the
data can be changed by changing the `print_line` function in `main.c`.
Here, `f_prime` can be left out if it not necessary.

More adjustments can be made if necessary, like automating the assignement
of values for `x`. I've left them as is because I have had no need for
too many data points yet.

### 2. Compile

Follow the [general instructions](https://github.com/hungrybluedev/Numerical-Methods/blob/master/README.md)
for compiling this CMake project and run the executable.