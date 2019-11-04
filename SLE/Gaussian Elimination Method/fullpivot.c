#include "fullpivot.h"
#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static size_t forward_elimination(Matrix A) {
  size_t k;

  // Array to keep track of the variables
  size_t *vars = malloc(A.row * sizeof(size_t));
  for (k = 0; k < A.row; k++) {
    vars[k] = k;
  }

  for (k = 0; k < A.row; k++) {
    size_t imax = k, jmax = k, i, j;
    double pivot = A.arr[k][k];

    // Find the maximum element in the sub-square
    for (i = k; i < A.row; i++) {
      for (j = j; j < A.col - 1; j++) {
        if (fabs(pivot) < fabs(A.arr[i][j])) {
          pivot = A.arr[i][j];
          imax = i;
          jmax = j;
        }
      }
    }

    // There is no point in swapping if the system is not solvable
    if (fabs(pivot) < EPS) {
      // Singular matrix
      return k;
    }

    // Swap the column if necessary
    if (jmax != k) {
      swap_cols(A, k, jmax);
      size_t temp = vars[k];
      vars[k] = vars[jmax];
      vars[jmax] = temp;
    }

    // Swap the rows
    swap_rows(A, k, imax);

    // Proceed as normal
    for (i = k + 1; i < A.row; i++) {
      double f = A.arr[i][k] / pivot;
      for (j = k + 1; j < A.col; j++) {
        A.arr[i][j] -= A.arr[k][j] * f;
      }
      A.arr[i][k] = 0;
    }
  }
  // Display the permutation
  printf("The order of the variables is:\n");
  for (k = 0; k < A.row; k++) {
    printf("%3zu : %3zu\n", k, vars[k]);
  }

  return A.row;
}

char *ge_full_pivot(Matrix A) {
  size_t rank = forward_elimination(A);

  if (rank < A.row) {
    if (fabs(A.arr[rank][A.col - 1]) > EPS) {
      return "Inconsistent system of linear equations.";
    } else {
      return "System has infinitely many solutions.";
    }
  }

  backward_substitution(A);
  return NULL;
}