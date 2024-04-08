#include <stdio.h>
#include <stdlib.h>

// Function to sum elements of the array recursively
int sum_array(int *arr, int size) {
    if (size <= 0) {
        return 0;
    }
    return arr[0] + sum_array(arr + 1, size - 1);
}

int main() {
    int originalLength, length;

    // Read the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &originalLength);

    // Allocate memory for the array
    int *array = (int*)malloc(originalLength * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Non-zero return value indicates failure
    }

    // Read elements into the array
    printf("Enter %d elements:\n", originalLength);
    for (int i = 0; i < originalLength; i++) {
        scanf("%d", &array[i]);
    }

    // Calculate the sum of the array elements
    int sum = sum_array(array, originalLength);
    printf("Sum of array elements: %d\n", sum);

    // Free the original array memory
    free(array);

    return 0;
}


