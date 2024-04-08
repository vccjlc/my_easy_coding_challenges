#include <stdio.h>

long binexp(int a, int b) {
    if (b == 0)
        return 1;
    long tmp = binexp(a, b / 2);
    long result = (long)tmp * tmp;
    if (b % 2 == 1)
        result *= a;
    return result;
}

int main(void) {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    long result = binexp(a, b);
    printf("%li\n", result);
    return 0;
}
