#include <stdio.h>

void print_tuple(int *t, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            printf("%d %d	", t[i], t[j]);
            if (i != n - 1) {
            printf("\n");
            }
        }
        
        }
    }


int main(void) {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int myArray[n]; // Variable Length Array based on the input 'n'

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &myArray[i]);
    }

    print_tuple(myArray, n);

    return 0;
}

