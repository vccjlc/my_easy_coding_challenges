#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOSOWANIA 10

int randof(int n) {
    return (int) (rand() / (RAND_MAX + 1.0) * n);
}

int main(void) {
    srand((unsigned) time(NULL));
    for (int i = 0; i < LOSOWANIA; ++i) {
        printf("%d", randof(2));
    }
    printf("\n");
    return 0;
}
