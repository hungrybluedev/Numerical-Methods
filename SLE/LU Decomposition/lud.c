#include "lud.h"
#include <stdio.h>
#include <stdlib.h>

char *lu_decompose(Matrix A) {
  double **uarray = malloc(A.row * sizeof(double *));
  double **larray = malloc(A.row * sizeof(double *));
  double **parray = malloc(A.row * sizeof(double *));
  size_t i, j, k;

  for (i = 0; i < A.row; i++) {
    uarray[i] = calloc(0, A.col * sizeof(double));
    larray[i] = calloc(0, A.col * sizeof(double));
    parray[i] = calloc(0, A.col * sizeof(double));
  }

  Matrix L = {larray, A.row, A.col};
  Matrix U = {uarray, A.row, A.col};

  //  printf("\n");
  //  print_matrix(L);
  //  printf("\n");
  //  print_matrix(U);

  for (i = 0; i < A.row; i++) {
    // Process the upper triangular matrix first
    for (j = i; j < A.row; j++) {
      double sum = 0;
      for (k = 0; k < i; k++) {
        sum += L.arr[i][k] * U.arr[k][j];
      }
      U.arr[i][j] = A.arr[i][j] - sum;
    }

    // Process the lower triangular matrix
    for (j = i; j < A.row; j++) {
      if (i == j) {
        L.arr[i][i] = 1;
        continue;
      }
      double sum = 0;
      for (k = 0; k < i; k++) {
        sum += L.arr[j][k] * U.arr[k][i];
      }
      L.arr[j][i] = (A.arr[j][i] - sum) / U.arr[i][i];
    }
  }

  printf("The lower triangular matrix is:\n");
  print_matrix(L);
  printf("The upper triangular matrix is:\n");
  print_matrix(U);

  Matrix P = {parray, A.row, A.col};
  multiply(L, U, P);
  printf("The product of L and U is:\n");
  print_matrix(P);

  free_matrix(L);
  free_matrix(U);
  free_matrix(P);
  return NULL;
}