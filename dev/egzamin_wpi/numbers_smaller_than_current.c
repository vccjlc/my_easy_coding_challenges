/*


Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.


*/


void findSmallerCounts(int* nums, int numsSize, int* result) {
    int i, min = nums[0], max = nums[0];

    // Step 1: Find the range
    for (i = 1; i < numsSize; i++) {
        if (nums[i] < min) min = nums[i];
        if (nums[i] > max) max = nums[i];
    }

    int range = max - min + 1;
    int count[range];
    memset(count, 0, sizeof(count));

    // Step 2: Count frequencies
    for (i = 0; i < numsSize; i++) {
        count[nums[i] - min]++;
    }

    // Step 3: Compute prefix sums
    for (i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Step 4: Generate result
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == min) {
            result[i] = 0;
        } else {
            result[i] = count[nums[i] - min - 1];
        }
    }
}
