// write a function to find the distance of a given node from the root


/*

Finding the distance of a given node from the root of a binary tree involves traversing the tree from the root to the given node and counting the number of edges along the path. This can be efficiently done using a depth-first search (DFS) approach.


*/


#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to find the distance of a given node from the root.
// 'root' is the root of the tree, and 'value' is the value of the node whose distance from the root is to be found.
int findDistanceFromRoot(struct TreeNode* root, int value) {
    // Helper function to perform DFS and find the distance.
    int dfs(struct TreeNode* node, int value, int depth) {
        if (node == NULL) {
            return -1; // Node not found, return -1.
        }
        if (node->val == value) {
            return depth; // Node found, return current depth.
        }

        // Search the left subtree.
        int left = dfs(node->left, value, depth + 1);
        if (left != -1) return left; // If found in left subtree, no need to search right.

        // Search the right subtree.
        return dfs(node->right, value, depth + 1);
    }

    // Start DFS from the root with initial depth 0.
    return dfs(root, value, 0);
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
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int value = 4; // The value of the node whose distance from the root is to be found
    int distance = findDistanceFromRoot(root, value);
    printf("Distance of node %d from the root is: %d\n", value, distance);

    // Free allocated memory for the tree nodes (omitted for brevity)

    return 0;
}

