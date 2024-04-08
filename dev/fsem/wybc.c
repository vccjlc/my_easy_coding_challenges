#include <stdio.h>

void print_subsequence(int subseq[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", subseq[i]);
    }
    printf("\n");
}

void generate_subsequences(int sequence[], int n, int subseq[], int subseq_size, int index, int sum) {
    if (index == n) {
        if (subseq_size != 0 && subseq_size % 2 == 0 && (sum % 2 != 0))
            print_subsequence(subseq, subseq_size);
        return;
    }

    subseq[subseq_size] = sequence[index];
    generate_subsequences(sequence, n, subseq, subseq_size + 1, index + 1, sum + sequence[index]);

    generate_subsequences(sequence, n, subseq, subseq_size, index + 1, sum);
}

int main() {
    int n;
    scanf("%d", &n);

    int sequence[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence[i]);
    }

    int subseq[n];
    generate_subsequences(sequence, n, subseq, 0, 0, 0);

    return 0;
}

