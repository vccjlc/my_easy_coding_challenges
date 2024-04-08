#include <stdio.h>

void running_total(int A[], int n) { 
    int i = 0;
    int cs = 0; 
    while(i < n) {
        cs = cs + A[i];
        printf("running total is: ");
        printf("%d\n", cs);
        i++;
        }
}

int main() {
    int A[] = {3, 4, -1, -5, 5, -4, 3, -2, 1}; // Example array
    int n = sizeof(A) / sizeof(A[0]); // Calculate size of the array
    running_total(A, n);
    
    return 0;
    }
