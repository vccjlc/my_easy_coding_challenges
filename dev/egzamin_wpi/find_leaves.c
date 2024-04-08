/*

Collect all leaves
Trim them
Do it again until the tree is empty


To solve the problem where we need to collect and remove leaf nodes layer by layer until the tree is empty, we can perform a level-order traversal with a slight modification to process the nodes level by level, starting from the leaves.

Here's the approach in steps:

Traverse the tree to find the leaves.
Collect the leaves in a list.
Remove the leaves from the tree by setting the parent's reference to the leaf node to NULL.
Repeat the process with the reduced tree until the tree is empty.

*/

// Function to find leaves and remove them
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
} TreeNode;

// Helper function to create a new TreeNode
TreeNode* createTreeNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find leaves and remove them
void findAndRemoveLeaves(TreeNode* node, int level, int* maxLevel, int** leaves, int* leavesSize, int* leavesCapacity) {
    if (!node) return;

    // If it's a leaf node
    if (!node->left && !node->right) {
        if (level > *maxLevel) {
            *maxLevel = level;
            // Reset leaves array for new level
            *leavesSize = 0;
        }
        // Add leaf value to leaves array
        if (*leavesSize >= *leavesCapacity) {
            *leavesCapacity *= 2;
            *leaves = realloc(*leaves, (*leavesCapacity) * sizeof(int));
        }
        (*leaves)[(*leavesSize)++] = node->val;
        return;
    }

    // Recur for left and right subtrees
    findAndRemoveLeaves(node->left, level + 1, maxLevel, leaves, leavesSize, leavesCapacity);
    findAndRemoveLeaves(node->right, level + 1, maxLevel, leaves, leavesSize, leavesCapacity);

    // Remove leaves from tree
    if (node->left && (node->left->left == NULL && node->left->right == NULL)) node->left = NULL;
    if (node->right && (node->right->left == NULL && node->right->right == NULL)) node->right = NULL;
}

// Main function to collect leaves from tree
int** findLeaves(TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int capacity = 500; // Initial capacity for each level's leaves array
    int* leaves = (int*)malloc(capacity * sizeof(int)); // Array to hold leaves of current level
    int leavesSize = 0; // Size of current level's leaves array
    int maxLevel = -1; // Track the last level processed
    
    *returnSize = 0;
    int** result = (int**)malloc(capacity * sizeof(int*)); // Array of leaves arrays
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int)); // Array of sizes for each level's leaves array

    while (root && (root->left || root->right)) {
        findAndRemoveLeaves(root, 0, &maxLevel, &leaves, &leavesSize, &capacity);
        result[*returnSize] = (int*)malloc(leavesSize * sizeof(int));
        memcpy(result[*returnSize], leaves, leavesSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = leavesSize;
        (*returnSize)++;
    }

    // Add root if it's the last remaining node
    if (root) {
        result[*returnSize] = (int*)malloc(sizeof(int));
        result[*returnSize][0] = root->val;
        (*returnColumnSizes)[*returnSize] = 1;
        (*returnSize)++;
    }

    free(leaves);
    return result;
}


