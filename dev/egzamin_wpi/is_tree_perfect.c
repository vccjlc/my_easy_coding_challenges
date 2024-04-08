#include <stdbool.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to calculate the depth of the tree ONLY USE TO CHECK IF TREE IS PERFECT
int depth(struct TreeNode* node) {
    int d = 0;
    while (node != NULL) {
        d++;
        node = node->left; // Go as left as possible to find the depth
    }
    return d;
}

// Function to check if a binary tree is perfect
bool isPerfect(struct TreeNode* root) {
    if (!root) return true;

    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);

    // Check if the depths of the left and right subtrees are the same
    if (leftDepth != rightDepth) return false;

    // Recursively check if the left and right subtrees are perfect
    return isPerfect(root->left) && isPerfect(root->right);
}

