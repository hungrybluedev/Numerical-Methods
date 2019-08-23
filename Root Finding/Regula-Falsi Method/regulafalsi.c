#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include "regulafalsi.h"

/**
 * @param a The lower limit of the interval.
 * @param b The upper bound of the interval.
 * @param f The function whose root is sought.
 * @return An estimate for the location of the root.
 */
static double next_x(
        double a,
        double b,
        const double (*f)(double)
) {
    double fa = f(a);
    double fb = f(b);
    return (a * fb - b * fa) / (fb - fa);
}

double regula_falsi(
        double a,
        double b,
        double (*f)(double),
        const double eps,
        size_t *n,
        const bool silent
) {
    *n = 0; // better safe than sorry
    double fa = f(a);
    double fb = f(b);

    // Check corner cases first
    if (fabs(fa) < eps) {
        return a;
    }
    if (fabs(fb) < eps) {
        return b;
    }

    while (true) {
        double x = next_x(a, b, f);
        double fx = f(x);
        (*n)++; // Increment right after the function call on guessed location

        if (!silent) {
            printf("%2zu %.5lf %.5lf %.5lf %.5lf\n", *n, a, b, x, fx);
        }

        if (fabs(fx) < eps) {
            return x;
        }

        // Chose the interval in which the root lies (from the IVT)
        if (fx * fa < 0) {
            b = x;
            fb = fx;
        } else if (fx * fb < 0) {
            a = x;
            fa = fx;
        }
    }
}
