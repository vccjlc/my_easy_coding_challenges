#include <stdlib.h>
#include <stdio.h>

int main() {
    void* block = malloc(2147483647); // Attempt to allocate ~2 GB

    if (block != NULL) {
        printf("Allocation succeeded.\n");
        // Remember to free the memory if the allocation succeeds
        free(block);
    } else {
        printf("Allocation failed.\n");
    }

    return 0;
}

