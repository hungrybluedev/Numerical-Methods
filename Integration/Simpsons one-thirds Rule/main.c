#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "onethirds.h"

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

    size_t n;
    do {
        printf("Enter the number of intervals (should be even) :\nn: ");
        scanf("%zu", &n);
    } while (n % 2);

    double result = integrate(f, a, b, n);

    printf("The result of integration is %lf\n", result);

    return 0;
}