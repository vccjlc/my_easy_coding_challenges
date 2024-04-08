#include <stdio.h>

int countSubarraysWithSum(int arr[], int n, int targetSum) {
    int start = 0, end = 0;
    int currentSum = 0;
    int count = 0;

    while (end < n) {
        // Add the element at the end to the currentSum
        currentSum += arr[end];

        // While currentSum is greater than targetSum, subtract
        // the element at start from currentSum and increment start
        while (currentSum > targetSum && start < end) {
            currentSum -= arr[start];
            start++;
        }

        // Check if currentSum is equal to targetSum
        if (currentSum == targetSum) {
            count++;
        }

        // Move end to the next element
        end++;
    }

    return count;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int targetSum = 5;

    printf("Number of subarrays with sum %d: %d\n", targetSum, countSubarraysWithSum(arr, n, targetSum));
    return 0;
}

