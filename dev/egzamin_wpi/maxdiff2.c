#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int maxdiff(int A[], int n) {
    int leftsum = 0;
    bool was_negative = false; // sprawdzamy czy jest ujemny element w tablicy
    for (int i = 0; i < n; ++i) {
        leftsum += A[i];
        if (A[i] < 0)
            was_negative = true;
    }

    if (!was_negative) { // jeśli nie było żadnego ujemnego, bierzemy ile się da
                         // z lewej i odejmujemy jak najmniej się da z prawej
                         // (czyli jeden element, bo trzeba, ponieważ j <= n -
                         // 1)
        return leftsum - A[n - 1];
    }

    int rightsum = 0;
    int maxsum = INT_MIN;
    int currentsum1 = INT_MIN; // suma gdy i = j
    int currentsum2 = INT_MIN; // suma gdy i < j

    for (int i = n - 1; i >= 0; --i) {
        rightsum += A[i];
        currentsum1 = leftsum - rightsum;
        if (currentsum1 > maxsum) {
            maxsum = currentsum1;
        }

        if (i > 0) { // nie można odjąć pierwszego elementu, bo i >= 0
            leftsum -= A[i];
        }
        currentsum2 = leftsum - rightsum;
        if (currentsum2 > maxsum) {
            maxsum = currentsum2;
        }
    }
    return maxsum;
}

int main() {
    int A[] = {-20, 5, 5};            // Example array
    int n = sizeof(A) / sizeof(A[0]); // Calculate size of the array
    int result = maxdiff(A, n);
    printf("Maximum difference is: %d\n", result);
    return 0;
}
