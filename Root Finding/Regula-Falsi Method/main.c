#include "regulafalsi.h"
#include <stdbool.h>
#include <stdio.h>

double f(double x) { return (x - 10) * (x - 44) * (x + 20); }

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"

void input_bounds(double *a, double *b, double (*f)(double)) {
  while (true) {
    printf("Enter the value of a (lower bound) : ");
    scanf("%lf", a);
    printf("Enter the value of b (upper bound) : ");
    scanf("%lf", b);
    if (f(*a) * f(*b) < 0) {
      return;
    }
    printf("Invalid range provided. Try again.\n\n");
  }
}

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

#pragma clang diagnostic pop

int main() {
  double a, b;
  size_t n;

  input_bounds(&a, &b, f);
  double eps = input_error();

  double ans = regula_falsi(a, b, f, eps, &n, false);

  printf("Answer : %.5lf\nIterations : %zu\n", ans, n);

  return 0;
}