#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MAX

typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
} TreeNode;

// Function to create a new tree node
TreeNode* createTreeNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive function to find the minimum depth of the binary tree
int minDepth(TreeNode* root) {
    // Base case: empty tree
    if (root == NULL) return 0;

    // Base case: leaf node
    if (root->left == NULL && root->right == NULL) return 1;

    // If left subtree is empty, recurse on right subtree
    if (root->left == NULL) return 1 + minDepth(root->right);

    // If right subtree is empty, recurse on left subtree
    if (root->right == NULL) return 1 + minDepth(root->left);

    // If neither subtree is empty, take the minimum of the two depths
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);

    return 1 + (leftDepth < rightDepth ? leftDepth : rightDepth);
}

