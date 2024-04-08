/*

Given a zero-based permutation nums (0-indexed), build an array ans of the same length where ans[i] = nums[nums[i]] for each 0 <= i < nums.length and return it.

A zero-based permutation nums is an array of distinct integers from 0 to nums.length - 1 (inclusive).

Memory O(1)

*/

int* buildArray(int* nums, int numsSize, int* returnSize) {
    
    int final;

    for (int i = 0; i < numsSize; ++i) {
        if (i > nums[i]) { // Check if we have to get the final number from already modified position
            final = nums[nums[i]] % numsSize; // Get the final number from modified position
        } else {
            final = nums[nums[i]]; // Get the final number from "fresh" position
        }

        nums[i] = nums[i] + numsSize * final;
    }

    for (int i = 0; i < numsSize; ++i) { // Retrieve original numbes
        nums[i] = nums[i] / numsSize;
    }

    *returnSize = numsSize;
    return nums;
}

/*
Explanation:

Constraints are given, so at each position we store the number: original + final * numsSize

To get them back, we reverse the operation:
To retrieve original, do number % numsSize
To retrieve final, do number / numsSize
*/
