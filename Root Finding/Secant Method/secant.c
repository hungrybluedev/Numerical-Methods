#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

static double next_x(double x0, double x1, double (*f)(double)) {
    double fx0 = f(x0);
    double fx1 = f(x1);
    return (x0 * fx1 - x1 * fx0) / (fx1 - fx0);
}

double secant(
        double x0,
        double x1,
        double (*f)(double),
        double eps,
        size_t *n,
        bool silent) {
    *n = 0;
    double x;

    do {
        x = next_x(x0, x1, f);
        (*n)++;
        if (!silent) {
            printf("%2zu %10.5lf %10.5lf %10.5lf %10.5lf\n", *n, x0, x1, x, f(x));
        }
        // Move up the guess sequence
        x0 = x1;
        x1 = x;
    } while (fabs(f(x)) > eps);

    return x;
}
