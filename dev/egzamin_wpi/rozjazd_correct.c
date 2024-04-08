#include <stdio.h>
#include <stdlib.h>

// Parzyste indeksy shift na prawo, nieparzyste shift na lewo
// Metoda - triple reversal

// mod dla ujemnych
int mod(int x, int y) { return (x % y + y) % y; }

void reverse_half(int arr[], int start, int end) {
    end--;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start += 2;
        end -= 2;
    }
}

void shift_even(int array[], int size, int k) {
    reverse_half(array, 0, size - 1);
    reverse_half(array, 0, k - 1);
    reverse_half(array, k, size - 1);
}

void shift_odd(int array[], int size, int k) {
    int right_shift = size - k;
    reverse_half(array, 1, size);
    reverse_half(array, 1, right_shift);
    reverse_half(array, right_shift + 1, size);
}

void rozklad(int arr[], int size, int k) {
    // Adjust k to be within the bounds of the array size
    k = k % (size * 2);

    if (k % 2 == 0) { // If k is even
        shift_even(arr, size, k);
        shift_odd(arr, size, k);
    } else {
        // k nieparzyste
        for (int i = 0; i < size; i += 2) {
            int pom = arr[mod(i + k, size)];
            arr[mod(i + k, size)] = arr[i];
            arr[i] = pom;
        }
    }
}

int main() {
    int size; // Variable to store the array size
    int k;    // Variable to store the shift value

    // Prompt the user to enter the array size
    printf("Enter the array size: ");
    scanf("%d", &size);

    // Validate the input to ensure the size is positive
    if (size <= 0) {
        printf("Array size must be positive.\n");
        return 1; // Exit with an error code
    }

    // Allocate memory for the array based on the user input
    int *A = (int *)malloc(size * sizeof(int));
    if (A == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit with an error code
    }

    // Initialize the array with numbers from 0 to size-1
    for (int i = 0; i < size; i++) {
        A[i] = i;
    }

    // Print the original array
    printf("Original array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    // Prompt the user to enter the shift value k
    printf("Enter the shift value (k): ");
    scanf("%d", &k);

    // Call the rozklad function with the user-defined size and k
    rozklad(A, size, k);

    // Print the array after applying the rozklad function
    printf("Array after applying rozklad with k = %d:\n", k);
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(A);

    return 0;
}
