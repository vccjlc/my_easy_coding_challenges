/*


Return true if and only if the absolute difference of the sum of the left subtree and the sum of the right subtree is  within the range of root value (eg. root value is 5, left subtree is 17, right is 21, difference is -4 and |-4| = 4 is less than or equal 5)


To determine if the absolute difference between the sum of the left subtree and the sum of the right subtree is within the range of the root value, you can perform a post-order traversal of the binary tree. At each node, calculate the sum of its left and right subtrees, then check if the absolute difference between these sums is less than or equal to the node's value. This needs to be checked specifically at the root node to satisfy the condition.


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

// Main function to check if the absolute difference between the left and right subtree sums
// is within the range of the root value
bool isDiffWithinRootValue(struct TreeNode* root) {
    if (root == NULL) {
        return true; // If the tree is empty, consider it as meeting the condition
    }

    int leftSum = subtreeSum(root->left); // Calculate the sum of the left subtree
    int rightSum = subtreeSum(root->right); // Calculate the sum of the right subtree
    int diff = abs(leftSum - rightSum); // Calculate the absolute difference between left and right sums

    return diff <= root->val; // Return true if the difference is within the range of the root value
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

    // bool result = isDiffWithinRootValue(root);
    // if (result) {
    //     printf("The absolute difference of the left and right subtree sums is within the range of the root value.\n");
    // } else {
    //     printf("The absolute difference of the left and right subtree sums is NOT within the range of the root value.\n");
    // }

    return 0;
}

