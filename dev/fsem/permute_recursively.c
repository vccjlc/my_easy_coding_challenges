#include <stdbool.h>
#include <stdio.h>

void permute(int n, int k, int arr[], bool used[]);

void print_all_permutations(int n) {
    bool used[n + 1];
    int arr[n];

    for (int i = 0; i <= n; ++i) {
        used[i] = false;
    }

    permute(n, 0, arr, used);
}

void permute(int n, int k, int arr[], bool used[]) {
    if (k == n) {
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            used[i] = true;
            arr[k] = i;
            permute(n, k + 1, arr, used);
            used[i] = false;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    print_all_permutations(n);

    return 0;
}

