#include <stdio.h>

#include <stdio.h>

int findBreakingPoint(int arr[], int size) {
    // Check if the first element breaks the sequence
    if (size > 1 && arr[0] > arr[1]) {
        return 0;
    }

    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if mid is the breaking point
        if (mid > 0 && arr[mid] < arr[mid - 1]) {
            return mid;
        }

        // Adjust search space
        if (arr[mid] >= arr[low]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    // Check if the last element breaks the sequence
    if (size > 1 && arr[size - 1] < arr[size - 2]) {
        return size - 1;
    }

    return -1; // Return -1 if no breaking point is found
}


int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d elements of the array:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int index = findBreakingPoint(arr, size);

    if (index != -1) {
        printf("First non-increasing element is at index %d with value %d\n", index, arr[index]);
    } else {
        printf("All elements are increasing\n");
    }

    return 0;
}

