#include "euler.h"
#include <stdio.h>
#include <stdlib.h>

void iterate_explicit(size_t n, double y[n], double (*f)(double y, double x),
                      double a, double h) {
  size_t i;
  double x = a;
  for (i = 0; i < n; i++, x += h) {
    y[i + 1] = y[i] + h * f(y[i], x);
  }
}