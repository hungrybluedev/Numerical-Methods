#ifndef BISECTION_H
#define BISECTION_H

#include <stddef.h>

/**
 * Applies the bisection method of root finding to find a zero of the provided
 * function f.
 *
 * NOTE: This function assumes that the initial criteria for a valid interval
 * has been met. That is, f(a) * f(b) < 0, or the function has opposite signs
 * at the two bounds. By the Intermediate Value Theorem, it will then be
 * guaranteed that the function f has at least 1 zero between a and b.
 *
 * @param a         The lower bound of the interval to search in.
 * @param b         The upper bound of the interval to search in.
 * @param f         The function whose zero is sought.
 * @param eps       The permissible error in the final result.
 * @param n         The pointer in which the number of iterations required will
 *                  be stored.
 * @param silent    Should intermediate results be hidden?
 * @return The zero of a function in the given interval when guaranteed it
 * exists.
 */
double bisection(double a, double b, double (*f)(double), double eps, size_t *n,
                 bool silent);

#endif