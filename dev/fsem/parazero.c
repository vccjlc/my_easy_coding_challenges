#include <stdio.h>
#include <stdlib.h>

int parazero(int A[], int n) {
    int left = 0;
    int right = n - 2; // we look for pairs, so the second element of the pair is at most at n-2

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if ((A[mid] == 0 && A[mid + 1] == 0) || 
            (A[mid] + A[mid + 1] == 0 && abs(A[mid] - A[mid + 1]) == 1)) {
            return mid;
        }

        if (A[mid] == -1 && A[mid + 1] == 0) {
            // Special case for -1 and 0, we need to check the side where 0 could be part of a decreasing subsequence
            return mid;
        } else if (A[mid] < 0 && A[mid + 1] >= 0) {
            // If we're at the boundary between negative and non-negative
            // Check if we went from negative to positive; if so, the current index is the solution
            return mid;
        } else if (A[mid] > 0) {
            // If the mid element is positive, we need to search left
            right = mid - 1;
        } else {
            // If the mid element is negative or zero, we need to search right
            left = mid + 1;
        }
    }

    return -1; // Return -1 if no such pair exists
}

int main() {
    // Example usage:
    int A[] = {-4, -2, -1, 0, 0, 0, 10};
    int n = sizeof(A) / sizeof(A[0]);
    int result = parazero(A, n);
    if (result != -1) {
        printf("Index: %d, Elements: %d, %d\n", result, A[result], A[result + 1]);
    } else {
        printf("No such index found.\n");
    }
    return 0;
}

