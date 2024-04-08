#include <stdio.h>

int generate_factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * generate_factorial(n - 1);
    }
}

int main(void) {
    int n = 0;
    scanf("%d", &n);

    int result = generate_factorial(n);
    printf("%d\n", result);

    return 0;
}
