// Write a function to find the distance of a given node to the deepest leaf


/*

To find the distance of a given node to the deepest leaf in a binary tree, you can use a depth-first search (DFS) approach. The idea is to traverse the tree to find the maximum depth (the level of the deepest leaf) and then calculate the distance from the given node to this deepest level.

This can be achieved by first writing a helper function to find the depth of the tree, and then using this depth information to calculate the distance from the given node to the deepest leaf.

*/


#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to find the depth of the tree.
int findDepth(struct TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    int leftDepth = findDepth(node->left);
    int rightDepth = findDepth(node->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

// Function to find the distance of a given node to the deepest leaf.
// 'node' is the root of the tree, and 'value' is the value of the node whose distance to the deepest leaf is to be found.
int findDistanceToDeepestLeaf(struct TreeNode* root, int value) {
    if (root == NULL) {
        return -1; // Return -1 if the root is NULL or the value is not found in the tree.
    }
    
    // Find the overall depth of the tree.
    int maxDepth = findDepth(root);
    
    // Define a helper function to find the node and its depth.
    int findNodeDepth(struct TreeNode* node, int value, int depth) {
        if (node == NULL) {
            return 0;
        }
        if (node->val == value) {
            return depth;
        }
        int left = findNodeDepth(node->left, value, depth + 1);
        if (left) return left; // If found in left subtree, no need to search right.
        return findNodeDepth(node->right, value, depth + 1);
    }

    // Find the depth of the given node.
    int nodeDepth = findNodeDepth(root, value, 1);
    
    // Calculate and return the distance from the given node to the deepest leaf.
    return maxDepth - nodeDepth;
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
    root->right->right = newNode(5);

    int value = 2; // The value of the node whose distance to the deepest leaf is to be found
    int distance = findDistanceToDeepestLeaf(root, value);
    printf("Distance of node %d to the

