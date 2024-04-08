/*

Given a binary tree root and an integer target, delete all the leaf nodes with value target.

 just delete original leaf nodes with value target
 
 
 
 ***
 
 To delete the original leaf nodes with a value equal to the target, without further cascading deletions up the tree, you can modify the recursive function to only check for and delete nodes that are leaves at the moment of the function call. This approach ensures that only the original leaf nodes with the target value are deleted, and their parents, even if they become leaves after deletion, are not removed.


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

// Recursive function to delete original leaf nodes with the target value
TreeNode* removeLeafNodes(TreeNode* root, int target) {
    if (root == NULL) return NULL;

    // Recursively traverse the left and right subtrees
    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);

    // Check if the current node is a leaf with the target value
    if (root->left == NULL && root->right == NULL && root->val == target) {
        free(root);  // Delete the node
        return NULL;  // Update the parent's pointer to this node
    }

    return root;  // Return the possibly updated subtree
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
    root = removeLeafNodes(root, target);  // Remove leaf nodes with value equal to target

    // The binary tree is now modified with the target leaves removed
    // You can add code to print the modified tree to verify the result (not shown here)

    // Free the allocated memory for the tree nodes
    freeTree(root);

    return 0;
}

