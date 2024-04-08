#include <stdio.h>
#include <stdlib.h>

void print_set(int *subset, int n) {
    printf("{ ");
    for (int i = 0; i < n; i++) {
        if (subset[i] == 1) {
            printf("%d ", i + 1);
        }
    }
    printf("}\n");
}

void generate_powerset(int n, int *subset, int current_index) {
    if (current_index == n) {
        print_set(subset, n);
        return;
    }

    // exclude the current element
    subset[current_index] = 0;
    generate_powerset(n, subset, current_index + 1);

    // include the current element
    subset[current_index] = 1;
    generate_powerset(n, subset, current_index + 1);
}

int main() {
    int n;
    scanf("%d", &n);

    int *subset = (int *)malloc(n * sizeof(int));
    if (subset == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    generate_powerset(n, subset, 0);
    free(subset);
    return 0;
}

