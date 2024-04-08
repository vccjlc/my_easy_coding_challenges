/* RETURN MAX OF LEAF-TO-ROOT binary numbers


You are given the root of a binary tree where each node has a value 0 or 1. Each leaf-to-root path represents a binary number starting with the most significant bit.

For all leaves in the tree, consider the numbers represented by the path from the leaf to that root. Return the maximum of these numbers.


To find the maximum number represented by a leaf-to-root path in a binary tree where each node has a value of 0 or 1, you can modify the depth-first search (DFS) approach used for summing the numbers. Instead of summing the numbers, you track the maximum number encountered as you traverse the tree from the root to each leaf.


*/

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to perform DFS traversal and find the maximum number.
void findMaxPath(struct TreeNode* node, int currentNum, int* maxNum) {
    if (node == NULL) return; // Base case: empty node

    // Update the current number. Left shift currentNum by 1 position and add the node's value.
    currentNum = (currentNum << 1) | node->val;

    // Check if the current node is a leaf
    if (node->left == NULL && node->right == NULL) {
        // Update maxNum if the current number is greater than the maxNum
        if (currentNum > *maxNum) {
            *maxNum = currentNum;
        }
    } else {
        // Continue DFS traversal on left and right children
        findMaxPath(node->left, currentNum, maxNum);
        findMaxPath(node->right, currentNum, maxNum);
    }
}

// Function to return the maximum number represented by any leaf-to-root path.
int maxRootToLeaf(struct TreeNode* root) {
    int maxNum = 0;
    findMaxPath(root, 0, &maxNum); // Start DFS with the root, initial number is 0
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
    //     0   1
    //    / \   \
    //   0   1   0
    struct TreeNode* root = newNode(1);
    root->left = newNode(0);
    root->right = newNode(1);
    root->left->left = newNode(0);
    root->left->right = newNode(1);
    root->right->right = newNode(0);

    int maxNumber = maxRootToLeaf(root);
    printf("Maximum Number from Leaf to Root: %d\n", maxNumber);

    // Free allocated memory for the tree nodes (omitted for brevity)

    return 0;
}



