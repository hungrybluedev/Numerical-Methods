#ifndef NEWTON_DIFF_H
#define NEWTON_DIFF_H

#include "data.h"
#include <stdbool.h>
#include <stddef.h>
/**
 * Returns the value of the interpolated polynomial using the given points.
 * The user can choose between forward and backward substitution method
 * for Newton's Method of Divided Differences.
 *
 * NOTE: This function assumes that the value of x provided is within the
 * range set by the minimum and maximum values of x in the data provided.
 * The advantage of Newton's method is that a greater accuracy can be achieved
 * by adding new points without discarding the old ones. Forward difference
 * allows addition of points towards the right, backward difference method
 * allows for addition of points towards the left.
 *
 * @param x         The location to evaluate the interpolated polynomial at.
 * @param n         The number of points to be used for interpolation.
 * @param data      The collection of n (x, y) pairs to represent the function.
 * @param forward   Whether forward or backward substitution should be used.
 * @return          The result of evaluating the interpolated polynomial at x.
 */
double newton_interpolate(double x, size_t n, Data *data, bool forward);

#endif // NEWTON_DIFF_H