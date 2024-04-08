#include <stdio.h>

int return_factorial(int n) {
    if (n == 1) {
        return 1;
    }
    else {
        return n * return_factorial(n - 1);
    }
}

int main() {
    int n;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial of a negative number is not defined.\n");
    } else if (n == 0) {
        printf("Factorial of 0 is 1.\n");
    } else {
        int factorial = return_factorial(n);
        printf("Factorial of %d is %d\n", n, factorial);
    }

    return 0;
}

