#include "euler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double f(double y, double x) { return -1000 * (y - (x + 2)) + 1; }

int main() {
  double a = 0, b = 0.01;
  double h = 0.002;

  size_t n = (size_t)((b - a) / h);
  printf("%zu\n", n);
  double *y = malloc(n * sizeof(double));

  // Setting the initial value.
  y[0] = 0;
  iterate_explicit(n, y, f, a, h);

  printf("%lf\n", y[n - 1]);

  return EXIT_SUCCESS;
}