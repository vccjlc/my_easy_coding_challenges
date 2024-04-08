#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
        if (a > b) {
                return a;
        } else {
                return b;
        }
}

int min(int a, int b) {
        if (a > b) {
                return b;
        } else {
                return a;
        }
}

int main(void) {
        int N; 
        scanf("%d", &N);
        int *A = malloc(N * sizeof(int));
        int *B = malloc(N * sizeof(int));
        if (!A || !B) {
                return 1;
        }

        for (int i = 0; i < N; i++) {
                scanf("%d", &A[i]);
        }

        for (int i = 0; i < N; i++) {
                scanf("%d", &B[i]);
        }

        int wynik = 0;

        if (N == 1) {
                wynik = max(A[0], B[0]);
        } else {
                int L = 0;
                int R = N - 1;

                while (L < R - 1) {
                        int mid = (L + (R - L + 1) / 2);
                        if (max(A[mid], B[mid]) > max(A[mid + 1], B[mid + 1])) {
                                L = mid;
                        } else {
                                R = mid;
                        }
                }

                wynik = min(max(A[R], B[R]), max(A[L], B[L]));
        }

        printf("%d\n", wynik);

        free(A);
        free(B);
        return 0;
}

