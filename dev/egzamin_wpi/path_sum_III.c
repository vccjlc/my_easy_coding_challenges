/*

Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).


This problem can be approached by traversing the tree and checking, at each node, the number of paths that sum up to the targetSum. A recursive function can keep track of the current path sums and increment a counter each time a sum equals the targetSum.

Here's an efficient C implementation using a recursive depth-first search (DFS):

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new TreeNode
TreeNode* createTreeNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Helper function to count paths with the given sum starting from the current node
int countPaths(TreeNode* node, long currentSum, int targetSum) {
    if (node == NULL) return 0;
    
    currentSum += node->val;
    int totalPaths = (currentSum == targetSum) ? 1 : 0;

    // Count paths including the left child
    totalPaths += countPaths(node->left, currentSum, targetSum);
    // Count paths including the right child
    totalPaths += countPaths(node->right, currentSum, targetSum);

    return totalPaths;
}

// Main function to count all paths with the given sum
int pathSum(TreeNode* root, int targetSum) {
    if (root == NULL) return 0;

    // Count paths starting from the root
    int pathsFromRoot = countPaths(root, 0, targetSum);

    // Try to find paths from left and right child independently
    int pathsFromLeft = pathSum(root->left, targetSum);
    int pathsFromRight = pathSum(root->right, targetSum);

    // Total paths is the sum of paths from the root, left child, and right child
    return pathsFromRoot + pathsFromLeft + pathsFromRight;
}

int main() {
    // Assume createTreeNode function is given and the tree is created

    // Example usage
    TreeNode* root = createTreeNode(10);
    root->left = createTreeNode(5);
    root->right = createTreeNode(-3);
    root->left->left = createTreeNode(3);
    root->left->right = createTreeNode(2);
    root->right->right = createTreeNode(11);
    root->left->left->left = createTreeNode(3);
    root->left->left->right = createTreeNode(-2);
    root->left->right->right = createTreeNode(1);

    int targetSum = 8;
    int result = pathSum(root, targetSum);
    printf("Number of paths with sum %d: %d\n", targetSum, result);

    // Free memory if needed and perform other cleanups

    return 0;
}

