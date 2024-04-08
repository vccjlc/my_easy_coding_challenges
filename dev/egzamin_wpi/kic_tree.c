/*

Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
} TreeNode;

// Function to create a new TreeNode
TreeNode* createTreeNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive function to flip the binary tree
TreeNode* flipBinaryTree(TreeNode* root) {
    // Base case: If the root is NULL or it's a leaf node, it becomes the new root.
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return root;
    }

    // Recursively call the function for the left child
    TreeNode* newRoot = flipBinaryTree(root->left);

    // Rearrange pointers
    root->left->left = root->right;  // The original right child becomes the new left child of the original left child
    root->left->right = root;        // The original parent becomes the new right child

    // Set the current root's pointers to NULL to avoid cycles
    root->left = NULL;
    root->right = NULL;

    return newRoot;  // The leftmost node becomes the new root
}

int main() {
    // Example usage
    TreeNode* root = createTreeNode(1);
    root->left = createTreeNode(2);
    root->right = createTreeNode(3);
    root->left->left = createTreeNode(4);
    root->left->right = createTreeNode(5);

    TreeNode* newRoot = flipBinaryTree(root);
    // newRoot now points to the new root of the flipped tree
    // Continue with further operations on newRoot...

    return 0;
}

