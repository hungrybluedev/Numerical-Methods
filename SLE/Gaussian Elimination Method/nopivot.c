#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matrix.h"
#include "nopivot.h"

static size_t forward_elimination(Matrix A) {
  size_t k;
  for (k = 0; k < A.row; k++) {
    double pivot = A.arr[k][k];
    if (fabs(pivot) < EPS) {
      // Singular matrix
      return k;
    }

    size_t i, j;
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

char* ge_no_pivot(Matrix A) {
  size_t rank = forward_elimination(A);

  if (rank < A.row) {
    if (fabs(A.arr[rank][A.col - 1]) >= EPS) {
      return "Inconsistent system of linear equations.";
    } else {
      return "System has infinitely many solutions.";
    }
  }

  backward_substitution(A);
  return NULL;
}