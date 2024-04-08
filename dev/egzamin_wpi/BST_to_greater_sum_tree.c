/*

Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.


To convert a Binary Search Tree (BST) to a Greater Tree, where each node's value is updated to be the sum of all values greater than itself in the BST, you can perform a reverse in-order traversal (visit right, node, left). During this traversal, you maintain a running sum of all nodes visited so far.

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

// Recursive function to convert BST to Greater Tree
void convertBSTToGreaterTree(TreeNode* root, int* sum) {
    if (root == NULL) return;

    // Reverse in-order traversal: right -> node -> left
    convertBSTToGreaterTree(root->right, sum);

    // Node's value is updated to the sum of all greater values
    *sum += root->val;
    root->val = *sum;

    convertBSTToGreaterTree(root->left, sum);
}

// Wrapper function that initiates the conversion process
TreeNode* convertBST(TreeNode* root) {
    int sum = 0;
    convertBSTToGreaterTree(root, &sum);
    return root;
}

// Example usage
int main() {
    // Construct a binary search tree
    TreeNode* root = newNode(4);
    root->left = newNode(1);
    root->right = newNode(6);
    root->left->left = newNode(0);
    root->left->right = newNode(2);
    root->right->left = newNode(5);
    root->right->right = newNode(7);
    root->left->right->right = newNode(3);
    root->right->right->right = newNode(8);

    // Convert the BST to a Greater Tree
    convertBST(root);

    // The BST is now converted to a Greater Tree with each node's value
    // being updated to the original key plus the sum of all keys greater than the original key.

    // Add code to print the tree inorder to verify the result (not shown here)

    return 0;
}

