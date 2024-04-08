#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000 
#define DEFAULT_MEMO_VALUE -1

int memo[MAX_SIZE];

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    if (memo[n] != DEFAULT_MEMO_VALUE) {
        return memo[n];
    }

    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i <= n; i++) {
        memo[i] = DEFAULT_MEMO_VALUE;
    }

    for (int i = 0; i <= n; ++i) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}

