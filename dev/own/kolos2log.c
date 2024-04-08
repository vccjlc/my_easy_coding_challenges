#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sortTransformedArray(int A[], int n, int i) {
    // Find the other index j where the swap occurred
    int j = -1;
    if (i > 0 && A[i] < A[i - 1]) {
        j = i - 1;
    } else if (i < n - 1 && A[i] > A[i + 1]) {
        j = i + 1;
    }

    // If j is not found, use binary search to find it
    if (j == -1) {
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if ((mid > 0 && A[mid] < A[mid - 1]) || (mid < n - 1 && A[mid] > A[mid + 1])) {
                j = mid;
                break;
            } else if (A[mid] < A[i]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    // Swap back the elements
    if (j != -1) {
        swap(&A[i], &A[j]);
    }
}

int main() {
    int n, i;

    // Input for the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int A[n];

    // Input for the elements of the array
    printf("Enter %d elements in increasing order with one swap:\n", n);
    for (int k = 0; k < n; k++) {
        scanf("%d", &A[k]);
    }

    // Input for the known index i
    printf("Enter the known index i (0 to %d): ", n-1);
    scanf("%d", &i);

    // Calling the function to sort the array
    sortTransformedArray(A, n, i);

    // Output the sorted array
    printf("Sorted array: ");
    for (int k = 0; k < n; k++) {
        printf("%d ", A[k]);
    }

    return 0;
}


