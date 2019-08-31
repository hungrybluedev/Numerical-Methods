#ifndef LAGRANGE_H
#define LAGRANGE_H

#include "data.h"
#include <stddef.h>

/**
 * Creates a Lagrange Interpolating polynomial (coefficients are not directly
 * accessible) and returns the result of evaluating the polynomial at the
 * provided point.
 *
 * NOTE: This function assumes that the value of x provided is within the
 * range set by the minimum and maximum values of x in the data provided.
 *
 * @param x     The location to evaluate the interpolated polynomial at.
 * @param n     The number of points to be used for interpolation.
 * @param data  The collection of n (x, y) pairs to represent the function.
 * @return      The result of evaluating the interpolated polynomial at x.
 */
double lagrange_interpolate(double x, size_t n, Data *data);

#endif // LAGRANGE_H