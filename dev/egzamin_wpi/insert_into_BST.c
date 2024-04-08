/*

You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them


To insert a value into a binary search tree (BST) while maintaining its properties, you can perform a recursive search to find the appropriate location for the new value. 



*/


#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Helper function to create a new TreeNode
TreeNode* createTreeNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new value into the BST
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == NULL) {
        // If the current node is NULL, the new value should be inserted here
        return createTreeNode(val);
    }

    if (val < root->val) {
        // If the new value is less than the current node's value, insert it into the left subtree
        root->left = insertIntoBST(root->left, val);
    } else {
        // If the new value is greater than the current node's value, insert it into the right subtree
        root->right = insertIntoBST(root->right, val);
    }

    // Return the unchanged current node
    return root;
}

int main() {
    // Example usage:
    // Create the root of the BST
    TreeNode* root = createTreeNode(4);
    // Insert new values into the BST
    insertIntoBST(root, 2);
    insertIntoBST(root, 7);
    insertIntoBST(root, 1);
    insertIntoBST(root, 3);
    insertIntoBST(root, 5);

    // The BST after insertion is now rooted at 'root'
    // Continue with other operations...

    // Don't forget to free the memory of the BST after use
    // ...

    return 0;
}

