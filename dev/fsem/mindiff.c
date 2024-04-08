#include <limits.h>
#include <stdio.h>

int abs(int a) { return (a < 0) ? -a : a; }

int min(int a, int b) { return (a > b) ? b : a; }

int max(int a, int b) { return (a < b) ? b : a; }

// assume n > 1 and array is ordered as described;
int mindiff(int A[], int n) {
    if (A[n - 2] <= A[n-1] || A[0] >= A[1]) {
        return min(abs(A[0] - A[1]), abs(A[n - 2] - A[n - 1]));
    }

    int L = 0;
    int R = n % 2 == 0 ? n - 2 : n - 1;

    while (L < R) { 
        int mid = L + (R - L) / 2;
        if (mid % 2 != 0) {
            mid--; 
        }

        if (A[mid] > A[mid + 1]) {
            R = mid;
        } else {
            L = mid + 2 < n ? mid + 2 : mid; 
        }
    }

    int minimum = INT_MAX;
    for (int i = max(0, L - 2); i < min(n - 1, L + 2); ++i) {
        minimum = min(minimum, abs(A[i] - A[i + 1]));
    }
    return minimum;
}

int main() {
    int n;
    scanf("%d", &n);

    int A[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int result = mindiff(A, n);
    printf("%d\n", result);

    return 0;
}


