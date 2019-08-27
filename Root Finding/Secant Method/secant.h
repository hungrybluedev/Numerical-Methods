#ifndef SECANT_H
#define SECANT_H

#include <stddef.h>

/**
 * Applies the Secant method of root finding to find a zero of the provided
 * function f.
 *
 * NOTE: This method requires that the initial guesses be "different" i.e the
 * absolute value of their difference is greater than the tolerance.
 *
 * @param x0        The guess before x1.
 * @param x1        The previous guess or approximation.
 * @param f         The function whose zero is sought.
 * @param eps       The permissible error in the final result.
 * @param n         The pointer in which the number of iterations required will be stored.
 * @param silent    Should intermediate results be hidden?
 * @return The zero of a function in the given interval when guaranteed it exists.
 */
double secant(
        double x0,
        double x1,
        double (*f)(double),
        double eps,
        size_t *n,
        bool silent
);

#endif