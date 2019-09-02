#ifndef DATA_H
#define DATA_H
/**
 * A helper datatype to store (x, y, y') triples to represent the value of the
 * given function at the presented points, along with the derivative.
 */
typedef struct data_struct {
  double x;
  double y;
  double dy;
} Data;
#endif // DATA_H
