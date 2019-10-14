#include "trapezoidal.h"

double integrate(double (*f)(double), double a, double b, size_t n) {
  double sum = f(a) + f(b);
  double gap = (b - a) / n;

  size_t index;
  for (index = 1; index < n; index++) {
    sum += 2 * f(a + gap * index);
  }

  return gap * sum / 2;
}