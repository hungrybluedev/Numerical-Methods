#include "onethirds.h"

double integrate(double (*f)(double), double a, double b, size_t n) {
  double sum = f(a) + f(b);
  double gap = (b - a) / n;

  size_t index;
  for (index = 1; index < n; index++) {
    double fx = f(a + index * gap);
    sum += (index % 2 ? 4 : 2) * fx;
  }

  return gap * sum / 3;
}