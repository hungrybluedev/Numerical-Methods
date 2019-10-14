#ifndef SIMPSONS_THREE_EIGHTHS_H
#define SIMPSONS_THREE_EIGHTHS_H

#include <stddef.h>

/**
 * Performs evaluation of definite integral of the function using
 * Simpson's 1/3 rule.
 *
 * NOTE: This function requires b to be bigger than a. It is expected
 * that the inputs be validated before calling this function.
 *
 * @param f The function to be integrated.
 * @param a The lower bound of integration.
 * @param b The upper bound of integration.
 * @param n The number of sub-intervals to use for integration.
 */
double integrate(double (*f)(double), double a, double b, size_t n);

#endif//SIMPSONS_THREE_EIGHTHS_H