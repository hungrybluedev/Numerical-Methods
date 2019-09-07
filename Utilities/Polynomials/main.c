#include "polynomial.h"
#include <stdio.h>

void print_line(double x, double y, double dy) {
  printf("{%.2lf, %15.7lf, %15.7lf},\n", x, y, dy);
}

int main() {
  double data[] = {1, 2, 3, 4, 2.5, 1.7, 2.3, 3.9};
  size_t i, n = sizeof(data) / sizeof(double);
  for (i = 0; i < n; i++) {
    double x = data[i];
    print_line(x, f(x), f_prime(x));
  }
  return 0;
}