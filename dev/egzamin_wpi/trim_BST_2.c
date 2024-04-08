/*

Given the root of a binary search tree and the lowest and highest boundaries as low and high, trim the tree so that all its elements lies in [low, high]. Trimming the tree should not change the relative structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant). It can be proven that there is a unique answer.

Return the root of the trimmed binary search tree. Note that the root may change depending on the given bounds.




To trim a binary search tree (BST) so that all its elements lie in the range [low, high], you can use recursion. When you visit a node, there are three cases:

If the node's value is less than low, then trim the left subtree, because all the values to the left are also less than low and thus outside the range. You will then return the trimmed right subtree because the right subtree could still have values in the range [low, high].

If the node's value is greater than high, then trim the right subtree, because all the values to the right are also greater than high and thus outside the range. You will then return the trimmed left subtree because the left subtree could still have values in the range [low, high].

If the node's value is within the range [low, high], trim both the left and right subtrees, and keep the current node as the root of the trimmed tree.


*/


#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// A utility function to create a new Binary Tree node
TreeNode* newNode(int val) {
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to trim the BST
TreeNode* trimBST(TreeNode* root, int low, int high) {
    // Base case
    if (root == NULL) return root;

    // If the current node's value is less than the low boundary,
    // then we are only interested in the right subtree
    if (root->val < low) return trimBST(root->right, low, high);

    // If the current node's value is greater than the high boundary,
    // then we are only interested in the left subtree
    if (root->val > high) return trimBST(root->left, low, high);

    // If the current node's value is within the range [low, high],
    // recursively trim the left and right subtrees, and return the current node
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
}

// Example usage
int main() {
    TreeNode *root = newNode(3);
    root->left = newNode(0);
    root->right = newNode(4);
    root->left->right = newNode(2);
    root->left->right->left = newNode(1);

    int low = 1, high = 3;
    TreeNode *trimmedRoot = trimBST(root, low, high);

    // Now trimmedRoot points to the root of the trimmed BST
    // You would normally have code here to print the tree
    // and to free all the allocated nodes
    // ...

    return 0;
}

