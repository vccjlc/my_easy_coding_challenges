/*

Return true if and only if the absolute difference of the average of the left subtree and the average of the right subtree is  within the range of root value (eg. root value is 5, left subtree is 17, right is 21, difference is -4 and |-4| = 4 is less than or equal 5)


To determine if the absolute difference between the average of the left subtree and the average of the right subtree is within the range of the root value, we can adapt the approach used for sum calculations. Specifically, we need to calculate the sum and count of nodes for both the left and right subtrees. With these values, we can compute the averages of the subtrees. Finally, we'll compare the absolute difference of these averages to the root's value.

We'll use a helper function that calculates both the sum and the count of nodes in a subtree. This function will allow us to compute the average values for both subtrees efficiently. After obtaining these averages, we can perform the required check at the root level.

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

// Helper function to calculate the sum and count of nodes in a subtree
void sumAndCountNodes(struct TreeNode* node, int* sum, int* count) {
    if (node == NULL) {
        *sum = 0; // Sum of the subtree is 0 for a NULL node
        *count = 0; // Count of nodes in the subtree is 0 for a NULL node
        return;
    }
    int leftSum, rightSum, leftCount, rightCount;
    sumAndCountNodes(node->left, &leftSum, &leftCount);
    sumAndCountNodes(node->right, &rightSum, &rightCount);

    // Update the sum and count for the current subtree
    *sum = node->val + leftSum + rightSum;
    *count = 1 + leftCount + rightCount; // 1 for the current node
}

// Main function to check if the absolute difference between the averages of the left and right subtrees
// is within the range of the root value
bool isAverageDiffWithinRootValue(struct TreeNode* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return true; // If the tree is empty or the root has no children, consider the condition met
    }

    int leftSum, rightSum, leftCount, rightCount;
    sumAndCountNodes(root->left, &leftSum, &leftCount);
    sumAndCountNodes(root->right, &rightSum, &rightCount);

    // Calculate the average for each subtree, avoiding division by zero
    double leftAvg = leftCount ? (double)leftSum / leftCount : 0;
    double rightAvg = rightCount ? (double)rightSum / rightCount : 0;

    // Calculate the absolute difference between the averages
    double diff = fabs(leftAvg - rightAvg);

    // Check if the difference is within the range of the root value
    return diff <= root->val;
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

    // bool result = isAverageDiffWithinRootValue(root);
    // if (result) {
    //     printf("The absolute difference of the averages of the left and right subtrees is within the range of the root value.\n");
    // } else {
    //     printf("The absolute difference of the averages is NOT within the range of the root value.\n");
    // }

    return 0;
}

