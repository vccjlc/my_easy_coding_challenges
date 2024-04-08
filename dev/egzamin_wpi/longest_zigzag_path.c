/*

You are given the root of a binary tree.

A ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
Change the direction from right to left or from left to right.
Repeat the second and third steps until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.

***


To find the longest ZigZag path in a binary tree, you can use a recursive depth-first search (DFS) approach. The key is to keep track of two things at each node: the maximum length of a ZigZag path starting at that node and going left first, and the maximum length of a ZigZag path starting at that node and going right first.

For each node, you will return two values to its parent:

The maximum ZigZag length going left then right (which is 1 + the maximum ZigZag length of the right child going right then left).
The maximum ZigZag length going right then left (which is 1 + the maximum ZigZag length of the left child going left then right).
You also keep a global variable to keep track of the maximum ZigZag length found during the traversal.


*/



#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Helper function to create a new tree node
TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Utility structure to return two values from the recursive function
typedef struct ZigZagLength {
    int leftToRight;
    int rightToLeft;
} ZigZagLength;

int maxZigZag = 0;

// Recursive DFS function to calculate ZigZag lengths
ZigZagLength dfs(TreeNode* node) {
    if (!node) {
        return (ZigZagLength){0, 0};
    }

    ZigZagLength left = dfs(node->left);
    ZigZagLength right = dfs(node->right);

    // Calculate ZigZag lengths for the current node
    ZigZagLength current;
    current.leftToRight = 1 + left.rightToLeft;
    current.rightToLeft = 1 + right.leftToRight;

    // Update the global maximum ZigZag length
    if (current.leftToRight > maxZigZag) maxZigZag = current.leftToRight;
    if (current.rightToLeft > maxZigZag) maxZigZag = current.rightToLeft;

    return current;
}

// Main function to find the longest ZigZag path in the binary tree
int longestZigZag(TreeNode* root) {
    maxZigZag = 0;
    dfs(root);
    return maxZigZag - 1;  // Subtract 1 because ZigZag length is defined as the number of nodes visited - 1
}

// Example usage
int main() {
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->left = newNode(5);
    root->left->right->right = newNode(6);
    root->right->right = newNode(7);
    root->right->right->right = newNode(8);

    int result = longestZigZag(root);
    printf("Longest ZigZag path: %d\n", result);

    // Free the allocated memory for the tree nodes (not shown here)

    return 0;
}

