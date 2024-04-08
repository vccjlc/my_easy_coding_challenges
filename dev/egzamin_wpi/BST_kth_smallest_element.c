// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

/*

To find the 
�
th smallest value in a Binary Search Tree (BST), you can perform an in-order traversal, which visits the nodes in ascending order. By keeping a count of the nodes visited, you can return the 
�
th node encountered during this traversal.

*/



#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
} TreeNode;

// Helper function to create a new TreeNode
TreeNode* createTreeNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive function to perform in-order traversal and find kth smallest value
void inOrderTraversal(TreeNode* node, int* k, int* kthValue) {
    if (node == NULL || *k == 0) return;

    // Traverse the left subtree
    inOrderTraversal(node->left, k, kthValue);

    // Visit the current node
    (*k)--;
    if (*k == 0) {
        *kthValue = node->val;
        return;
    }

    // Traverse the right subtree
    inOrderTraversal(node->right, k, kthValue);
}

// Main function to find the kth smallest value in the BST
int kthSmallest(TreeNode* root, int k) {
    int kthValue = -1;  // Initialize to an invalid value
    inOrderTraversal(root, &k, &kthValue);
    return kthValue;
}

