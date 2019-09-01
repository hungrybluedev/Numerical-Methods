#include "newton.h"
#include "data.h"
#include <stdlib.h>

static void forward_init(size_t n, Data *data, double **y) {
  size_t i, j;
  for (i = 0; i < n; i++) {
    y[i] = malloc((n - i) * sizeof(double));
  }
  // Copy the data to the first column
  for (i = 0; i < n; i++) {
    y[i][0] = data[i].y;
  }
  // Calculate the differences
  for (j = 1; j < n; j++) {
    for (i = 0; i < n - j; i++) {
      y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
    }
  }
}

static void backward_init(size_t n, Data *data, double **y) {
  size_t i, j;
  for (i = 0; i < n; i++) {
    y[i] = malloc((i + 1) * sizeof(double));
  }
  // Copy the data to the first column
  for (i = 0; i < n; i++) {
    y[i][0] = data[i].y;
  }
  // Calculate the differences
  for (j = 1; j < n; j++) {
    for (i = n - 1; i >= j; i--) {
      y[i][j] = y[i][j - 1] - y[i - 1][j - 1];
    }
  }
}

static double forward_diff(double x, size_t n, Data *data, double **y) {
  forward_init(n, data, y);
  size_t j;
  double sum = y[0][0];
  double partial = 1;
  double u = (x - data[0].x) / (data[1].x - data[0].x);
  for (j = 1; j < n; j++) {
    partial *= u / ((double) j);
    sum += partial * y[0][j];
    u -= 1;
  }
  return sum;
}
static double backward_diff(double x, size_t n, Data *data, double **y) {
  backward_init(n, data, y);
  size_t j;
  double sum = y[n - 1][0];
  double partial = 1;
  double u = (x - data[n - 1].x) / (data[1].x - data[0].x);
  for (j = 1; j < n; j++) {
    partial *= u / ((double) j);
    sum += partial * y[n - 1][j];
    u += 1;
  }
  return sum;
}

static void free_2D_array(size_t n, double **y) {
  size_t i;
  for (i = 0; i < n; i++) {
    free(y[i]);
  }
  free(y);
}

double newton_interpolate(double x, size_t n, Data *data, bool forward) {
  size_t i;
  double **y = malloc(n * sizeof(double *));
  double result =
      forward ? forward_diff(x, n, data, y) : backward_diff(x, n, data, y);
  free_2D_array(n, y);
  return result;
}
