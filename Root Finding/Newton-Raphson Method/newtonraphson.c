#include <stdbool.h>
#include <stddef.h>
#include <math.h>

double newton_raphson(
        double initial,
        double (*f)(double),
        double (*f_prime)(double),
        double eps,
        size_t *n,
        bool silent) {
    *n = 0;

    double x = initial;
    while (fabs(f(x)) > eps) {
        x = x - f(x) / f_prime(x);
        (*n)++;
    }
    return x;
}
