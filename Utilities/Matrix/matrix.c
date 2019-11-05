#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

void print_matrix(Matrix matrix) {
  size_t i, j;
  for (i = 0; i < matrix.row; i++) {
    for (j = 0; j < matrix.col; j++) {
      printf("%" WIDTH "." DIGITS "lf ", matrix.arr[i][j]);
    }
    printf("\n");
  }
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
char *input_matrix(Matrix matrix) {
  size_t i, j;
  for (i = 0; i < matrix.row; i++) {
    for (j = 0; j < matrix.col; j++) {
      printf("%zu, %zu: ", i, j);
      if (scanf("%lf", &(matrix.arr[i][j])) != 1) {
        return "Could not read item.";
      }
    }
  }
  return NULL;
}
#pragma clang diagnostic pop

void free_matrix(Matrix matrix) { free(matrix.arr); }

static char *validate_row(Matrix matrix, size_t row) {
  if (row >= matrix.row) {
    return "Invalid row index. Out of bounds.";
  }
  return NULL;
}

char *swap_rows(Matrix matrix, size_t row1, size_t row2) {
  if (row1 == row2)
    return NULL;

  char *message;
  if ((message = validate_row(matrix, row1)) != NULL) {
    return message;
  }
  if ((message = validate_row(matrix, row2)) != NULL) {
    return message;
  }

  size_t i;
  for (i = 0; i < matrix.col; i++) {
    double temp = matrix.arr[row1][i];
    matrix.arr[row1][i] = matrix.arr[row2][i];
    matrix.arr[row2][i] = temp;
  }
  return NULL;
}

static char *validate_col(Matrix matrix, size_t col) {
  if (col >= matrix.col) {
    return "Invalid column index. Out of bounds.";
  }
  return NULL;
}

char *swap_cols(Matrix matrix, size_t col1, size_t col2) {
  if (col1 == col2)
    return NULL;

  char *message;
  if ((message = validate_col(matrix, col1)) != NULL) {
    return message;
  }
  if ((message = validate_col(matrix, col2)) != NULL) {
    return message;
  }

  size_t i;
  for (i = 0; i < matrix.row; i++) {
    double temp = matrix.arr[i][col1];
    matrix.arr[i][col1] = matrix.arr[i][col2];
    matrix.arr[i][col2] = temp;
  }
  return NULL;
}

void print_solutions(double *x, size_t count) {
  printf("The solutions are:\n");
  size_t i;
  for (i = 0; i < count; i++) {
    printf("%zu: %+." DIGITS "lf\n", (i + 1), x[i]);
  }
}

char *backward_substitution(Matrix matrix) {
  double *x = malloc(matrix.row * sizeof(double));

  if (x == NULL) {
    return "Could not allocate space for displaying solutions.";
  }

  size_t i = matrix.row - 1, j;

  while (i >= 0 && i < matrix.row) {
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

  print_solutions(x, matrix.row);
  free(x);
  return NULL;
}
