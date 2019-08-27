#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "secant.h"

double f(double x) {
    return 5 * pow(x, 3) - 4 * pow(x, 2) + 3 * x - 19;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"

double input_error() {
    double eps;
    while (true) {
        printf("Enter the tolerance : ");
        scanf("%lf", &eps);
        if (eps > 1e-15) {
            return eps;
        }
        if (eps < 0) {
            printf("Tolerance must be positive. Try again.\n\n");
        } else {
            printf("Tolerance value too low. Try again.\n\n");
        }
    }
}

void input_guesses(double *x0, double *x1, double eps) {
    do {
        printf("Enter first guess  : ");
        scanf("%lf", x0);
        printf("Enter second guess : ");
        scanf("%lf", x1);

        if (fabs(*x0 - *x1) > eps) {
            return;
        }
        printf("The initial guesses are too similar. Try again.\n");
    } while (true);
}

int main() {
    double x0, x1;
    size_t n;

    double eps = input_error();
    input_guesses(&x0, &x1, eps);

    double ans = secant(x0, x1, f, eps, &n, false);

    printf("Answer : %.5lf\nIterations : %zu\n", ans, n);

    return 0;
}

#pragma clang diagnostic pop
