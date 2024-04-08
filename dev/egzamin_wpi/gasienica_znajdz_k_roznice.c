int hasPairWithDifferenceK(int A[], int n, int k) {
    int i = 0, j = 1; // Start with j = 1 since i and j can't be the same for a valid pair

    while (j < n && i < n) {
        if (i != j && A[j] - A[i] == k) {
            return 1; // Found a pair
        } else if (A[j] - A[i] < k) {
            j++; // Increase j to make the difference larger
        } else {
            i++; // Increase i to make the difference smaller
        }

        // Ensure i and j stay within bounds and avoid j being less than i
        if (j <= i && j < n) j = i + 1;
    }

    return 0; // No such pair found
}

