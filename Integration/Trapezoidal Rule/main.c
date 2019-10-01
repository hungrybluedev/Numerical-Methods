#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "trapezoidal.h"

// Put the function that you want to integrate in this area.
double f(double x) {
    return 1 / (1 + x * x);
}

double get_double() {
    double value;
    scanf("%lf", &value);
    return value;
}

int main() {
    printf("Enter the limits of the integration :\na: ");
    double a = get_double();
    printf("b: ");
    double b = get_double();

    // Make sure that a is smaller than b
    if (a > b) {
        double temp = a;
        a = b;
        b = temp;
    }

    printf("Enter the number of intervals :\nn: ");
    size_t n;
    scanf("%zu", &n);

    double result = integrate(f, a, b, n);

    printf("The result of integration is %lf\n", result);

    return 0;
}