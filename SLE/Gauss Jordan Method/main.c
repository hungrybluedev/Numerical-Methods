#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gaussjordan.h"
#include "matrix.h"

int main() {
  size_t n = 4;
  //   printf("Enter number of variables : ");
  //   scanf("%zu", &n);

  //   double** arr = malloc(n * sizeof(double *));
  //   size_t i;
  //   for (i = 0; i < n; i++) {
  //       arr[i] = malloc((n + 1) * sizeof(double));
  //   }

  double st[4][5] = {
      {+1.19, +2.11, -100, +1, 1.12},
      {+14.2, -0.122, +12.2, -1, 3.44},
      {0, +100, -99.9, +1, 2.15},
      {15.3, 0.11, -13.1, -1, 4.16},
  };

  double **arr = malloc(n * sizeof(double *));
  size_t i;
  for (i = 0; i < n; i++) {
    arr[i] = st[i];
  }

  Matrix A = {arr, n, n + 1};

  //   printf("Enter the coeffcients. The last column is for RHS.\n");
  //   input_matrix(A);

  printf("The matrix entered is:\n");
  print_matrix(A);

  //  char *message = ge_part_pivot(A);
  char *message = gauss_jordan(A);
  if (message) {
    printf("%s\n", message);
  }

  printf("The matrix in RREF:\n");
  print_matrix(A);

  free_matrix(A);

  return EXIT_SUCCESS;
}