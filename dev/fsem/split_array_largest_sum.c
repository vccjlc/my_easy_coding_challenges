#include <stdio.h>
#include <limits.h>

// Function to calculate the sum of array elements
long long sum_array_elements(int nums[], int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }
    return sum;
}

// Function to check if mid can be maximum subarray sum
int is_possible(int nums[], int n, int m, long long mid) {
    int count = 1; //keeps track of the number of subarrays formed
    long long total = 0;
    for (int i = 0; i < n; i++) {
        total += nums[i];
        if (total > mid) {
            total = nums[i];
            count++;
            if (count > m) return 0;
        }
    }
    return 1;
}

// Function to find minimum largest sum
long long split_array(int nums[], int n, int m) {
    long long max_element = 0, sum = sum_array_elements(nums, n);
    for (int i = 0; i < n; i++) {
        if (nums[i] > max_element) max_element = nums[i];
    }

    long long low = max_element, high = sum, result = sum;
    while (low <= high) {
        long long mid = (low + high) / 2;
        //mid is a guess for potential minimum largest value	
        if (is_possible(nums, n, m, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    int n; 
    scanf("%d", &n); 

    int m; 
    scanf("%d", &m); 

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); 
    }
    
    printf("Minimum largest sum: %lld\n", split_array(arr, n, m));
    return 0;
}


