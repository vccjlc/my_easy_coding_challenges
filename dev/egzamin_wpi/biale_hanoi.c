#include <stdio.h>

void move(int n, int source, int target, int auxiliary) {
    if (n == 0) {
        return;
    }
    
    move(n - 1, source, auxiliary, target);
    printf("przenieś krążek z wieży %d na wieżę %d\n", source, target);
    move(n - 1, auxiliary, target, source);
    move(n - 1, target, auxiliary, source);
    printf("przenieś krążek z wieży %d na wieżę %d\n", source, target);
    move(n - 1, auxiliary, source, target);
    move(n - 1, source, target, auxiliary);
}

void zamiana(int n) {
    // Call the move function with the initial positions and the number of discs.
    move(n, 1, 2, 3);
}

int main() {
    // Example usage:
    zamiana(2);
    return 0;
}

