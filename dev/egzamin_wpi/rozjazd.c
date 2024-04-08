// Przesunięcie nieparzystych w lewo, parzystych w prawo
// Handling ujemne modulo 
void rozjazd(int A[], int k) {
    int B[2 * N];
    int i = 0;
    while (i < 2 * N) {
        if (i % 2 == 0) { // i even
            B[(i + k) % (2 * N)] = A[i];
        } else { // i odd
            // Normalize k and ensure the result is positive
            int effectiveK =
                k % (2 * N); // Normalize k to the range of the array
            B[(i - effectiveK + 2 * N) % (2 * N)] = A[i];
        }

        i++;
    }
    // Copying back to A
    for (int i = 0; i < 2 * N; i++) {
        A[i] = B[i];
    }
}
