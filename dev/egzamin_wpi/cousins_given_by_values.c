/*

Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.


To check if two nodes are cousins in a binary tree, we need to ensure that:

The two nodes are at the same depth in the tree.
The two nodes have different parents.
We can achieve this by performing a Depth-First Search (DFS) where we track the depth and parent of each node as we traverse the tree. When we find the nodes corresponding to the given values x and y, we can compare their depths and parents to determine if they are cousins.



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

// Helper function to perform DFS and track the depth and parent of target nodes
void dfs(TreeNode* node, int x, int y, int depth, TreeNode* parent, int* xDepth, int* yDepth, TreeNode** xParent, TreeNode** yParent) {
    if (!node) return;

    if (node->val == x) {
        *xDepth = depth;
        *xParent = parent;
    } else if (node->val == y) {
        *yDepth = depth;
        *yParent = parent;
    }

    // Continue DFS in the left and right subtrees, incrementing depth
    dfs(node->left, x, y, depth + 1, node, xDepth, yDepth, xParent, yParent);
    dfs(node->right, x, y, depth + 1, node, xDepth, yDepth, xParent, yParent);
}

// Main function to check if two nodes are cousins
bool isCousins(TreeNode* root, int x, int y) {
    int xDepth = -1, yDepth = -1; // Initialize depths
    TreeNode *xParent = NULL, *yParent = NULL; // Initialize parents

    dfs(root, x, y, 0, NULL, &xDepth, &yDepth, &xParent, &yParent);

    // Check if x and y are at the same depth and have different parents
    return (xDepth == yDepth) && (xParent != yParent);
}

// Example usage
int main() {
    // Construct a binary tree
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->right = newNode(5);

    // Check if nodes 4 and 5 are cousins
    bool result = isCousins(root, 4, 5);
    if (result) {
        printf("The nodes are cousins.\n");
    } else {
        printf("The nodes are not cousins.\n");
    }

    // Free the allocated memory for the tree nodes (not shown here)

    return 0;
}

