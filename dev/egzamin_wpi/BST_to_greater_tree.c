/*

Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.


This problem can be solved by performing a reverse in-order traversal (visit right -> node -> left) of the BST. During the traversal, we maintain a running sum of all nodes visited so far. Since this is a reverse in-order traversal, we visit the nodes in decreasing order, so we can easily accumulate the sum of all greater nodes.




*/


#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// A utility function to create a new Binary Tree node
TreeNode* newNode(int data) {
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->val = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Helper function to perform reverse in-order traversal
void convertBSTHelper(TreeNode* node, int* sum) {
    if (node == NULL) return;

    // Recur on right subtree
    convertBSTHelper(node->right, sum);

    // Update the value of the current node
    *sum = *sum + node->val;
    node->val = *sum;

    // Recur on left subtree
    convertBSTHelper(node->left, sum);
}

// Main function to convert a BST to a Greater Tree
TreeNode* convertBST(TreeNode* root) {
    int sum = 0;
    convertBSTHelper(root, &sum);
    return root;
}

