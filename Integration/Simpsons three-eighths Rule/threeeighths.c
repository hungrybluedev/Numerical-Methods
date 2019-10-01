#include "threeeighths.h"

double integrate(double (*f)(double), double a, double b, size_t n) {
    double sum = f(a) + f(b);
    double gap = (b - a) / n;

    size_t index;
    for (index = 1; index < n; index++) {
        double fx = f(a + index * gap);
        sum += (index % 3 ? 3 : 2) * fx;
    }

    return gap * sum * (3.0 / 8.0);
}