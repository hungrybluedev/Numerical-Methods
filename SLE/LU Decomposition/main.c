#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lud.h"
#include "matrix.h"

int main() {
  size_t n = 5;
  //   printf("Enter number of variables : ");
  //   scanf("%zu", &n);

  //   double** arr = malloc(n * sizeof(double *));
  //   size_t i;
  //   for (i = 0; i < n; i++) {
  //       arr[i] = malloc((n + 1) * sizeof(double));
  //   }

  double st[5][6] = {
      {1, 1, 1, 1, 1, 0},   {0, 1, 2, 3, 4, 0},     {0, 1, 4, 9, 16, 1},
      {0, 1, 8, 27, 64, 0}, {0, 1, 16, 81, 256, 0},
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
  char *message = lu_decompose(A);
  if (message) {
    printf("%s\n", message);
  }

  printf("The matrix in RREF:\n");
  print_matrix(A);

  free_matrix(A);

  return EXIT_SUCCESS;
}