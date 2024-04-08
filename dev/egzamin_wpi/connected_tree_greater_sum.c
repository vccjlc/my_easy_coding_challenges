/*

Two binary trees are connected at one node (and the subtree starting at this node is the same for both). Write a function that will return the root of a tree with greater sum. Note that we don't have to calculate the sum of the shared subtree





*/


#include <stdio.h>
#include <stdlib.h>

// Define the structure for tree nodes
struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Utility function to create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Helper function to calculate the sum of the tree nodes, excluding the shared subtree
int calculateSum(struct TreeNode* root, struct TreeNode* sharedRoot) {
    if (root == NULL || root == sharedRoot) {
        return 0; // Stop if we reach null or the shared root
    }
    // Recursive DFS to calculate the sum
    return root->value + calculateSum(root->left, sharedRoot) + calculateSum(root->right, sharedRoot);
}

// Function to find the root of the tree with the greater sum, excluding the shared subtree
struct TreeNode* findGreaterSumTreeRoot(struct TreeNode* root1, struct TreeNode* root2, struct TreeNode* sharedRoot) {
    int sum1 = calculateSum(root1, sharedRoot);
    int sum2 = calculateSum(root2, sharedRoot);

    // Compare the sums and return the root of the tree with the greater sum
    return sum1 > sum2 ? root1 : root2;
}

int main() {
    // Example usage:
    // Assume we have two trees, root1 and root2, and a sharedRoot that is connected to both
    // struct TreeNode* root1 = createNode(...);
    // struct TreeNode* root2 = createNode(...);
    // struct TreeNode* sharedRoot = createNode(...);
    // Connect trees to the sharedRoot accordingly

    // struct TreeNode* greaterSumTreeRoot = findGreaterSumTreeRoot(root1, root2, sharedRoot);
    // printf("The root of the tree with the greater sum has the value: %d\n", greaterSumTreeRoot->value);

    return 0;
}

