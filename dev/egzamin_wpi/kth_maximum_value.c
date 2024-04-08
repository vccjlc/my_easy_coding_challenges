// Return kth maximum value from a BST

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to create a new tree node.
struct TreeNode* createNode(int value) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = value;
    node->left = node->right = NULL;
    return node;
}

// Helper function to perform reverse in-order traversal.
int reverseInorderTraversal(struct TreeNode* node, int* k) {
    // Base case
    if (node == NULL) return -1;

    // Search in right subtree first
    int val = reverseInorderTraversal(node->right, k);
    if (*k == 0) return val; // If kth largest is already found

    // Decrement k after visiting right subtree
    *k = *k - 1;
    if (*k == 0) return node->val; // If current node is the kth largest

    // If not found in right subtree, search in left subtree
    return reverseInorderTraversal(node->left, k);
}

// Function to find the kth maximum value in the BST.
int findKthMaximum(struct TreeNode* root, int k) {
    return reverseInorderTraversal(root, &k);
}

int main() {
    // Example usage:
    struct TreeNode* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(7);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->right->left = createNode(6);
    root->right->right = createNode(8);

    int k = 3; // Change k to find the kth maximum value
    int kthMax = findKthMaximum(root, k);
    if (kthMax != -1) {
        printf("The %d-th maximum value is: %d\n", k, kthMax);
    } else {
        printf("The tree does not have %d-th maximum value.\n", k);
    }

    // Don't forget to free the memory for the nodes in a real program!
    return 0;
}



