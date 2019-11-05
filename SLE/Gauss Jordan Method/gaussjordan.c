#include "gaussjordan.h"
#include "matrix.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static size_t eliminate(Matrix A) {
  // This is similar to Partial Pivot
  size_t k;
  for (k = 0; k < A.row; k++) {
    size_t i, j, r = k;
    double pivot = A.arr[k][k];
    // Find the largest in the column
    for (i = k + 1; i < A.row; i++) {
      if (fabs(A.arr[i][k]) > fabs(pivot)) {
        pivot = A.arr[i][k];
        r = i;
      }
    }

    if (fabs(pivot) < EPS) {
      // Singular matrix
      return k;
    }

    // Swap with the appropriate row
    swap_rows(A, k, r);
    // print_matrix(A);

    for (i = k + 1; i < A.row; i++) {
      double f = A.arr[i][k] / pivot;
      for (j = k + 1; j < A.col; j++) {
        A.arr[i][j] -= A.arr[k][j] * f;
      }
      A.arr[i][k] = 0;
    }
  }
  return A.row;
}

static void cleanup_backward(Matrix A) {
  size_t k = A.row - 1;
  while (k < A.row) {
    size_t i, j;
    double pivot = A.arr[k][k];
    // Loop over all the rows and zero out the elements
    // the row corresponding to the offset k
    for (i = k - 1; i < A.row; i--) {
      double f = A.arr[i][k] / pivot;
      for (j = k; j < A.col; j++) {
        A.arr[i][j] -= A.arr[k][j] * f;
      }
    }
    // Reduce the row
    A.arr[k][A.col - 1] /= A.arr[k][k];
    A.arr[k][k] = 1.0;
    k--;
  }
}

char *gauss_jordan(Matrix A) {
  size_t rank = eliminate(A), i;

  if (rank < A.row) {
    if (fabs(A.arr[rank][A.col - 1]) > EPS) {
      return "Inconsistent system of linear equations.";
    } else {
      return "System has infinitely many solutions.";
    }
  }
  cleanup_backward(A);
  // The solutions are simply the last column of the array
  printf("The solutions are:\n");
  for (i = 0; i < A.row; i++) {
    printf("%zu: %+." DIGITS "lf\n", (i + 1), A.arr[i][A.col - 1]);
  }
  return NULL;
}