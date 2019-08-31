#include "data.h"
#include <stddef.h>

/**
 * Calculates the subexpression for the ith location (index) which will
 * be added to the accumulator to get the full result.
 *
 * @param n     The number of points we have to work with.
 * @param x     The point to interpolate the function at.
 * @param index Which subexpression to calculate.
 * @param data  The collection of the n data points.
 * @return      The partial value of the interpolation.
 */
static double L(size_t n, double x, size_t index, Data *data) {
  double product = 1, xi = data[index].x;
  size_t j;
  for (j = 0; j < n; j++) {
    // Skip the given index.
    if (j == index)
      continue;
    double xj = data[j].x;
    product *= (x - xj) / (xi - xj);
  }
  return product;
}

double lagrange_interpolate(double x, size_t n, Data *data) {
  double value = 0;
  size_t i;
  for (i = 0; i < n; i++) {
    value += L(n, x, i, data) * data[i].y;
  }
  return value;
}
