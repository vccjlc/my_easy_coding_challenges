// RETURN SUM OF LEAF_TO_ROOT BINARY NUMBERS

/*

You are given the root of a binary tree where each node has a value 0 or 1. Each leaf-to-root path represents a binary number starting with the most significant bit.

For all leaves in the tree, consider the numbers represented by the path from the leaf to that root. Return the sum of these numbers.

***

To solve this problem, we can perform a depth-first search (DFS) traversal of the binary tree. During the traversal, we keep track of the current number by appending the node's value (0 or 1) as we move down from the root to the leaves. When we reach a leaf node, we add the number represented by the path from the root to that leaf to the total sum.




*/
#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to perform DFS traversal and compute the sum of leaf numbers.
void dfs(struct TreeNode* node, int currentNum, int* totalSum) {
    if (node == NULL) return; // Base case: empty node

    // Update the current number. Left shift currentNum by 1 position and add the node's value.
    currentNum = (currentNum << 1) | node->val;

    // Check if the current node is a leaf
    if (node->left == NULL && node->right == NULL) {
        // Add the current number to the total sum
        *totalSum += currentNum;
    } else {
        // Continue DFS traversal on left and right children
        dfs(node->left, currentNum, totalSum);
        dfs(node->right, currentNum, totalSum);
    }
}

// Function to return the sum of numbers represented by all leaf-to-root paths.
int sumRootToLeaf(struct TreeNode* root) {
    int totalSum = 0;
    dfs(root, 0, &totalSum); // Start DFS with the root, initial number is 0
    return totalSum;
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

    int total = sumRootToLeaf(root);
    printf("Total Sum of Leaf Numbers: %d\n", total);

    // Free allocated memory for the tree nodes (omitted for brevity)

    return 0;
}

