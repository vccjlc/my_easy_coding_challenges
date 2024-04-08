/*

Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.


*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MAX

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new TreeNode
TreeNode* createTreeNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Helper function to recursively find the minimum absolute difference
void findMinDifference(TreeNode* node, int* prev, int* minDiff) {
    if (node == NULL) return;

    // Traverse the left subtree
    findMinDifference(node->left, prev, minDiff);

    // Update minDiff with the difference between the current and previous node values
    if (*prev >= 0) {
        int currentDiff = node->val - *prev;
        if (currentDiff < *minDiff) {
            *minDiff = currentDiff;
        }
    }
    *prev = node->val; // Update prev to the current node's value

    // Traverse the right subtree
    findMinDifference(node->right, prev, minDiff);
}

// Main function to find the minimum absolute difference in the BST
int getMinimumDifference(TreeNode* root) {
    int minDiff = INT_MAX;
    int prev = -1; // Initialize to -1 to indicate that prev is not yet set
    findMinDifference(root, &prev, &minDiff);
    return minDiff;
}

int main() {
    // Example usage
    TreeNode* root = createTreeNode(4);
    root->left = createTreeNode(2);
    root->right = createTreeNode(6);
    root->left->left = createTreeNode(1);
    root->left->right = createTreeNode(3);

    int result = getMinimumDifference(root);
    printf("Minimum absolute difference in the BST is: %d\n", result);

    // Free memory if needed and perform other cleanups

    return 0;
}
