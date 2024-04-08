/*

Given the root of a binary tree, return the most frequent subtree sum. If there is a tie, return all the values with the highest frequency in any order.

The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).

To solve this problem, we can perform a post-order traversal of the binary tree. During the traversal, we compute the sum of each subtree, keep track of the frequency of each sum, and update the maximum frequency and the list of sums with the maximum frequency accordingly. Finally, we return the list of sums with the maximum frequency.

*/



#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// A utility function to create a new Binary Tree node
TreeNode* newNode(int data) {
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->val = data;
    temp->left = temp->right = NULL;
    return temp;
}

// A structure to store sum and its frequency
typedef struct SumFreq {
    int sum;
    int freq;
} SumFreq;

// A utility function to create a SumFreq
SumFreq* newSumFreq(int sum) {
    SumFreq* temp = (SumFreq*)malloc(sizeof(SumFreq));
    temp->sum = sum;
    temp->freq = 1;
    return temp;
}

// Function to find a sum in SumFreq array
SumFreq* findSum(SumFreq* arr, int size, int sum) {
    for (int i = 0; i < size; ++i) {
        if (arr[i].sum == sum) {
            return &arr[i];
        }
    }
    return NULL;
}

// Recursive function to find subtree sum and update SumFreq array
int findSubtreeSums(TreeNode* root, SumFreq* sums, int* size, int* maxFreq, int* resultSize) {
    if (root == NULL) {
        return 0;
    }

    int leftSum = findSubtreeSums(root->left, sums, size, maxFreq, resultSize);
    int rightSum = findSubtreeSums(root->right, sums, size, maxFreq, resultSize);
    int sum = root->val + leftSum + rightSum;

    SumFreq* sumFreq = findSum(sums, *size, sum);
    if (sumFreq) {
        sumFreq->freq++;
    } else {
        sums[*size] = *newSumFreq(sum);
        (*size)++;
    }

    if (sumFreq && sumFreq->freq > *maxFreq) {
        *maxFreq = sumFreq->freq;
        *resultSize = 1;
    } else if (sumFreq && sumFreq->freq == *maxFreq) {
        (*resultSize)++;
    }

    return sum;
}

// Function to return the most frequent subtree sum
int* findFrequentTreeSum(TreeNode* root, int* returnSize) {
    SumFreq sums[1000]; // Assuming the size of the tree does not exceed 1000 nodes
    int size = 0;
    int maxFreq = 0;
    int resultSize = 0;

    findSubtreeSums(root, sums, &size, &maxFreq, &resultSize);

    int* result = (int*)malloc(resultSize * sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < size; ++i) {
        if (sums[i].freq == maxFreq) {
            result[(*returnSize)++] = sums[i].sum;
        }
    }

    return result;
}

