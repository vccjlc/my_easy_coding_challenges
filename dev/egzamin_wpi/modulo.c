#include <stdio.h>

int abs(int a) {
    return a < 0 ? -a : a;
}

// Modulo operation following the divisor's sign (like Haskell's `mod`)
int mod(int a, int b) {
    int r = a % b;
    return r < 0 ? r + abs(b) : r;
}

int main(void) {
    printf("Which operation would you like to perform?\n");
    printf("1. Remainder Operation: follow numerator (dividend) sign (-8 percent 5 = -3), (8 percent -5 = 2),\n");
    printf("2. Modulo Operation (like mod in Haskell): follow denominator (divisor) sign\n");
    
    int choice;
    printf("Enter your choice (1 or 2):\n");
    scanf("%d", &choice);

    int a, b;
    printf("Enter a:\n");
    scanf("%d", &a);
    printf("Enter b:\n");
    scanf("%d", &b);

    int result;
    switch (choice) {
        case 1: // Remainder operation following the numerator's sign
            result = (a % b);
            printf("Result of the operation is: %d\n", result);
            break;
        case 2: // Modulo operation following the denominator's sign (like Haskell's mod)
            result = mod(a, b);
            printf("Result of the operation is: %d\n", result);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}

