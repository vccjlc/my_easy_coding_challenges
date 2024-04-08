// Copy all leaves of binary tree to array

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function for binary tree to recursively find leaves.
void findLeavesOfBinaryTree(struct TreeNode* node, int* leaves, int* count) {
    if (node == NULL) return;

    // Check if the node is a leaf
    if (node->left == NULL && node->right == NULL) {
        leaves[(*count)++] = node->val; // Add leaf value to array and increment count
    } else {
        findLeavesOfBinaryTree(node->left, leaves, count);
        findLeavesOfBinaryTree(node->right, leaves, count);
    }
}

// Function to copy all leaves of a binary tree to an array.
int* copyLeavesBinaryTree(struct TreeNode* root, int* returnSize) {
    int* leaves = (int*)malloc(1000 * sizeof(int)); // Allocate memory for leaves array
    *returnSize = 0; // Initialize return size
    findLeavesOfBinaryTree(root, leaves, returnSize);
    return leaves;
}

