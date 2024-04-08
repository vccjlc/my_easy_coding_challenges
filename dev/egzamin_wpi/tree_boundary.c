/*

Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root. Boundary includes left boundary, leaves, and right boundary in order without duplicate nodes. (The values of the nodes may still be duplicates.)

Left boundary is defined as the path from root to the left-most node. Right boundary is defined as the path from root to the right-most node. If the root doesn't have left subtree or right subtree, then the root itself is left boundary or right boundary. Note this definition only applies to the input binary tree, and not applies to any subtrees.

The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if exists. If not, travel to the right subtree. Repeat until you reach a leaf node.
The right-most node is also defined by the same way with left and right exchanged.

To solve this problem, we need to break it into three parts:

Collect the left boundary nodes (excluding the left-most leaf node).
Collect the leaf nodes (from left to right).
Collect the right boundary nodes (excluding the right-most leaf node) in reverse.

After collecting these, we concatenate them in the order of left boundary, leaves, and reversed right boundary to get the final result. Here is a possible C implementation:
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Helper functions to check if a node is leaf
int isLeaf(TreeNode *node) {
    return (node->left == NULL) && (node->right == NULL);
}

// Collect left boundary excluding the leaf node
void leftBoundary(TreeNode *node, int *result, int *size) {
    TreeNode *cur = node;
    while (cur) {
        if (!isLeaf(cur)) {
            result[(*size)++] = cur->val;
        }
        if (cur->left) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
}

// Collect leaf nodes
void addLeaves(TreeNode *node, int *result, int *size) {
    if (isLeaf(node)) {
        result[(*size)++] = node->val;
        return;
    }
    if (node->left) {
        addLeaves(node->left, result, size);
    }
    if (node->right) {
        addLeaves(node->right, result, size);
    }
}

// Collect right boundary in reverse order excluding the leaf node
void rightBoundary(TreeNode *node, int *result, int *size) {
    TreeNode *cur = node;
    TreeNode *stack[1000]; // Assuming the height of the tree will not exceed 1000
    int top = -1;
    while (cur) {
        if (!isLeaf(cur)) {
            stack[++top] = cur;
        }
        if (cur->right) {
            cur = cur->right;
        } else {
            cur = cur->left;
        }
    }
    // Now add the right boundary to result in reverse order
    while (top >= 0) {
        result[(*size)++] = stack[top--]->val;
    }
}

// Main function to collect the boundary
int* boundaryOfBinaryTree(TreeNode *root, int *returnSize) {
    int *result = (int *)malloc(1000 * sizeof(int)); // Assuming the total nodes will not exceed 1000
    *returnSize = 0;
    if (!root) return result;
    if (!isLeaf(root)) {
        result[(*returnSize)++] = root->val;
    }
    leftBoundary(root->left, result, returnSize);
    addLeaves(root, result, returnSize);
    rightBoundary(root->right, result, returnSize);
    return result;
}

