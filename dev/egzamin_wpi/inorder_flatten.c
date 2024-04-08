/*

Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

The idea is to maintain a current node pointer that points to the last node processed. As you perform the in-order traversal, you set the current node's right child to the newly visited node and clear its left child. This way, you link all nodes in ascending order directly, without needing an auxiliary structure.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Helper function to create a new node
TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Function prototypes
void inOrderFlatten(TreeNode* root, TreeNode** prev);

// Main function to rearrange the BST
TreeNode* increasingBST(TreeNode* root) {
    TreeNode* dummy = newNode(0);  // Create a dummy node
    TreeNode* prev = dummy;  // Use prev to keep track of the last processed node

    inOrderFlatten(root, &prev);

    TreeNode* newRoot = dummy->right;  // The right child of dummy is the new root
    free(dummy);  // Free the dummy node
    return newRoot;
}

// Helper function to rearrange the BST in in-order directly
void inOrderFlatten(TreeNode* node, TreeNode** prev) {
    if (node == NULL) return;

    inOrderFlatten(node->left, prev);  // Traverse the left subtree

    // Rearrange the current node
    (*prev)->right = node;  // Link the previous node's right to the current node
    node->left = NULL;  // Clear the current node's left child
    *prev = node;  // Update the previous node to the current node

    inOrderFlatten(node->right, prev);  // Traverse the right subtree
}

// Add your functions to create and free the BST as needed

