#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "jacobi.h"
#include "matrix.h"

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

void jacobi(Matrix A, double x[A.row], double tolerance) {
  ensure_convergence(A);

  double* y = malloc(A.row * sizeof(double));
  double max_error;
  do {
      size_t i, j;
      for (i = 0; i < A.row; i++) {
          double sum = 0;
          for (j = 0; j < A.row; j++) {
              if (i == j) continue;
              sum += A.arr[i][j] * x[j];
          }
        y[i] = (A.arr[i][A.col - 1] - sum) / A.arr[i][i];
      }
      // Check all tolerances now
      max_error = fabs(x[0] - y[0]) / x[0];
      for (i = 1; i < A.row; i++) {
        double err = fabs(x[i] - y[i]) / y[i];
        if (err > max_error) {
            max_error = err;
        }
      }
      // Copy over all results
      for (i = 0; i < A.row; i++) {
          x[i] = y[i];
      }
  } while (max_error > tolerance);
}