#include "gaussjordan.h"
#include "matrix.h"
#include <math.h>
#include <stdlib.h>

static size_t eliminate(Matrix A) {

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