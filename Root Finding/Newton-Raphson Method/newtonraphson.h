#ifndef BISECTION_H
#define BISECTION_H

#include <stddef.h>
#include <stdbool.h>

/**
 * Applies the Newton-Raphson method of root finding to find a zero of the
 * provided function f.
 *
 * NOTE: This function requires both the f and the f_prime (i.e. the first
 * derivative) to be defined in order to work. In case the function is updated,
 * the user should also update the derivative function.
 *
 * @param initial   The starting guess which will be refined in each iteration.
 * @param f         The function whose zero is sought.
 * @param f_prime   The derivative of f.
 * @param eps       The permissible error in the final result.
 * @param n         The pointer in which the number of iterations required will
 * be stored.
 * @param silent    Should intermediate results be hidden?
 * @return The zero of a function in the given interval when guaranteed it
 * exists.
 */
double newton_raphson(double initial, double (*f)(double),
                      double (*f_prime)(double), double eps, size_t *n,
                      bool silent);

#endif