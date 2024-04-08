/*



If the depth of a tree is smaller than 5, then this tree can be represented by an array of three-digit integers. For each integer in this array:
• The hundreds digit represents the depth d of this node where 1 <= d <= 4.
• The tens digit represents the position p of this node in the level it belongs to where 1 <= p <= 8. The position is the same as that in a full binary tree.
• The units digit represents the value v of this node where 0 <= v <= 9.
Given an array of ascending three-digit integers nums representing a binary tree with a depth smaller than 5, return the sum of all paths from the root towards the leaves.
It is guaranteed that the given array represents a valid connected binary tree.

To solve this, you can follow these steps:

Parse the array and build a tree structure that captures the parent-child relationships implied by the depth and position information.
Perform a depth-first search (DFS) or a similar traversal to calculate the path sums from the root to each leaf.
Add these path sums to get the total sum.

*/

#include <stdio.h>
#include <stdlib.h>

// Define a simple binary tree node structure.
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Helper function to create a new tree node.
TreeNode* createTreeNode(int value) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// A function to build the binary tree from the given array representation.
TreeNode* buildTree(int* nums, int numsSize) {
    // Initialize nodes and construct the binary tree.
    // ...

    // Return the root of the constructed tree.
    return NULL; // Placeholder
}

// Helper function to calculate path sums.
void calculatePathSums(TreeNode* node, int currentSum, int* totalSum) {
    if (!node) return;
    currentSum = currentSum * 10 + node->val; // Update the current path sum.
    if (!node->left && !node->right) { // Check if the node is a leaf.
        *totalSum += currentSum; // If it is, add to the total sum.
    } else {
        calculatePathSums(node->left, currentSum, totalSum); // Continue to the left.
        calculatePathSums(node->right, currentSum, totalSum); // Continue to the right.
    }
}

// Main function to return the sum of all paths.
int pathSum(int* nums, int numsSize) {
    TreeNode* root = buildTree(nums, numsSize); // Construct the tree.
    int totalSum = 0;
    calculatePathSums(root, 0, &totalSum); // Calculate path sums.
    // Free the constructed binary tree.
    // ...
    return totalSum; // Return the total path sum.
}

int main() {
    // Example usage.
    int nums[] = {113, 215, 221}; // Example input.
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = pathSum(nums, numsSize);
    printf("Total path sum: %d\n", result);
    return 0;
}

