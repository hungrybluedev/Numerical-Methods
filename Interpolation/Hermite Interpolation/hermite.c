#include "data.h"
#include <stdlib.h>

static void init_table(size_t m, Data *data, double **y) {
  size_t i, j;

  // Allocate only as much memory as required
  for (i = 0; i < m; i++) {
    y[i] = malloc((m - i + 1) * sizeof(double));
  }

  // Columns 0, 1 and half of 2
  // Copy two places at a time
  for (i = 0; i < m; i += 2) {
    y[i][0] = y[i + 1][0] = data[i / 2].x;
    y[i][1] = y[i + 1][1] = data[i / 2].y;
    y[i][2] = data[i / 2].dy;
  }

  // Rest of column 2
  // Fill in the pieces with the divided differences
  for (i = 1; i < m - 2; i += 2) {
    y[i][2] = (y[i + 1][1] - y[i][1]) / (y[i + 1][0] - y[i][0]);
  }

  // Populate the rest of the table. Column 3 onwards
  for (j = 2; j < m; j++) {
    for (i = 0; i < m - j; i++) {
      // Note that the bottom requires a separation of j because the
      // stride length increases by 1 as we move right.
      y[i][j + 1] = (y[i + 1][j] - y[i][j]) / (y[i + j][0] - y[i][0]);
    }
  }
}

static void free_2D_array(size_t m, double **y) {
  size_t i;
  for (i = 0; i < m; i++) {
    free(y[i]);
  }
  free(y);
}

double hermite_interpolate(size_t n, double x, Data *data) {
  size_t m = 2 * n, j;
  double **y = malloc(m * sizeof(double *));
  init_table(m, data, y);

  double sum = y[0][1], partial = 1;

  for (j = 2; j <= m; j++) {
    partial *= (x - y[j - 2][0]);
    sum += y[0][j] * partial;
  }

  free_2D_array(m, y);
  return sum;
}
