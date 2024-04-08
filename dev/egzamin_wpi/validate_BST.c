/*
To determine if a given binary tree is a valid Binary Search Tree (BST), we can use a recursive approach that leverages the BST property: for every node, all nodes in the left subtree must have values less than the node's value, and all nodes in the right subtree must have values greater than the node's value. This condition must hold for every node in the tree.

To enforce the BST rules, we can pass down the valid value range for each node from its parent. Initially, the range is infinite. As we traverse down the tree, we narrow the range for the left and right children based on the current node's value.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MIN and INT_MAX

typedef struct TreeNode {
    int value;
    struct TreeNode *left, *right;
} TreeNode;

// Helper function to validate the BST
int validateBSTUtil(TreeNode* node, long minVal, long maxVal) {
    // Base case: An empty tree is a valid BST
    if (node == NULL) return 1;

    // Check if the current node violates the min/max constraints
    if (node->value <= minVal || node->value >= maxVal) return 0;

    // Recursively check the left and right subtrees with updated constraints
    return validateBSTUtil(node->left, minVal, node->value) && validateBSTUtil(node->right, node->value, maxVal);
}

// Main function to determine if the binary tree is a valid BST
int isValidBST(TreeNode* root) {
    // Call the helper function with initial min and max values
    return validateBSTUtil(root, LONG_MIN, LONG_MAX);
}

