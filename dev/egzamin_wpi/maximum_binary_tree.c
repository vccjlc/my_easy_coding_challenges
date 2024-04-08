/*

You are given an integer array nums with no duplicates. A maximum binary tree can be built recursively from nums using the following algorithm:

Create a root node whose value is the maximum value in nums.
Recursively build the left subtree on the subarray prefix to the left of the maximum value.
Recursively build the right subtree on the subarray suffix to the right of the maximum value.
Return the maximum binary tree built from nums.

To build a maximum binary tree from an integer array nums without duplicates by following the algorithm you've provided, we can implement a recursive function in C. This function will find the maximum value in the current subarray to create a root node, and then recursively call itself to construct the left and right subtrees from the subarrays to the left and right of the maximum value, respectively.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new TreeNode
TreeNode* newTreeNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Function to find the index of the maximum value in the array
int findMaxIndex(int nums[], int left, int right) {
    int maxIndex = left;
    for (int i = left; i <= right; i++) {
        if (nums[i] > nums[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Recursive function to construct the Maximum Binary Tree
TreeNode* constructMaximumBinaryTreeHelper(int nums[], int left, int right) {
    if (left > right) return NULL;  // Base case

    // Find the index of the maximum value in the current subarray
    int maxIndex = findMaxIndex(nums, left, right);

    // Create a root node with the maximum value
    TreeNode* root = newTreeNode(nums[maxIndex]);

    // Recursively build the left subtree
    root->left = constructMaximumBinaryTreeHelper(nums, left, maxIndex - 1);

    // Recursively build the right subtree
    root->right = constructMaximumBinaryTreeHelper(nums, maxIndex + 1, right);

    return root;
}

// Main function to be called to construct the Maximum Binary Tree
TreeNode* constructMaximumBinaryTree(int nums[], int numsSize) {
    return constructMaximumBinaryTreeHelper(nums, 0, numsSize - 1);
}

// A utility function to print the pre-order traversal of the binary tree
void preOrderTraversal(TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Example usage
int main() {
    int nums[] = {3, 2, 1, 6, 0, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    TreeNode* root = constructMaximumBinaryTree(nums, numsSize);
    
    // Print pre-order traversal of the maximum binary tree
    printf("Pre-order Traversal of the Maximum Binary Tree:\n");
    preOrderTraversal(root);
    printf("\n");

    // Free allocated memory
    // ... (You would add code here to free the tree nodes)
    
    return 0;
}

