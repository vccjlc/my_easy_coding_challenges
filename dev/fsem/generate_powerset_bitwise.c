#include <stdio.h>
#include <stdlib.h>

void generate_powerset(int arr[], int size) {
    for (int i = 0; i < (1 << size); i++) {
        for (int bit = 0; bit < size; ++bit) {
            if (i & (1 << bit)) {
                printf("%d ", arr[size - bit - 1]);
            }
        }
        printf("\n");
    }
}

int main(void) {
    int n;
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        perror("Memory allocation failed");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    generate_powerset(arr, n);

    free(arr);

    return 0;
}

