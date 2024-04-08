#include <stdio.h>

void move(int n, int s, int d) {
    printf("Move disk %d from pole %d to %d\n", n, s, d);
}

void hanoi(int n, int s, int d, int a) {
    if (n > 0) {
        hanoi(n - 1, s, a, d);
        move(n, s, d);
        hanoi(n - 1, a, d, s);
    }
}

int main(void) {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    hanoi(n, 1, 3, 2);
    int m = 1 << n;
    printf("Total number of moves: %d\n", m);

    return 0;
}
