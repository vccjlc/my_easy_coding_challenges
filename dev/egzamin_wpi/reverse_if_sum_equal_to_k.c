/*

Given the root of a perfect binary tree, swap the nodes of one parent only if their sum is equal to given integer k (if a parent has children and their sum is equal to k, we swap the children)

To swap the children of a parent node in a perfect binary tree if their sum is equal to a given integer k, you can perform a simple depth-first search (DFS) traversal of the tree. During the traversal, for each parent node, check if the sum of its children's values equals k. If it does, swap the children.


*/



#include <stdio.h>
#include <stdlib.h>

// Define the structure for tree nodes
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

// Utility function to create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to swap the children of a node
void swapChildren(struct TreeNode* node) {
    struct TreeNode* temp = node->left;
    node->left = node->right;
    node->right = temp;
}

// DFS function to swap nodes based on the condition
void swapIfSumEqualsK(struct TreeNode* node, int k) {
    if (node == NULL || (node->left == NULL && node->right == NULL)) {
        // If the node is NULL or a leaf, nothing to do
        return;
    }

    // Check if the sum of the children equals k
    if (node->left->val + node->right->val == k) {
        // Swap the children
        swapChildren(node);
    }

    // Recursively apply to the left and right subtrees
    swapIfSumEqualsK(node->left, k);
    swapIfSumEqualsK(node->right, k);
}

// Main function to initiate the swap process
struct TreeNode* swapNodes(struct TreeNode* root, int k) {
    swapIfSumEqualsK(root, k);
    return root;
}

int main() {
    // Example usage
    // struct TreeNode* root = createNode(1);
    // root->left = createNode(2);
    // root->right = createNode(3);
    // root->left->left = createNode(4);
    // root->left->right = createNode(5);
    // root->right->left = createNode(6);
    // root->right->right = createNode(7);
    // int k = 11;

    // struct TreeNode* result = swapNodes(root, k);

    // Proceed to use the result tree as needed

    return 0;
}

