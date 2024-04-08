/*

Given a binary tree with n nodes, your task is to check if it's possible to pa
rtition the tree to two trees which have the equal sum of values after remov ing exactly one edge on the original tree.
1. The range of tree node value is in the range of [-100000, 100000].
2.1 <= n <= 10000
3. You can assume that the tree is not null


To solve this problem, we can first calculate the total sum of all the nodes' values. Then, we perform a depth-first search (DFS) traversal of the tree. During the traversal, we calculate the sum of each subtree. If at any point, the sum of a subtree is equal to half of the total sum, we can conclude that it is possible to split the tree into two trees of equal sum by removing the edge above this subtree.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Utility function to create a new tree node
TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Helper function to calculate the total sum of all nodes in the tree
int calcTotalSum(TreeNode* root) {
    if (!root) return 0;
    return root->val + calcTotalSum(root->left) + calcTotalSum(root->right);
}

// Helper function for DFS traversal to find the subtree with half total sum
int findSubtreeWithHalfSum(TreeNode* node, int totalSum, int* canPartition) {
    if (!node) return 0;

    int currSum = node->val + findSubtreeWithHalfSum(node->left, totalSum, canPartition) +
                  findSubtreeWithHalfSum(node->right, totalSum, canPartition);

    if (currSum * 2 == totalSum) {
        *canPartition = 1; // Found a valid partition
    }

    return currSum;
}

// Main function to determine if we can split the tree
int canSplitIntoTwoTrees(TreeNode* root) {
    int canPartition = 0;
    int totalSum = calcTotalSum(root);
    findSubtreeWithHalfSum(root, totalSum, &canPartition);
    return canPartition;
}

// Example usage
int main() {
    TreeNode* root = newNode(5);
    root->left = newNode(10);
    root->right = newNode(10);
    root->right->left = newNode(2);
    root->right->right = newNode(3);

    if (canSplitIntoTwoTrees(root)) {
        printf("The tree can be split into two trees with equal sum.\n");
    } else {
        printf("The tree cannot be split into two trees with equal sum.\n");
    }

    // Free the allocated memory for the tree nodes
    free(root->right->left);
    free(root->right->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}

