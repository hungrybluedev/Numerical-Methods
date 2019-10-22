#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void print_matrix(Matrix matrix) {
  size_t i, j;
  for (i = 0; i < matrix.row; i++) {
    for (j = 0; j < matrix.col; j++) {
      printf("%9." DIGITS "lf ", matrix.arr[i][j]);
    }
    printf("\n");
  }
}

void input_matrix(Matrix matrix) {
  size_t i, j;
  for (i = 0; i < matrix.row; i++) {
    for (j = 0; j < matrix.col; j++ ) {
        printf("%zu, %zu: ", i, j);
        scanf("%lf", &(matrix.arr[i][j]));
    }
  }
}

void free_matrix(Matrix matrix) {
    free(matrix.arr);
}

static char* validate_row(Matrix matrix, size_t row) {
  if (row >= matrix.row) {
    return "Invalid row index. Out of bounds.";
  }
  return NULL;
}

char* swap_rows(Matrix matrix, size_t row1, size_t row2) {
  if (row1 == row2) return NULL;
  validate_row(matrix, row1);
  validate_row(matrix, row2);

  size_t i;
  for (i = 0; i < matrix.col; i++) {
    double temp = matrix.arr[row1][i];
    matrix.arr[row1][i] = matrix.arr[row2][i];
    matrix.arr[row2][i] = temp;
  }
  return NULL;
}

void backward_substitution(Matrix matrix) {
    double *x = malloc(matrix.row * sizeof(double));

    size_t i = matrix.row - 1, j;

    while (i >= 0 && i < matrix.row) {
        printf("%zu\n", i);
        // Start with the RHS
        x[i] = matrix.arr[i][matrix.col - 1];
        // Subtract all values except the variable sought
        for (j = i + 1; j < matrix.row; j++) {
            x[i] -= matrix.arr[i][j] * x[j];
        }
        // Divide by coefficient of variable
        x[i] /= matrix.arr[i][i];
        i--;
    }

    printf("The solutions are:\n");
    for (i = 0; i < matrix.row; i++) {
        printf("%zu: %." DIGITS "lf\n", (i + 1), x[i]);
    }

    free(x);
}