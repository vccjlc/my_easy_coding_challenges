/*

For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.

A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.

Given the roots of two binary trees root1 and root2, return true if the two trees are flip equivalent or false otherwise.


To determine if two binary trees are flip equivalent, you can use a recursive function that checks the following for every corresponding node pair in the two trees:

Both nodes are NULL, which implies that the subtrees rooted at these nodes are equivalent.
Both nodes are not NULL, and their values are equal. In this case, you need to check two possibilities due to the flip operation:
The left subtree of the first tree is flip equivalent to the left subtree of the second tree, and the right subtree of the first tree is flip equivalent to the right subtree of the second tree.
The left subtree of the first tree is flip equivalent to the right subtree of the second tree, and the right subtree of the first tree is flip equivalent to the left subtree of the second tree (this checks for a flip).


*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Include for bool type

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Helper function to create a new Binary Tree node
TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Recursive function to check if two trees are flip equivalent
bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    // Both nodes are NULL
    if (root1 == NULL && root2 == NULL) {
        return true;
    }

    // One node is NULL and the other is not, or the values of the nodes are not equal
    if (root1 == NULL || root2 == NULL || root1->val != root2->val) {
        return false;
    }

    // Check if subtrees are flip equivalent (without flip and with flip)
    return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
           (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
}

// Example usage
int main() {
    // Create and populate trees root1 and root2
    // TreeNode* root1 = ...
    // TreeNode* root2 = ...

    bool result = flipEquiv(root1, root2);
    if (result) {
        printf("The trees are flip equivalent.\n");
    } else {
        printf("The trees are not flip equivalent.\n");
    }

    // Remember to free the allocated memory for the nodes after usage
    return 0;
}

