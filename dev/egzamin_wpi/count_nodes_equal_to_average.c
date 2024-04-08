/*


Count Nodes Equal to Average of Subtree

Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.
Note:
The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
A subtree of root is a tree consisting of root and all of its descendants.

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

// Helper function to traverse the tree and count nodes equal to the average of their subtree
// It returns the sum of the subtree values and the count of nodes in the subtree through pointers
void traverseAndCount(struct TreeNode* node, int* count, int* totalSum, int* totalCount) {
    if (node == NULL) {
        *totalSum = 0; // Sum of the subtree is 0 for a NULL node
        *totalCount = 0; // Count of nodes in the subtree is 0 for a NULL node
        return;
    }

    int leftSum = 0, rightSum = 0, leftCount = 0, rightCount = 0;
    traverseAndCount(node->left, count, &leftSum, &leftCount);
    traverseAndCount(node->right, count, &rightSum, &rightCount);

    // Sum and count for the current node's subtree
    *totalSum = node->val + leftSum + rightSum;
    *totalCount = 1 + leftCount + rightCount; // 1 for the current node

    // Calculate the average and check if the node's value is equal to the average
    if (node->val == *totalSum / *totalCount) {
        (*count)++;
    }
}

// Main function to count nodes equal to the average of their subtree
int countNodesEqualtoAverage(struct TreeNode* root) {
    int count = 0, totalSum, totalCount;
    traverseAndCount(root, &count, &totalSum, &totalCount);
    return count;
}

int main() {
    // Example usage
    // struct TreeNode* root = createNode(4);
    // root->left = createNode(8);
    // root->right = createNode(5);
    // root->left->left = createNode(0);
    // root->left->right = createNode(1);
    
    // int result = countNodesEqualtoAverage(root);
    // printf("Number of nodes equal to the average of their subtree: %d\n", result);

    return 0;
}

