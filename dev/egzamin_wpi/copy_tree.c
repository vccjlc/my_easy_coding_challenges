#include <stdlib.h> // For malloc

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node with a given value.
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (!node) { // Check if malloc was successful
        return NULL; // In case malloc fails, return NULL
    }
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to copy a tree.
struct TreeNode* copyTree(struct TreeNode* root) {
    if (root == NULL) {
        return NULL; // If the current node is NULL, return NULL.
    }

    // Create a new node with the same value as the root node.
    struct TreeNode* newRoot = newNode(root->val);

    // Recursively copy the left and right subtrees.
    newRoot->left = copyTree(root->left);
    newRoot->right = copyTree(root->right);

    return newRoot; // Return the new tree's root node.
}

