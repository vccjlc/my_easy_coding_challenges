#include <stdio.h>

void move(int n, int s, int d) { printf("%d %d %d\n", s, d, n); }

void hanoi(int *arr, int n, int s, int d, int a) {
    if (n > 0) {
        int next_size = 0;
        int csc = 0; // csc - current_size_counter
        int start = n - 1;

        while (start >= 0 && arr[start] == arr[n - 1]) {
            csc++;
            start--;
        }

        next_size = n - csc;

        hanoi(arr, next_size, s, a, d);

        for (int i = 1; i <= csc; ++i) {
            move(arr[n - 1], s, d);
        }

        hanoi(arr, next_size, a, d, s);
    }
}

void reverse_array(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int A[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    reverse_array(A, 0, n - 1);

    hanoi(A, n, 1, 3, 2);

    return 0;
}
