/*

Return true if and only if the sum of the left subtree and the sum of the right subtree are such that if we add the value of root to one of them, we will get the same numbers (ie left tree sum = 10, right tree sum = 15, root value = 5, we return true because 10+5 = 15)


To determine if the sum of the left subtree plus the root's value equals the sum of the right subtree, or vice versa, we can traverse the binary tree to calculate the sums of the left and right subtrees. After obtaining these sums, we can perform the specified check by adding the root's value to each sum and comparing them.

We'll use a helper function to calculate the sum of a subtree and return this sum to the caller. Then, at the root level, we can use these sums to check if adding the root's value to one of them results in the sum of the other subtree.


*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Helper function to calculate the sum of a subtree
int subtreeSum(struct TreeNode* node) {
    if (node == NULL) {
        return 0; // Base case: if the node is null, return 0
    }
    // Recursive call to calculate the sum of the left and right subtrees and add the current node's value
    return node->val + subtreeSum(node->left) + subtreeSum(node->right);
}

// Main function to check if adding the root's value to the sum of one subtree equals the sum of the other subtree
bool isSumWithRootEqualToOtherSubtree(struct TreeNode* root) {
    if (root == NULL) {
        return true; // If the tree is empty, consider it as meeting the condition
    }

    int leftSum = subtreeSum(root->left); // Calculate the sum of the left subtree
    int rightSum = subtreeSum(root->right); // Calculate the sum of the right subtree

    // Check if adding the root's value to the left sum equals the right sum, or vice versa
    return (leftSum + root->val == rightSum) || (rightSum + root->val == leftSum);
}

int main() {
    // Example usage
    // struct TreeNode* root = createNode(5);
    // root->left = createNode(3);
    // root->right = createNode(7);
    // root->left->left = createNode(2);
    // root->left->right = createNode(4);
    // root->right->left = createNode(6);
    // root->right->right = createNode(8);

    // bool result = isSumWithRootEqualToOtherSubtree(root);
    // if (result) {
    //     printf("Adding the root's value to one subtree's sum equals the sum of the other subtree.\n");
    // } else {
    //     printf("No such combination found.\n");
    // }

    return 0;
}

