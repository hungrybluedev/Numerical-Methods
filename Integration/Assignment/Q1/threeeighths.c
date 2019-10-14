#include "threeeighths.h"

double te_integrate(double (*f)(double), double a, double b, size_t n) {
  // The number of intervals should be a multiple of 3
  // Otherwise the inaccuracy is too large to ignore.
  size_t num = n % 3 ? 3 * n : n;
  double sum = f(a) + f(b);
  double gap = (b - a) / num;

  size_t index;
  for (index = 1; index < num; index++) {
    double fx = f(a + index * gap);
    sum += (index % 3 ? 3 : 2) * fx;
  }

  return gap * sum * (3.0 / 8.0);
}