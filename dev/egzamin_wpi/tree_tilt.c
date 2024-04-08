/*

Given the root of a binary tree, return the sum of every tree node's tilt.

The tilt of a tree node is the absolute difference between the sum of all left subtree node values and all right subtree node values. If a node does not have a left child, then the sum of the left subtree node values is treated as 0. The rule is similar if the node does not have a right child.



To find the sum of every tree node's tilt in a binary tree, we can perform a post-order traversal (left-right-node). At each node, we'll calculate the sum of the values in its left and right subtrees, and the tilt of the node will be the absolute difference between these two sums. We will also maintain a running total of all tilts encountered during the traversal.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// A utility function to create a new Binary Tree node
TreeNode* newNode(int val) {
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Helper function to calculate the sum of node values in a subtree and the tilt
int findTiltHelper(TreeNode* node, int* totalTilt) {
    if (!node) return 0;

    // Post-order traversal: left, then right, then node
    int leftSum = findTiltHelper(node->left, totalTilt);
    int rightSum = findTiltHelper(node->right, totalTilt);
    
    // Tilt of the current node
    int tilt = abs(leftSum - rightSum);
    
    // Add current node's tilt to the total tilt
    *totalTilt += tilt;
    
    // Return the sum of values starting from this node
    return node->val + leftSum + rightSum;
}

// Main function to find the total tilt of the binary tree
int findTilt(TreeNode* root) {
    int totalTilt = 0;
    findTiltHelper(root, &totalTilt);
    return totalTilt;
}

// Example usage
int main() {
    TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    int result = findTilt(root);
    printf("The total tilt of the tree is: %d\n", result);

    // Free the allocated memory
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}

