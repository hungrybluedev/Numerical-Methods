#include "data.h"
#include "hermite.h"
#include <stdio.h>



int main() {
    Data data[] = {
        {1.3, 0.6200860, -0.5220232},
        {1.6, 0.4554022, -0.5698959},
        {1.9, 0.2818186, -0.5811571}
    };

  size_t n = sizeof(data) / sizeof(Data);
  double x = 1.5;

  double ans = hermite_interpolate(n, x, data);

  printf("f(%.2lf) = %.7lf\n", x, ans);

  return 0;
}