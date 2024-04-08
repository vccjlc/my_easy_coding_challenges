#include <stdio.h>

int count_partitions(int n, int m) {
    if (n == 0) {
        return 1;
    }

    else if (m == 0 || n < 0) {
        return 0;
    }

        return count_partitions(n - m, m) + count_partitions(n, m - 1);
}

int main() {
    int n, m;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter m: ");
    scanf("%d", &m);

    printf("Number of partitions: %d\n", count_partitions(n, m));

    return 0;
}
