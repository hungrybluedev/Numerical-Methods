#include "data.h"
#include "lagrange.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N_LIMIT 1000
#define EPS 1e-10

#pragma ide diagnostic ignored "cert-err34-c"

void input_data(size_t n, Data *data, double *min, double *max) {
  size_t i, j;
  // First pass to input all the data
  for (i = 0; i < n; i++) {
    printf("Entry %zu:\nx = ", (i + 1));
    scanf("%lf", &data[i].x);

    // Ensure that the abscissa is unique.
    bool repeating = true;
    while (repeating) {
      repeating = false;
      // Search the previous coordinates to ensure that the
      // abscissa is not present.
      for (j = 0; j < i; j++) {
        if (fabs(data[j].x - data[i].x) < EPS) {
          printf("Repeated abscissa. Not a valid function.\n"
                 "Enter another value for x : ");
          scanf("%lf", &data[i].x);
          repeating = true;
          break;
        }
      }
    }

    printf("y = ");
    scanf("%lf", &data[i].y);
  }
  // Second pass to find the endpoints
  *min = *max = data[0].x;
  for (i = 1; i < n; i++) {
    if (*min > data[i].x) {
      *min = data[i].x;
    }
    if (*max < data[i].x) {
      *max = data[i].x;
    }
  }
}

void input_point_count(size_t *n) {
  printf("Enter the number of points : ");
  scanf("%zu", n);

  while (*n > N_LIMIT || *n == 0) {
    printf("Invalid number of points. Try again.\n");
    printf("Enter the number of points : ");
    scanf("%zu", n);
  }
}

double input_x_in_range(double min, double max) {
  double x;
  printf("Enter the location to interpolate it at : ");
  scanf("%lf", &x);
  while (min > x || max < x) {
    printf("Enter a value in the interval (%.3lf, %.3lf) : ", min, max);
    scanf("%lf", &x);
  }
  return x;
}

int main() {
  size_t n;
  input_point_count(&n);

  Data *data = malloc(sizeof(Data) * n);
  double min, max;
  input_data(n, data, &min, &max);

  double x = input_x_in_range(min, max);

  double ans = lagrange_interpolate(x, n, data);

  printf("f(%.3lf) = %.5lf\n", x, ans);

  return 0;
}
