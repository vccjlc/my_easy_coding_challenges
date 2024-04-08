#include <stdio.h>

int maxdiff(int A[], int n) { 
    int i = 0, p = 0;
    int cs = 0, maxsum = 0;
    while(i < n) {
        cs += A[i];
        if (cs > maxsum) {
            maxsum = cs;
            p = i;
        }
        i++;
    }
    
    int j = n-1;
    int cs2 = 0, minsum = 0;
    while(j >= p) {
        cs2 += A[j];
        if (cs2 < minsum) {
            minsum = cs2;
        }
        j--;
    }
    
    int kandydat1 = maxsum - minsum;
    
    j = n-1;
    int q = n - 1;
    cs2 = 0; 
    minsum = 0;
    while(j >= 0) {
        cs2 += A[j];
        if (cs2 < minsum) {
            minsum = cs2;
            q = j;
        }
        j--;
    }
    
    i = 0;
    cs = 0; 
    maxsum = 0;
    while(i <= q) {
        cs += A[i];
        if (cs > maxsum) {
            maxsum = cs;
            p = i;
        }
        i++;
    }
    
    int kandydat2 = maxsum - minsum;
    
    return kandydat1 > kandydat2 ? kandydat1 : kandydat2;
}

int main() {
    int A[] = {3, 2, 1, 7}; // Example array
    int n = sizeof(A) / sizeof(A[0]); // Calculate size of the array
    int result = maxdiff(A, n);
    printf("Maximum difference is: %d\n", result);
    return 0;
}

