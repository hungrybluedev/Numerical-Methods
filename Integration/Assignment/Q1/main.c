#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "onethirds.h"
#include "threeeighths.h"
#include "trapezoidal.h"

#define DIGITS "10"

double f(double x) { return 4 / (1 + x * x); }

int main() {
  double pi = M_PI;
  double a = 0, b = 1;
  size_t intervals[] = {10, 20};
  size_t index;

  for (index = 0; index < sizeof(intervals) / sizeof(size_t); index++) {
    size_t n = intervals[index];
    printf("Number of intervals : %zu\n", n);
    double result = tr_integrate(f, a, b, n);
    printf("TR: %." DIGITS "lf, %." DIGITS "lf\n", result, fabs(result - pi));
    result = ot_integrate(f, a, b, n);
    printf("OT: %." DIGITS "lf, %." DIGITS "lf\n", result, fabs(result - pi));
    result = te_integrate(f, a, b, n);
    printf("TE: %." DIGITS "lf, %." DIGITS "lf\n", result, fabs(result - pi));
  }
  return EXIT_SUCCESS;
}