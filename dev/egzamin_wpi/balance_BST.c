/*

Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

***


To balance a binary search tree (BST), you can perform an in-order traversal to retrieve the elements in sorted order, and then construct a new balanced BST from the sorted elements. The process of building a balanced BST from a sorted array is akin to a binary search where the middle element becomes the root, and this process is applied recursively for left and right sub-arrays to construct the left and right subtrees respectively.

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

// Function to perform in-order traversal and fill the array with BST elements
void inOrderTraversal(TreeNode* root, int* arr, int* index) {
    if (root == NULL) return;
    inOrderTraversal(root->left, arr, index);
    arr[(*index)++] = root->val;
    inOrderTraversal(root->right, arr, index);
}

// Function to construct a balanced BST from the sorted array
TreeNode* sortedArrayToBST(int* arr, int start, int end) {
    if (start > end) return NULL;

    // Middle element becomes the root
    int mid = (start + end) / 2;
    TreeNode* node = newNode(arr[mid]);

    // Recursively construct the left and right subtrees
    node->left = sortedArrayToBST(arr, start, mid - 1);
    node->right = sortedArrayToBST(arr, mid + 1, end);

    return node;
}

// Main function to convert the given BST to a balanced BST
TreeNode* balanceBST(TreeNode* root) {
    int n = 10000;  // Assuming the BST has at most 10000 nodes
    int* arr = (int*)malloc(n * sizeof(int));
    int index = 0;

    // Fill the array with BST elements
    inOrderTraversal(root, arr, &index);

    // Construct a balanced BST from the sorted array
    TreeNode* balancedRoot = sortedArrayToBST(arr, 0, index - 1);

    free(arr);  // Don't forget to free the allocated memory
    return balancedRoot;
}

// Add your own functions to construct the BST, print it, and free the nodes

