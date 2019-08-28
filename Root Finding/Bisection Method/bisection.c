#include "bisection.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

double bisection(double a, double b, double (*f)(double), const double eps,
                 size_t *n, const bool silent) {
  *n = 0; // better safe than sorry
  double fa = f(a);
  double fb = f(b);

  // Check corner cases first
  if (fabs(fa) < eps) {
    return a;
  }
  if (fabs(fb) < eps) {
    return b;
  }

  while (true) {
    double x = (a + b) / 2;
    double fx = f(x);
    (*n)++; // Increment right after the function call on midpoint

    if (!silent) {
      printf("%2zu %.5lf %.5lf %.5lf %.5lf\n", *n, a, b, x, fx);
    }

    if (fabs(fx) < eps) {
      return x;
    }

    // Chose the interval in which the root lies (from the IVT)
    if (fx * fa < 0) {
      b = x;
      fb = fx;
    } else if (fx * fb < 0) {
      a = x;
      fa = fx;
    }
  }
}
