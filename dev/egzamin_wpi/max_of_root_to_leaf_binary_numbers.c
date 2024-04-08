/* RETURN MAX ROOT TO LEAF BINARY NUMBER

You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a  binary starting with the most significant bit.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the maximum of these numbers.


To find the maximum number represented by a root-to-leaf path in a binary tree where each node has a value of 0 or 1, with each path representing a binary number starting with the most significant bit, you can use a depth-first search (DFS) approach. As you traverse the tree from the root to each leaf, you construct the binary number represented by the path. When a leaf node is reached, compare the number formed by the current path with the current maximum number and update the maximum if necessary.


*/


#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val; // Node value can be 0 or 1
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to perform DFS traversal and find the maximum binary number.
void findMaxBinaryNumber(struct TreeNode* node, int currentNum, int* maxNum) {
    if (node == NULL) return; // Base case: empty node

    // Update the current number by appending the current node's binary value.
    // This is done by left shifting currentNum by 1 (to make space for the new bit)
    // and then using bitwise OR with the node's value to add the bit at the end.
    currentNum = (currentNum << 1) | node->val;

    // Check if the current node is a leaf
    if (node->left == NULL && node->right == NULL) {
        // Update maxNum if the current number is greater than the maxNum
        if (currentNum > *maxNum) {
            *maxNum = currentNum;
        }
    } else {
        // Continue DFS traversal on left and right children
        findMaxBinaryNumber(node->left, currentNum, maxNum);
        findMaxBinaryNumber(node->right, currentNum, maxNum);
    }
}

// Function to return the maximum binary number represented by any root-to-leaf path.
int maxBinaryNumberFromRootToLeaf(struct TreeNode* root) {
    int maxNum = 0;
    findMaxBinaryNumber(root, 0, &maxNum); // Start DFS with the root, initial number is 0
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
    //     1   0
    //    / \   \
    //   0   1   1
    struct TreeNode* root = newNode(1);
    root->left = newNode(1);
    root->right = newNode(0);
    root->left->left = newNode(0);
    root->left->right = newNode(1);
    root->right->right = newNode(1);

    int maxNumber = maxBinaryNumberFromRootToLeaf(root);
    printf("Maximum Binary Number from Root to Leaf: %d\n", maxNumber);

    // Free allocated memory for the tree nodes (omitted for brevity)

    return 0;
}

