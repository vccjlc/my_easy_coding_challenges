/*

You are given the root of a binary tree where each node has a value 0-9. Each leaf-to-root path represents a  number starting with the most significant bit.

For all leaves in the tree, consider the numbers represented by the path from the leaf to that root. Return the maximum of these numbers.


To find the maximum number represented by a leaf-to-root path in a binary tree where each node has a value from 0 to 9, we can use a depth-first search (DFS) approach similar to the previous solution. The difference here is that each node's value can range from 0 to 9, and we're treating each path as a decimal number rather than a binary number.


*/

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val; // Node value can be from 0 to 9
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to perform DFS traversal and find the maximum number.
void findMaxDecimalPath(struct TreeNode* node, int currentNum, int* maxNum) {
    if (node == NULL) return; // Base case: empty node

    // Update the current number by shifting it one decimal place and adding the node's value.
    currentNum = currentNum * 10 + node->val;

    // Check if the current node is a leaf
    if (node->left == NULL && node->right == NULL) {
        // Update maxNum if the current number is greater than the maxNum
        if (currentNum > *maxNum) {
            *maxNum = currentNum;
        }
    } else {
        // Continue DFS traversal on left and right children
        findMaxDecimalPath(node->left, currentNum, maxNum);
        findMaxDecimalPath(node->right, currentNum, maxNum);
    }
}

// Function to return the maximum number represented by any leaf-to-root path.
int maxDecimalRootToLeaf(struct TreeNode* root) {
    int maxNum = 0;
    findMaxDecimalPath(root, 0, &maxNum); // Start DFS with the root, initial number is 0
    return maxNum;
}

// Utility function to create a new TreeNode
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Example usage
int main() {
    // Construct an example tree:
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    int maxNumber = maxDecimalRootToLeaf(root);
    printf("Maximum Number from Leaf to Root: %d\n", maxNumber);

    // Free allocated memory for the tree nodes (omitted for brevity)

    return 0;
}

