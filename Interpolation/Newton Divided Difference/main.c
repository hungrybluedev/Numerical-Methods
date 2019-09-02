#include "data.h"
#include "newton.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N_LIMIT 1000
#define EPS 1e-10

/**
 * The function that is used to compare two data points on the
 * basis of their abscissa.
 *
 * NOTE: Equality is checked using the EPS tolerance value mentioned.
 *
 * @param a The first data point.
 * @param b The second data point.
 * @return -1 if a < b, 0 if a == b, 1 if a > b
 */
static int cmp_data(const void *a, const void *b) {
  Data *d1 = (Data *)a;
  Data *d2 = (Data *)b;
  double x1 = d1->x;
  double x2 = d2->x;
  double diff = x1 - x2;
  if (fabs(diff) < EPS) {
    return 0;
  }
  if (diff > EPS) {
    return 1;
  } else {
    return -1;
  }
}

static void sort_find_min_max(size_t n, Data *data, double *min, double *max) {
  qsort(data, n, sizeof(Data), cmp_data);
  *min = data[0].x;
  *max = data[n - 1].x;
  printf("Sorting done.\n");
}

static bool is_repeated(size_t i, double x, Data *data) {
  size_t j;
  for (j = 0; j < i; j++) {
    if (fabs(data[j].x - x) < EPS) {
      return true;
    }
  }
  return false;
}

#pragma ide diagnostic ignored "cert-err34-c"
static void input_data(size_t n, Data *data) {
  size_t i;

  for (i = 0; i < n; i++) {
    printf("Entry %zu:\nx = ", (i + 1));
    scanf("%lf", &data[i].x);

    // Ensure that the abscissa is unique.
    bool repeating = is_repeated(i, data[i].x, data);

    while (repeating) {
      printf("Repeated abscissa. Not a valid function.\n"
             "Enter another value for x : ");
      scanf("%lf", &data[i].x);
      repeating = is_repeated(i, data[i].x, data);
    }

    printf("y = ");
    scanf("%lf", &data[i].y);
  }
}

static void input_point_count(size_t *n) {
  printf("Enter the number of points : ");
  scanf("%zu", n);

  while (*n > N_LIMIT || *n == 0) {
    printf("Invalid number of points. Try again.\n");
    printf("Enter the number of points : ");
    scanf("%zu", n);
  }
}

static double input_x_in_range(double min, double max) {
  double x;
  printf("Enter the location to interpolate it at : ");
  scanf("%lf", &x);
  while (min > x || max < x) {
    printf("Enter a value in the interval (%.3lf, %.3lf) : ", min, max);
    scanf("%lf", &x);
  }
  return x;
}

static bool data_is_invalid(size_t n, Data *data) {
  double prev_diff, diff;
  size_t i;
  prev_diff = diff = data[1].x - data[0].x;
  for (i = 2; i < n; i++) {
    diff = data[i].x - data[i - 1].x;
    if (fabs(diff - prev_diff) > EPS) {
      printf("The data is inconsistently distributed. Please try again.\n");
      return true;
    }
    prev_diff = diff;
  }
  return false;
}

int main() {
  size_t n;
  input_point_count(&n);

  Data *data = malloc(sizeof(Data) * n);
  double min, max;
  do {
    input_data(n, data);
    sort_find_min_max(n, data, &min, &max);
  } while (data_is_invalid(n, data));

  double x = input_x_in_range(min, max);

  double ans = newton_interpolate(x, n, data, true);
  printf("Forward interpolation:\nf(%.3lf) = %.5lf\n", x, ans);
  ans = newton_interpolate(x, n, data, false);
  printf("Backward interpolation:\nf(%.3lf) = %.5lf\n", x, ans);

  free(data);
  return 0;
}
