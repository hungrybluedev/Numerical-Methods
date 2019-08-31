#include "data.h"
#include <stddef.h>

double L(size_t n, double x, size_t index, Data *data) {
  double product = 1, x_index = data[index].x;
  size_t i;
  for (i = 0; i < n; i++) {
    if (i == index)
      continue;
    product *= (x - data[i].x) / (x_index - data[i].x);
  }
  return product;
}

double lagrange_interpolate(double x, size_t n, Data *data) {
  double value = 0;
  double partial = 1;
  size_t i;
  for (i = 0; i < n; i++) {
    value += L(n, x, i, data) * data[i].y;
  }
  return value;
}
