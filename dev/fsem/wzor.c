#include <stdio.h>

int main(void) {
    double a, b, c, x;
    scanf("%lf%lf%lf%lf", &a, &b, &c, &x);
    double w = a * x * x + b * x + c;
    printf("%15.10f\n", w);
    return 0;
}
