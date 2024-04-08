#include <stdio.h>

// Function to print the subsequence
void printSubsequence(int subseq[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", subseq[i]);
    }
    printf("\n");
}

// Recursive function to generate all subsequences
void generateSubsequences(int sequence[], int n, int subseq[], int subseqSize, int index) {
    if (index == n) {
        // Base case: if index reaches the end, print the subsequence
        if (subseqSize != 0)
            printSubsequence(subseq, subseqSize);
        return;
    }

    // Include the current element in the subsequence
    subseq[subseqSize] = sequence[index];
    generateSubsequences(sequence, n, subseq, subseqSize + 1, index + 1);

    // Exclude the current element from the subsequence
    generateSubsequences(sequence, n, subseq, subseqSize, index + 1);
}

int main() {
    int n; 
    scanf("%d", &n); 


    int sequence[n]; // Array to store the sequence
    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence[i]); 
    }

    int subseq[n]; 
    // Function call to start generating all subsequences
    generateSubsequences(sequence, n, subseq, 0, 0);

    return 0;
}

