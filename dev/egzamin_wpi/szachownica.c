#include <stdbool.h>
#include <stdio.h>

#define N 8 // Define the size of the array (should be even)

// Function to check if the number at A[x][y] is even
bool parzysta(int value) { return value % 2 == 0; }

// Function to swap the values of two positions in the array
void zamień(int A[][N], int x1, int y1, int x2, int y2) {
    int temp = A[x1][y1];
    A[x1][y1] = A[x2][y2];
    A[x2][y2] = temp;
}

// Helper function to determine if a given position should have an even number
bool shouldBeEven(int x, int y) {
    return ((x % 4 == 0 && y % 4 == 0) || (x % 4 == 1 && y % 4 == 0) ||
            (x % 4 == 0 && y % 4 == 1) || (x % 4 == 1 && y % 4 == 1) ||
            (x % 4 == 2 && y % 4 == 2) || (x % 4 == 3 && y % 4 == 2) ||
            (x % 4 == 2 && y % 4 == 3) || (x % 4 == 3 && y % 4 == 3));
}

void moveForwardIndices(int *i, int *j) {
    (*i)++;
    if (*i == N) {
        *i = 0;
        (*j)++;
    }
}

void moveBackwardIndices(int *p, int *q) {
    (*p)--;
    if (*p < 0) {
        *p = N - 1;
        (*q)--;
    }
}

// Find first odd (from the left) on even position
void moveToNextOddOnEvenPosition(int A[N][N], int *i, int *j) {
    while (*i < N && *j < N) {
        if (shouldBeEven(*i, *j) && !parzysta(A[*i][*j])) {
            // Found an odd element on an even position
            break; // Exit the loop as the condition is met
        }

        // Move to the next position
        moveForwardIndices(i, j);
    }
}

// Find first even (from the left) on odd position
void moveToNextEvenOnOddPosition(int A[N][N], int *i, int *j) {
    while (*i < N && *j < N) {
        if (!shouldBeEven(*i, *j) && parzysta(A[*i][*j])) {
            break;
        }
        moveForwardIndices(i, j);
    }
}

// Find first odd (from the right) on even position
void moveToPrevEvenOnOddPosition(int A[N][N], int *p, int *q) {
    while (*p >= 0 && *q >= 0) {
        if (!shouldBeEven(*p, *q) && parzysta(A[*p][*q])) {
            break;
        }
        moveBackwardIndices(p, q);
    }
}

// Find first odd (from the right) on odd position
void moveToPrevOddOnEvenPosition(int A[N][N], int *p, int *q) {
    while (*p >= 0 && *q >= 0) {
        if (shouldBeEven(*p, *q) && !parzysta(A[*p][*q])) {
            break;
        }
        moveBackwardIndices(p, q);
    }
}

void szachuj(int A[N][N]) {
    int i = 0, j = 0;         // Forward indices for the first part
    int p = N - 1, q = N - 1; // Backward indices for the first part

    // First Part: Find incorrect odd and replace with even from the back
    while (i < N && j < N) {
        moveToNextOddOnEvenPosition(A, &i, &j);
        if (i < N && j < N) { // Found an incorrect odd on an even position
            moveToPrevEvenOnOddPosition(A, &p, &q);
            if (p >= 0 && q >= 0) { // Found an even on a wrong position
                zamień(A, i, j, p, q);
            }
        }
        moveForwardIndices(&i, &j);
    }

    // Reset indices for the second part
    i = 0; j = 0; // Forward indices for the second part
    p = N - 1; q = N - 1; // Backward indices for the second part

    // Second Part: Find incorrect even and replace with odd from the back
    while (i < N && j < N) {
        moveToNextEvenOnOddPosition(A, &i, &j);
        if (i < N && j < N) { // Found an incorrect even on an odd position
            moveToPrevOddOnEvenPosition(A, &p, &q);
            if (p >= 0 && q >= 0) { // Found an odd on a wrong position
                zamień(A, i, j, p, q);
            }
        }
        moveForwardIndices(&i, &j);
    }
}


// Function to print the 2D array
void printArray(int A[N][N]) {
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0 && i != 0) {
            // Print a separating line after every 2 rows, except before the
            // first row
            for (int k = 0; k < N; k++) {
                if (k % 2 == 0 && k != 0)
                    printf(
                        " "); // Add space to align with the vertical separators
                printf("----"); // Adjust the number of dashes based on your
                                // formatting needs
            }
            printf("\n");
        }
        for (int j = 0; j < N; j++) {
            if (j % 2 == 0 && j != 0)
                printf("  ");        // Add two spaces after every 2 numbers for
                                     // vertical separation
            printf("%3d ", A[i][j]); // Adjust "%3d" if your numbers are larger
                                     // and require more space
        }
        printf("\n\n");
    }
}

int main() {

    int A[N][N] = {
        {1, 2, 3, 4, 5, 6, 7, 8},         {9, 10, 11, 12, 13, 14, 15, 16},
        {17, 18, 19, 20, 21, 22, 23, 24}, {25, 26, 27, 28, 29, 30, 31, 32},
        {33, 34, 35, 36, 37, 38, 39, 40}, {41, 42, 43, 44, 45, 46, 47, 48},
        {49, 50, 51, 52, 53, 54, 55, 56}, {57, 58, 59, 60, 61, 62, 63, 64}};

    printf("Original array:\n\n");
    printArray(A);

    szachuj(A);

    printf("Rearranged array:\n\n");
    printArray(A);

    return 0;
}
