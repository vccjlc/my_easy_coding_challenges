#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

// Function to find median of two sorted arrays
// n - size of array A
// m - size of array B
double findMedianSortedArrays(int *A, int n, int *B, int m) {
    if (n > m) {
        // Ensure that array 'a' is the smaller one
        return findMedianSortedArrays(b, m, a, n);
    }

    int start = 0, end = n
    int i, j, maxLeft, minRight;
    while (start <= end) {
    // partition both arrays such that the elements on the left side (of both arrays combined) 
    // are less than or equal to the elements on the right side
        i = (start + end) / 2;
    	//balance
        j = ((n + m + 1) / 2) - i;

        // Handling edge cases
        int maxLeftA = (i == 0) ? INT_MIN : A[i - 1];
        int minRightA = (i == n) ? INT_MAX : A[i];
        int maxLeftB = (j == 0) ? INT_MIN : B[j - 1];
        int minRightB = (j == m) ? INT_MAX : B[j];

        if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
            // Found the correct partition
            if ((n + m) % 2 == 0) {
                return ((double)max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2;
            } else {
                return (double)max(maxLeftA, maxLeftB);
            }
        } else if (maxLeftA > minRightB) {
            end = i - 1;
        } else {
            start = i + 1;
        }
    }

    return -1; // If input arrays are not sorted or incorrect
}

int main() {
    int a[] = {1, 3, 5};
    int b[] = {2, 4, 6};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    printf("Median is: %f\n", findMedianSortedArrays(a, n, b, m));
    return 0;
}

