/* RETURN MAX LEAF-TO-ROOT

You are given the root of a binary tree where each node has a value 0-9. Each leaf-to-root path represents a  number starting with the most significant bit.

For all leaves in the tree, consider the numbers represented by the path from the leaf to that root. Return the maximum of these numbers.


To find the sum of the numbers represented by each leaf-to-root path in a binary tree where each node has a value from 0 to 9, we can use a depth-first search (DFS) approach. As we traverse from the root to each leaf, we build the numbers by shifting the current value by one decimal place to the left (multiplying by 10) and then adding the value of the current node.


*/

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val; // Node value can be from 0 to 9
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to perform DFS traversal and compute the sum of leaf numbers.
void sumLeafNumbers(struct TreeNode* node, int currentSum, int* totalSum) {
    if (node == NULL) return; // Base case: empty node

    // Update the current sum by shifting it one decimal place and adding the node's value.
    currentSum = currentSum * 10 + node->val;

    // Check if the current node is a leaf
    if (node->left == NULL && node->right == NULL) {
        // Add the current sum to the total sum
        *totalSum += currentSum;
    } else {
        // Continue DFS traversal on left and right children
        sumLeafNumbers(node->left, currentSum, totalSum);
        sumLeafNumbers(node->right, currentSum, totalSum);
    }
}

// Function to return the sum of numbers represented by all leaf-to-root paths.
int sumNumbers(struct TreeNode* root) {
    int totalSum = 0;
    sumLeafNumbers(root, 0, &totalSum); // Start DFS with the root, initial sum is 0
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
    //     2   3
    //    / \   \
    //   4   5   6
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    int total = sumNumbers(root);
    printf("Total Sum of Leaf Numbers: %d\n", total);

    // Free allocated memory for the tree nodes (omitted for brevity)

    return 0;
}


