/*

find the closest leaf in the subtree of a given node

Traverse the tree to find the node with the given value.
Once you have found the node, perform a DFS from that node to find the closest leaf.

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

// Recursive function to find the closest leaf from the given node
int findClosestLeaf(TreeNode* node) {
    if (node == NULL) return INT_MAX;
    if (node->left == NULL && node->right == NULL) return 0; // Found a leaf

    int leftDistance = findClosestLeaf(node->left);
    int rightDistance = findClosestLeaf(node->right);

    // Return the minimum distance plus one for the current node's level
    return 1 + (leftDistance < rightDistance ? leftDistance : rightDistance);
}

// Function to find the node with the given value
TreeNode* findNode(TreeNode* root, int value) {
    if (root == NULL || root->val == value) return root;
    TreeNode* left = findNode(root->left, value);
    if (left != NULL) return left;
    return findNode(root->right, value);
}

// Main function to find the closest leaf to the given value
int closestLeaf(TreeNode* root, int value) {
    TreeNode* node = findNode(root, value);
    return findClosestLeaf(node);
}

int main() {
    // Example usage:
    TreeNode* root = createTreeNode(1);
    root->left = createTreeNode(2);
    root->right = createTreeNode(3);
    root->left->left = createTreeNode(4);
    root->left->right = createTreeNode(5);
    root->left->left->left = createTreeNode(6);

    int value = 2; // Find the closest leaf in the subtree of the node with value 2
    int leafDistance = closestLeaf(root, value);
    printf("Closest leaf distance: %d\n", leafDistance);

    // Free memory if needed and perform other cleanups

    return 0;
}

