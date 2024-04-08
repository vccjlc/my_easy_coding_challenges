/*

Finding the maximum absolute difference between the values of any two different nodes in a Binary Search Tree (BST) is straightforward since the maximum difference will be between the smallest and largest nodes. In a BST, the smallest value is the leftmost node, and the largest value is the rightmost node.


*/

#include <stdio.h>
#include <stdlib.h>

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

// Helper function to find the smallest value in the BST (leftmost node)
int findMinValue(TreeNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node->val;
}

// Helper function to find the largest value in the BST (rightmost node)
int findMaxValue(TreeNode* node) {
    while (node->right != NULL) {
        node = node->right;
    }
    return node->val;
}

// Function to find the maximum absolute difference in the BST
int getMaxAbsoluteDifference(TreeNode* root) {
    if (root == NULL) {
        return 0; // If the tree is empty, there is no difference to calculate
    }
    int minValue = findMinValue(root);
    int maxValue = findMaxValue(root);
    return maxValue - minValue; // Maximum difference in BST is between max and min values
}

int main() {
    // Example usage
    TreeNode* root = createTreeNode(1);
    root->right = createTreeNode(3);
    root->right->left = createTreeNode(2);

    int result = getMaxAbsoluteDifference(root);
    printf("Maximum absolute difference in the BST is: %d\n", result);

    // Free memory if needed and perform other cleanups

    return 0;
}

