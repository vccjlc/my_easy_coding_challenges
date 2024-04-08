#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    size_t size = 2147483647; // Size of the array
    char* array = malloc(size);

    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Simple operation: increment each element by 1
    clock_t start = clock();
    for (size_t i = 0; i < size; ++i) {
        array[i] += 1;
    }
    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time spent: %f seconds\n", time_spent);

    free(array);
    return 0;
}

