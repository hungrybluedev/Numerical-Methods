#include "gaussjordan.h"
#include "matrix.h"
#include <math.h>
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
    print_matrix(A);

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

}

char *gauss_jordan(Matrix A) {
  size_t rank = eliminate(A);

  if (rank < A.row) {
    if (fabs(A.arr[rank][A.col - 1]) > EPS) {
      return "Inconsistent system of linear equations.";
    } else {
      return "System has infinitely many solutions.";
    }
  }

  return NULL;
}