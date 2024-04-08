/*

Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.\

***

To count the number of "good nodes" in a binary tree, where a good node is defined as a node where in the path from the root to that node, there are no nodes with a value greater than the value of that node, you can use a Depth-First Search (DFS) approach. During the DFS, keep track of the maximum value seen along the path from the root to the current node. A node is considered "good" if its value is greater than or equal to this maximum value.


*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MIN

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Helper function to create a new tree node
TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Recursive DFS function to count good nodes
int dfs(TreeNode* node, int maxVal) {
    if (node == NULL) return 0;

    int count = 0;
    // A node is good if its value is greater than or equal to the maximum value seen so far
    if (node->val >= maxVal) {
        count = 1; // Current node is good
        maxVal = node->val; // Update maxVal for the path
    }

    // Count good nodes in the left and right subtrees
    count += dfs(node->left, maxVal);
    count += dfs(node->right, maxVal);

    return count;
}

// Function to return the number of good nodes in the binary tree
int goodNodes(TreeNode* root) {
    return dfs(root, INT_MIN); // Start DFS with the minimum integer as the initial maximum value
}

// Example usage
int main() {
    // Construct the binary tree
    TreeNode* root = newNode(3);
    root->left = newNode(1);
    root->right = newNode(4);
    root->left->left = newNode(3);
    root->right->left = newNode(1);
    root->right->right = newNode(5);

    int result = goodNodes(root);
    printf("Number of good nodes: %d\n", result);

    // Free the allocated memory for the tree nodes (not shown here)

    return 0;
}

