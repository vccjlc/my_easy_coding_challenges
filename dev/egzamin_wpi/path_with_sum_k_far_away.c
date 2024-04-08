/*

You are given the root of a binary tree and an integer sum and integer k

Return the node farthest from the root from which the path starts such that the sum of the path is equal to sum and the length of the path is k


To find the node farthest from the root from which a path starts, with the path sum equal to a given sum and the length of the path equal to k, you can still use a Depth-First Search (DFS) strategy similar to the previous approach but with a slight modification. This time, instead of returning immediately upon finding the first valid path, you continue the search to explore all possible paths. You keep track of the valid starting node that is farthest from the root.



*/


#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

// Helper function for DFS
void dfs(struct TreeNode* node, int currentSum, int sum, int k, int currentLength, struct TreeNode** farthestNode) {
    if (node == NULL) {
        return;
    }

    // Update the current path sum and length
    currentSum += node->val;
    currentLength++;

    // If the path length is k, check the sum
    if (currentLength == k) {
        if (currentSum == sum) {
            *farthestNode = node;  // Update the farthest valid starting node
        }
        // Don't return here to ensure we explore all paths
    }

    // Recursively search in left and right subtrees
    dfs(node->left, currentSum, sum, k, currentLength, farthestNode);
    dfs(node->right, currentSum, sum, k, currentLength, farthestNode);

    // Backtrack not needed as we're not modifying the node or global state
}

// Main function to find the farthest starting node
struct TreeNode* findFarthestStartingNode(struct TreeNode* root, int sum, int k) {
    struct TreeNode* farthestNode = NULL;
    dfs(root, 0, sum, k, 0, &farthestNode);
    return farthestNode;
}

int main() {
    // Example usage
    // Build your binary tree here and call findFarthestStartingNode(root, sum, k)
    return 0;
}

