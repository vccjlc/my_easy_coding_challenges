

//Write a function that takes two inputs: n and m, 
//and outputs the number of unique paths from the top left corner to 
//the bottom right corner of n x m grid. 
//You can only move down or right 1 unit at the time. 


#include <stdio.h>

int find_paths(int n, int m) {
    if (n == 1 || m == 1) {
        return 1;
    } else {
        return find_paths(n, m - 1) + find_paths(n - 1, m);
    }
}

int main() {
    int n, m;

    printf("Enter the number of rows (n): ");
    scanf("%d", &n);

    printf("Enter the number of columns (m): ");
    scanf("%d", &m);

    printf("Number of unique paths: %d\n", find_paths(n, m));

    return 0;
}

