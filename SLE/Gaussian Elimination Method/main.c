#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrix.h"
#include "nopivot.h"

int main() {
  size_t n;
  printf("Enter number of variables : ");
  scanf("%zu", &n);

  double** arr = malloc(n * sizeof(double *));
  size_t i;
  for (i = 0; i < n; i++) {
      arr[i] = malloc((n + 1) * sizeof(double));
  }

  Matrix A = {.arr = arr, .row = n, .col = n+ 1};

  printf("Enter the coeffcients. The last column is for RHS.\n");
  input_matrix(A);

  printf("The matrix entered is:\n");
  print_matrix(A);

  ge_no_pivot(A);

  printf("The matrix after elimination:\n");
  print_matrix(A);

  free_matrix(A);

  return EXIT_SUCCESS;
}