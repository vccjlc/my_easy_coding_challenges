/*

Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

Return the array in the form [x1,y1,x2,y2,...,xn,yn].

*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    *returnSize = numsSize;
    int* returnArray = malloc(*returnSize * sizeof(int));

    for (int i = 0; i < n; ++i) {
        returnArray[2*i] = nums[i];
        returnArray[2*i + 1] = nums[n+i];
    }
    
    return returnArray;
}
