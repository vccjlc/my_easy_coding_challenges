#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

void sortuj(int i, int A[], int n) {
    int j = INT_MIN; //	Zamiast wrappera

    if (i == n - 1) { // i jest na końcu, czyli j jest pierwszym większym od
                      // następnego
        for (int k = 0; k < n - 1; ++k) {
            if (A[k] > A[k + 1]) {
                j = k; // pierwszy większy od następnego, o ile jest
            }  	
        }
    } else { // i nie jest na końcu
        for (int k = 0; k < n - 1;
             ++k) { // Szukaj pierwszego malejącego, który nie jest obok i
            if (A[k] > A[k + 1] && k != i) {
                j = k + 1;
            }
        }

        if (j == INT_MIN) { // Nie znaleziono, ale "i" oraz "j" mogą jeszcze być
                            // obok siebie
            for (int k = 0; k < n - 1; ++k) {
                if (A[k] > A[k + 1]) {
                    if (i == k) {
                        j = k + 1;
                    } else { // i == k + 1
                        j = k;
                    }
                }
            }
        }
    }

    if (j == INT_MIN) { // Nie znaleziono, czyli tablica jest posortowana
        return;

    } else { // Znaleziono, zamień elementy
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int i;
    printf("Enter i: ");
    scanf("%d", &i);

    int A[n];
    printf("Enter %d elements of the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    sortuj(i, A, n);

    for (int i = 0; i < n; ++i) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
