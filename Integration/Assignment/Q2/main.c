#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "onethirds.h"

#define EPS .000005
#define DIGITS "7"

typedef double (*f)(double);

double f1(double x) { return 1 / (1 + x * x); }
double f2(double x) { return sqrt(1 - x * x) - x; }

int main() {
  f p[] = {f1, f2};
  double a[] = {0, 0};
  double b[] = {1, 1.0 / sqrt(2.0)};
  size_t index;
  for (index = 0; index < sizeof(p) / sizeof(f); index++) {
    size_t n = 3;
    double result = integrate(p[index], a[index], b[index], n), last;
    do {
      n += 2;
      last = result;
      result = integrate(p[index], a[index], b[index], n);
    } while (fabs(last - result) > EPS);
    printf("%zu : %." DIGITS "lf, %zu\n", (index + 1), result, n);
  }

  return EXIT_SUCCESS;
}