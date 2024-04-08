#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode *left, *right;
} TreeNode;

// Helper function to check if two trees are mirror images of each other
int isMirror(TreeNode* tree1, TreeNode* tree2) {
    // If both trees are empty, then they are mirror images
    if (tree1 == NULL && tree2 == NULL) return 1;

    // If only one of the trees is empty, then they are not mirror images
    if (tree1 == NULL || tree2 == NULL) return 0;

    // The two trees are mirror images if:
    // 1. Their root values are the same
    // 2. The right subtree of each tree is a mirror image of the left subtree of the other tree
    return (tree1->value == tree2->value) && isMirror(tree1->left, tree2->right) && isMirror(tree1->right, tree2->left);
}

// Function to check if a binary tree is symmetric around its center
int isSymmetric(TreeNode* root) {
    // A tree is symmetric if the left subtree is a mirror image of the right subtree
    return isMirror(root, root);
}

