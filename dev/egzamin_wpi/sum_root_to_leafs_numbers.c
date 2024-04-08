/*

You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.

*/


#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
} TreeNode;

// Helper function to calculate the sum of root-to-leaf numbers
int sumNumbersDFS(TreeNode* root, int currentSum) {
    if (root == NULL) return 0;
    
    // Update the current sum by incorporating the current node's value
    currentSum = currentSum * 10 + root->val;

    // If it's a leaf node, return the current sum
    if (root->left == NULL && root->right == NULL) {
        return currentSum;
    }

    // Recursively calculate the sum for left and right subtrees and add them
    return sumNumbersDFS(root->left, currentSum) + sumNumbersDFS(root->right, currentSum);
}

// Main function to find the total sum of all root-to-leaf numbers
int sumNumbers(TreeNode* root) {
    return sumNumbersDFS(root, 0);
}

