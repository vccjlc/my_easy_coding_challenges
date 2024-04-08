#include <stdio.h>

#define MAX 10

int czytaj(int a[], int n) {
    int x;
    int i = 0;
    while ((i < n) && (scanf("%d", &x) > 0) && (x != 0)) {
        a[i] = x;
        ++i;
    }
    return i;
}

void pisz_odwrotnie(int a[], int n) {
    for (int i = n - 1; i >= 0; --i) {
        printf("%d\n", a[i]);
    }
}

int main(void) {
    int a[MAX];
    int n = czytaj(a, MAX);
    pisz_odwrotnie(a, n);
    return 0;
}
