/*

Given a binary tree, determine if it is 
height-balanced. A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
} TreeNode;

// Helper function to calculate the absolute difference
int absDiff(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
}

// Recursive function to check if the binary tree is height-balanced
int checkHeight(TreeNode* root) {
    // An empty tree is height-balanced
    if (root == NULL) return 0;

    // Check the height of the left and right subtrees
    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) return -1;  // Left subtree is not balanced

    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1) return -1;  // Right subtree is not balanced

    // If the current node's subtrees are balanced but their heights differ by more than 1, return -1
    if (absDiff(leftHeight, rightHeight) > 1) return -1;

    // Return the height of the current subtree
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Main function to determine if the tree is height-balanced
int isBalanced(TreeNode* root) {
    return checkHeight(root) != -1;
}

