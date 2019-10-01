# Bisection Method

## Introduction

The bisesction method is one of the simplest methods of root finding. It is
very similar to Binary Search in it's principle. Just like the pre-requisite
for the search is that the data needs to be sorted, bisection method needs
the function to be continuous and that the function cut the x-axis (i.e. have
a guaranteed zero) in the specified interval.

The condition that is checked is whether the function attains values of
opposing parity (i.e. one is negative, another is positive) at the end points.

## Pseudocode


### Inputs:
1. a   - the lower bound of the interval to search in.
2. b   - the upper bound of the interval to search in.
3. f   - the function whose zeero is sought
4. eps - the tolerance value.
5.n    - pointer to the storage for number of iteraions.

### Output:

The zero of the function in the given interval provided it exists.


### Algorithm:

1. Verify that f(a) * f(b) < 0. If not, exit/ask for input again.
2. Let c := (a + b) / 2.
3. If abs(f(c)) < eps, we are done. Return c.
4. If f(a) * f(c) < 0, let b := c.
5. If f(c) * f(b) < 0, let a := c.
6. Increment the number of iterations.
7. Goto step 2.
