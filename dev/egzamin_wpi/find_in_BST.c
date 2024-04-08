/*

You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Helper function to create a new TreeNode
TreeNode* createTreeNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to search for a value in the BST and return the subtree rooted with that node
TreeNode* searchBST(TreeNode* root, int val) {
    if (root == NULL || root->val == val) {
        // If the root is null or the root's value is the one we're searching for, return the root
        return root;
    } else if (val < root->val) {
        // If the value is less than the root's value, search in the left subtree
        return searchBST(root->left, val);
    } else {
        // If the value is greater than the root's value, search in the right subtree
        return searchBST(root->right, val);
    }
}

int main() {
    // Example usage:
    // Create a BST
    TreeNode* root = createTreeNode(4);
    root->left = createTreeNode(2);
    root->right = createTreeNode(7);
    root->left->left = createTreeNode(1);
    root->left->right = createTreeNode(3);

    int val = 2;
    TreeNode* result = searchBST(root, val);

    if (result) {
        printf("Subtree rooted at node with value %d found.\n", val);
        // Print subtree, handle or free the subtree as needed
    } else {
        printf("Node with value %d not found in the BST.\n", val);
    }

    // Free memory if needed and perform other cleanups

    return 0

