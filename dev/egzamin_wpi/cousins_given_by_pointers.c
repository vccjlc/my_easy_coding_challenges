/*
Given the root of a binary tree with unique values and the pointers of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.


If the two nodes are given by pointers instead of values, the approach to determine if they are cousins changes slightly. Since we have direct references to the nodes, we no longer need to search for them in the tree. However, we still need to determine their depths and their parents to check if they are cousins.

*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // For using bool in C

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new tree node
TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Helper function to find the depth and parent of a given node
bool findDepthAndParent(TreeNode* node, TreeNode* target, int depth, TreeNode* parent, int* targetDepth, TreeNode** targetParent) {
    if (!node) return false;

    if (node == target) {
        *targetDepth = depth;
        *targetParent = parent;
        return true;
    }

    // Search in the left subtree
    if (findDepthAndParent(node->left, target, depth + 1, node, targetDepth, targetParent)) return true;

    // Search in the right subtree
    return findDepthAndParent(node->right, target, depth + 1, node, targetDepth, targetParent);
}

// Main function to check if two nodes are cousins
bool isCousins(TreeNode* root, TreeNode* x, TreeNode* y) {
    int xDepth = -1, yDepth = -1; // Initialize depths
    TreeNode *xParent = NULL, *yParent = NULL; // Initialize parents

    // Find depth and parent for x
    findDepthAndParent(root, x, 0, NULL, &xDepth, &xParent);
    // Find depth and parent for y
    findDepthAndParent(root, y, 0, NULL, &yDepth, &yParent);

    // Check if x and y are at the same depth and have different parents
    return (xDepth == yDepth) && (xParent != yParent);
}

// Example usage
int main() {
    // Construct a binary tree
    TreeNode* root = newNode(1);
    TreeNode* node2 = newNode(2);
    TreeNode* node3 = newNode(3);
    TreeNode* node4 = newNode(4);
    TreeNode* node5 = newNode(5);
    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node3->right = node5;

    // Check if nodes 4 and 5 are cousins
    bool result = isCousins(root, node4, node5);
    if (result) {
        printf("The nodes are cousins.\n");
    } else {
        printf("The nodes are not cousins.\n");
    }

    // Free the allocated memory for the tree nodes (not shown here)

    return 0;
}

