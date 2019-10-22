#ifndef MATRIX_H
#define MATRIX_H

#define DIGITS "4"
#define EPS 1e-5

#include <stdlib.h>

typedef struct {
    double** arr;
    size_t row;
    size_t col;
} Matrix;

void print_matrix(Matrix matrix);

void input_matrix(Matrix matrix);

char* swap_rows(Matrix matrix, size_t row1, size_t row2);

void backward_substitution(Matrix matrix);

void free_matrix(Matrix matrix);

#endif//MATRIX_H