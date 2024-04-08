/*

You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.

Return the number of good leaf node pairs in the tree.

***


To count the number of good leaf node pairs in a binary tree, where the length of the shortest path between them is less than or equal to a given distance, you can perform a post-order traversal of the binary tree. During this traversal, you collect the distances to the leaf nodes for each subtree. When processing a node, you can then combine the distances from the left and right subtrees to count the number of pairs that satisfy the distance condition.

Here's a high-level algorithm:

Perform a DFS traversal of the tree. For each node, return a list of distances to its leaf nodes.
When processing a node, combine the distances from its left and right children, and count the number of pairs that have a combined distance less than or equal to the given distance.
Add one to each distance in the list (to account for the distance from the current node to its children) before returning it to the parent node.
The result is the total count of good leaf node pairs.


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

// The maximum number of nodes from root to any leaf will be the height of the tree.
// For simplicity, we use a fixed size for leafDistances assuming a reasonable height.
#define MAX_HEIGHT 1000

// DFS function to count good leaf node pairs and return leaf distances
int dfs(TreeNode* node, int distance, int* leafDistances, int* result) {
    if (!node) {
        return 0; // Base case: empty tree has no leaves
    }
    if (!node->left && !node->right) {
        leafDistances[1] = 1; // A leaf at distance 1 (itself)
        return 1; // Return the height of the tree (1 for a leaf)
    }
    
    int leftDistances[MAX_HEIGHT] = {0};
    int rightDistances[MAX_HEIGHT] = {0};
    int leftHeight = dfs(node->left, distance, leftDistances, result);
    int rightHeight = dfs(node->right, distance, rightDistances, result);
    
    // Combine distances from left and right subtrees to count good pairs
    for (int i = 1; i <= leftHeight; ++i) {
        for (int j = 1; j <= rightHeight && i + j <= distance; ++j) {
            *result += leftDistances[i] * rightDistances[j];
        }
    }
    
    // Collect leaf distances for the current node's parent
    for (int i = 1; i <= leftHeight; ++i) {
        leafDistances[i + 1] += leftDistances[i];
    }
    for (int i = 1; i <= rightHeight; ++i) {
        leafDistances[i + 1] += rightDistances[i];
    }
    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1; // Return the height of the current tree
}

// Main function to return the number of good leaf node pairs
int countPairs(TreeNode* root, int distance) {
    int leafDistances[MAX_HEIGHT] = {0};
    int result = 0;
    dfs(root, distance, leafDistances, &result);
    return result;
}

// Example usage
int main() {
    // Construct the binary tree
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int distance = 3;
    int result = countPairs(root, distance);
    printf("Number of good leaf node pairs: %d\n", result);

    // Free the allocated memory for the tree nodes (not shown here)

    return 0;
}

