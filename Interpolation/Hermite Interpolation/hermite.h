#ifndef HERMITE_H
#define HERMITE_H

#include "data.h"
#include <stddef.h>

/**
 *
 * @param n
 * @param x
 * @param data
 * @return
 */
double hermite_interpolate(size_t n, double x, Data *data);

#endif//HERMITE_H