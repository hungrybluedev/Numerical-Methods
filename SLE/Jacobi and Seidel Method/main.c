#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrix.h"
// #include "jacobi.h"
#include "seidel.h"

int main() {
  size_t n = 4;
  double x[4];
  double tolerance = 1e-3;
//   printf("Enter number of variables : ");
//   scanf("%zu", &n);

//   double** arr = malloc(n * sizeof(double *));
//   size_t i;
//   for (i = 0; i < n; i++) {
//       arr[i] = malloc((n + 1) * sizeof(double));
//   }

  double st[4][5] = {
      {1, 4, -1, -1, -1},
      {4, 1, -1, 1, -2},
      {1, -1, 1, 3, 1},
      {-1, -1, 5, 1, 0}
  };

  double** arr = malloc(n * sizeof(double *));
  size_t i;
  for (i = 0; i < n; i++) {
      arr[i] = st[i];
  }

  Matrix A = {arr, n, n + 1};

//   printf("Enter the coeffcients. The last column is for RHS.\n");
//   input_matrix(A);

  printf("The matrix entered is:\n");
  print_matrix(A);

//   jacobi(A, x, tolerance);
  seidel(A, x, tolerance);

  printf("The values are :\n");
  for (i = 0; i < A.row; i++) {
      printf("x%zu = %.5lf\n", (i + 1), x[i]);
  }

  free_matrix(A);

  return EXIT_SUCCESS;
}