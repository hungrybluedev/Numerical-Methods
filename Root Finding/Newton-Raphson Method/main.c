#include "newtonraphson.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

double f(double x) { return 5 * pow(x, 3) - 4 * pow(x, 2) + 3 * x - 19; }

double f_prime(double x) { return 15 * pow(x, 2) - 8 * x + 3; }

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"

double input_error() {
  double eps;
  while (true) {
    printf("Enter the tolerance : ");
    scanf("%lf", &eps);
    if (eps > 1e-15) {
      return eps;
    }
    if (eps < 0) {
      printf("Tolerance must be positive. Try again.\n\n");
    } else {
      printf("Tolerance value too low. Try again.\n\n");
    }
  }
}

int main() {
  double initial;
  size_t n;

  printf("Enter initial guess : ");
  scanf("%lf", &initial);

  double eps = input_error();

  double ans = newton_raphson(initial, f, f_prime, eps, &n, false);

  printf("Answer : %.5lf\nIterations : %zu\n", ans, n);

  return 0;
}

#pragma clang diagnostic pop
