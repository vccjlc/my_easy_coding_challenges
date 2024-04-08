/*

Given a binary tree root and an integer target, delete all the leaf nodes with value target.

Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you cannot).


To delete all leaf nodes with a specific target value from a binary tree in C, you can use a recursive function. This function will traverse the tree, and when it finds a leaf node with the target value, it will delete it. Additionally, if the deletion of a leaf node causes its parent to become a leaf with the target value, it will recursively delete that node as well.


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

// Recursive function to delete leaf nodes with the target value
TreeNode* removeLeafNodes(TreeNode* root, int target) {
    if (root == NULL) return NULL;

    // Recursively check and delete leaf nodes in left and right subtrees
    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);

    // If the current node becomes a leaf node and its value equals the target, delete it
    if (root->left == NULL && root->right == NULL && root->val == target) {
        free(root);
        return NULL;
    }

    return root;
}

// Function to free the memory allocated for the binary tree
void freeTree(TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Example usage
int main() {
    // Construct the binary tree
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(2);
    root->right->left = newNode(2);
    root->right->right = newNode(4);

    int target = 2;
    root = removeLeafNodes(root, target);

    // The binary tree is now modified with the target leaves removed
    // You can add code to print the modified tree to verify the result (not shown here)

    // Free the allocated memory for the tree nodes
    freeTree(root);

    return 0;
}

