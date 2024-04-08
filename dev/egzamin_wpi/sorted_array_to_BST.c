// Create BST from sorted array


#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node.
struct TreeNode* newNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Utility function to create a BST from a sorted array.
struct TreeNode* sortedArrayToBST(int arr[], int start, int end) {
    // Base case
    if (start > end) {
        return NULL;
    }

    // Get the middle element and make it root.
    int mid = (start + end) / 2;
    struct TreeNode *root = newNode(arr[mid]);

    // Recursively construct the left subtree
    // and make it left child of root.
    root->left = sortedArrayToBST(arr, start, mid - 1);

    // Recursively construct the right subtree
    // and make it right child of root.
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

// A utility function to print the preorder traversal of the BST.
void preOrder(struct TreeNode* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->val);
    preOrder(node->left);
    preOrder(node->right);
}

// Driver program to test above functions.
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Convert sorted array to BST
    struct TreeNode *root = sortedArrayToBST(arr, 0, n-1);

    printf("PreOrder Traversal of constructed BST: \n");
    preOrder(root);

    return 0;
}

