#include "polynomial.h"
#include <math.h>

double f(double x) {
  return 7 * pow(x, 4) + 12 * pow(x, 3) - 9 * x * x - 15 * x + 72;
}
double f_prime(double x) { return 28 * pow(x, 3) + 36 * x * x - 18 * x - 15; }
