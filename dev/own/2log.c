#include <stdio.h>

int findBreakingPoint(int arr[], int low, int high) {
    if (low >= high) return -1; // No breaking point found

    int mid = low + (high - low) / 2;

    // Check adjacent elements
    if ((mid > low && arr[mid] < arr[mid - 1]) || (mid < high && arr[mid] > arr[mid + 1])) {
        return mid;
    }

    // Recursive calls for the two halves
    int leftSearch = findBreakingPoint(arr, low, mid);
    if (leftSearch != -1) return leftSearch;

    return findBreakingPoint(arr, mid + 1, high);
}

int main() {
    int n, i;

    // Input for the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input for the elements of the array
    printf("Enter %d elements in increasing order with one breaking point:\n", n);
    for (int k = 0; k < n; k++) {
        scanf("%d", &arr[k]);
    }

    // Input for the known index i
    printf("Enter the known index i (0 to %d): ", n-1);
    scanf("%d", &i);

   int breakingPointIndex = findBreakingPoint(arr, 0, n - 1);
    if (breakingPointIndex != -1) {
        printf("Breaking point is at index %d with value %d\n", breakingPointIndex, arr[breakingPointIndex]);
    } else {
        printf("No breaking point found in the array\n");
    }

    return 0;
}

