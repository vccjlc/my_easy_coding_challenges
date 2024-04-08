/*

Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.


To construct a Binary Search Tree (BST) from its preorder traversal, you can follow a recursive strategy. Given the nature of a BST and the properties of preorder traversal (root, left, right), the first element of the preorder array is always the root of the BST. The elements after the root in the array up to the first element greater than the root form the left subtree, and the elements after that form the right subtree.

Here's a step-by-step approach:

Start with the first element of the preorder array as the root.
Find the first element greater than the root in the remaining array; this element marks the beginning of the right subtree.
Recursively construct the left subtree using the elements between the root and the first greater element.
Recursively construct the right subtree using the elements after the first greater element.
Return the root.
Below is the implementation in C:

*/


#include <stdio.h>
#include <stdlib.h>

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

// Helper function to construct the BST
TreeNode* bstFromPreorderHelper(int* preorder, int* preorderIndex, int size, int min, int max) {
    // Base case: if the entire preorder array is traversed
    if (*preorderIndex == size) return NULL;

    int val = preorder[*preorderIndex];
    // Check if the current value falls outside the min-max range
    if (val < min || val > max) return NULL;

    // Create a new node from the current value and increment index
    TreeNode* root = newNode(val);
    (*preorderIndex)++;

    // Construct the left and right subtrees recursively
    root->left = bstFromPreorderHelper(preorder, preorderIndex, size, min, val);
    root->right = bstFromPreorderHelper(preorder, preorderIndex, size, val, max);

    return root;
}

// Main function to construct BST from its preorder traversal
TreeNode* bstFromPreorder(int* preorder, int size) {
    int preorderIndex = 0;
    return bstFromPreorderHelper(preorder, &preorderIndex, size, INT_MIN, INT_MAX);
}

// Example usage
int main() {
    int preorder[] = {8, 5, 1, 7, 10, 12};
    int size = sizeof(preorder) / sizeof(preorder[0]);

    TreeNode* root = bstFromPreorder(preorder, size);

    // The BST is now constructed with root as the root of the BST
    // Add code to traverse and print the BST, or perform other operations

    return 0;
}

