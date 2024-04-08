/*

Given the root of a binary tree, return the maximum average value of a subtree of that tree. Answers within 10-5 of the actual answer will be accepted.
A subtree of a tree is any node of that tree plus all its descendants.
The average value of a tree is the sum of its values, divided by the number of nodes.


To find the maximum average value of a subtree in a binary tree, you can use a recursive function that calculates the sum and the count of nodes for each subtree. With the sum and count, you can calculate the average value for the subtree rooted at each node, and then return the maximum average found.

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

typedef struct Result {
    int sum;    // Sum of subtree
    int count;  // Number of nodes in subtree
} Result;

// Helper function to find the maximum average of a subtree
Result findMaxAverage(TreeNode* root, double* maxAvg) {
    if (root == NULL) {
        return (Result){0, 0};
    }

    Result leftResult = findMaxAverage(root->left, maxAvg);
    Result rightResult = findMaxAverage(root->right, maxAvg);

    // Current sum and count including the root node
    int currentSum = leftResult.sum + rightResult.sum + root->val;
    int currentCount = leftResult.count + rightResult.count + 1;

    // Calculate the average for the current subtree
    double currentAvg = (double)currentSum / currentCount;

    // Update maxAvg if the current average is greater
    if (currentAvg > *maxAvg) {
        *maxAvg = currentAvg;
    }

    // Return the current sum and count for the parent calls
    return (Result){currentSum, currentCount};
}

// Main function to return the maximum average of a subtree
double maximumAverageSubtree(TreeNode* root) {
    double maxAvg = 0;
    findMaxAverage(root, &maxAvg);
    return maxAvg;
}

// Example usage
int main() {
    TreeNode* root = newNode(5);
    root->left = newNode(6);
    root->right = newNode(1);

    double result = maximumAverageSubtree(root);
    printf("Maximum average value of a subtree: %f\n", result);

    // Free the allocated memory for the tree nodes (not shown here)

    return 0;
}

