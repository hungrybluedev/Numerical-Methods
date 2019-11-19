#include "seidel.h"
#include "matrix.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static void ensure_convergence(Matrix A) {
  // Swap rows to find the most appropriate pivots
  size_t i, j;
  for (i = 0; i < A.row; i++) {
    size_t r = i;
    for (j = i + 1; j < A.row; j++) {
      if (fabs(A.arr[r][i]) < fabs(A.arr[j][i])) {
        r = j;
      }
    }
    swap_rows(A, i, r);
  }
}

void seidel(Matrix A, double x[A.row], double tolerance) {
  ensure_convergence(A);
  size_t n = 0;

  double *y = malloc(A.row * sizeof(double));
  double max_error;
  do {
    n++;
    size_t i, j;
    for (i = 0; i < A.row; i++) {
      double sum = 0;
      for (j = 0; j < A.row; j++) {
        if (i == j)
          continue;
        sum += A.arr[i][j] * x[j];
      }
      double temp = (A.arr[i][A.col - 1] - sum) / A.arr[i][i];
      y[i] = fabs(x[i] - temp) / temp;
      x[i] = temp;
    }
    // Check all tolerances now
    max_error = y[0];
    for (i = 1; i < A.row; i++) {
      if (y[i] > max_error) {
        max_error = y[i];
      }
    }
  } while (max_error > tolerance);
  printf("Number of iterations : %zu\n", n);

}