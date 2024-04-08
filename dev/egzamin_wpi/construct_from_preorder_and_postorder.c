/*

Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

If there exist multiple answers, you can return any of them.

*/


#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to construct a binary tree from preorder and postorder traversals
struct TreeNode* constructTree(int* preorder, int* postorder, int* preorderIndex, int left, int right, int size) {
    if (*preorderIndex >= size || left > right) return NULL;

    // The first element in preorder is always the root
    struct TreeNode* root = newNode(preorder[*preorderIndex]);
    ++(*preorderIndex);

    // If there's only one element, no need to find left or right subtrees
    if (left == right || *preorderIndex >= size) return root;

    // Find the index of the next value in preorder in postorder array
    // to determine the boundary of left subtree
    int i = left;
    int found = 0; // Flag to indicate when the value is found
    while (i <= right && !found) {
        if (preorder[*preorderIndex] == postorder[i]) {
            found = 1; // Set the flag when the value is found
    } else {
        ++i;
    }
}

    // Using index in postorder, construct left and right subtrees
    if (i <= right) {
        root->left = constructTree(preorder, postorder, preorderIndex, left, i, size);
        root->right = constructTree(preorder, postorder, preorderIndex, i + 1, right - 1, size);
    }

    return root;
}

// Wrapper function to call constructTree
struct TreeNode* buildTree(int* preorder, int* postorder, int size) {
    int preorderIndex = 0;
    return constructTree(preorder, postorder, &preorderIndex, 0, size - 1, size);
}

// Add any additional functions to print or free the tree if necessary

int main() {
    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int postorder[] = {4, 5, 2, 6, 7, 3, 1};
    int size = sizeof(preorder) / sizeof(preorder[0]);

    struct TreeNode* root = buildTree(preorder, postorder, size);

    // The tree is now constructed, and root points to the root of the tree.
    // You can add functions to print or free the tree if necessary.

    return 0;
}

