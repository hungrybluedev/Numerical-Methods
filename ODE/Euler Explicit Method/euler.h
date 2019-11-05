#ifndef EXPLICIT_H
#define EXPLICIT_H

#include <stdlib.h>

void iterate_explicit(size_t n, double y[n], double (*f)(double y, double x),
                      double a, double h);

#endif // EXPLICIT_H