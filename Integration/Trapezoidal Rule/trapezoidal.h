#ifndef TRAPEZOIDAL_H
#define TRAPEZOIDAL_H

#include <stddef.h>

/**
 * Performs evaluaion of definite integral of the function using the
 * trapezoidal rule.
 *
 * NOTE: This function requires b to be bigger than a. It is expected
 * that the inputs be validated before calling this function.
 *
 * @param f The function to be integrated.
 * @param a The lower bound of integration.
 * @param b The upper bound of integration.
 * @param n The number of subintervals to use for integration.
 */
double integrate(double (*f)(double), double a, double b, size_t n);

#endif//TRAPEZOIDAL_H