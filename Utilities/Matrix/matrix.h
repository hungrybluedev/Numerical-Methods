#ifndef MATRIX_H
#define MATRIX_H

#define DIGITS "4"
#define WIDTH "9"
#define EPS 1e-5

#include <stdlib.h>

/**
 * A matrix is defined as a 2D grid of numbers.
 * This struct represents a matrix with arr as the storage,
 * and the specified number of rows and columns.
 *
 * Note that that arr is a double pointer variable. So
 * ordinary 2D arrays must be converted to double** before use.
 */
typedef struct {
  double **arr;
  size_t row;
  size_t col;
} Matrix;

/**
 * Prints out a matrix in an even grid. The overall width of each
 * entry is determined by the WIDTH and the precision by the
 * DIGITS string definition. Change these to tweak the settings.
 */
void print_matrix(Matrix matrix);

/**
 * Inputs the entries for a Matrix (whose row and col have already
 * been set) by prompting for input from the command-line. If there
 * was an error while reading the input, a non-null string containing
 * the error message is returned. If input was successful, a null
 * string is returned.
 */
char *input_matrix(Matrix matrix);

/**
 * Swaps the rows specified the row offsets. If they are same, there
 * is no effect. If any of the rows exceeds the size of the matrix,
 * a non-null error message is returned. On successful completion,
 * a null string is returned.
 */
char *swap_rows(Matrix matrix, size_t row1, size_t row2);

/**
 * Swaps the columns specified the column offsets. If they are same,
 * there is no effect. If any of the columns exceeds the size of the
 * matrix, a non-null error message is returned. On successful completion,
 * a null string is returned.
 */
char *swap_cols(Matrix matrix, size_t col1, size_t col2);

/**
 * A simple utility method to print the solutions in the given
 * pointer array with the number of elements specified by count.
 */
void print_solutions(double *x, size_t count);

/**
 * When the matrix has been to a row echelon form, this method
 * can be used to solve for the individual variables. It calls
 * the print_solutions(x, count) method.
 */
char *backward_substitution(Matrix matrix);

/**
 * Frees the space allocated to the matrix.
 */
void free_matrix(Matrix matrix);

#endif // MATRIX_H