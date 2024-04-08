#include <stdio.h>

// Function to calculate the Greatest Common Divisor (GCD)
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function to rotate the array A by k positions to the left
void rotateLeft(int A[], int N, int k) {
    int cycles = gcd(N, k);         // Number of cycles
    int cycle_length = N / gcd(N, k); // Length of each cycle
    
    for (int i = 0; i < cycles; i++) {
        int temp = A[i];            // Temporary variable to store the value to be rotated
        int current = i;            // Current index
        for (int j = 0; j < cycle_length; j++) {
            // Calculate the new position for a left rotation
            int next = (current - k + N) % N;
            int temp2 = A[next];    // Store the value at the new position
            A[next] = temp;         // Move the value to its new position
            temp = temp2;           // Update temp with the value that was replaced
            current = next;         // Update current position
        }
    }
}

int main() {
    int N = 8; // Array size
    int k = 3;  // Number of positions to rotate
    int A[N];   // Declare the array

    // Initialize the array for demonstration
    for (int i = 0; i < N; i++) {
        A[i] = i;
    }

    // Rotate the array
    rotateLeft(A, N, k);

    // Print the rotated array
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}

