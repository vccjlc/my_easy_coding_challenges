/*

Return the longest path in which no two values are the same



To find the longest path in a binary tree where no two values are the same, we can use a Depth-First Search (DFS) traversal. The idea is to maintain a record of the current path as we traverse the tree and keep updating the longest path found so far. At each node, we need to ensure the current node's value hasn't already been seen on the current path. If it has, the current path ends, and we backtrack.

We can implement this by using a recursive DFS function that traverses the tree and checks for repeated values using a data structure like a set (to keep track of the unique values seen along the current path). Since C doesn't have a built-in set data structure, we can use a hash table or an array (if the values in the nodes are limited to a certain range and can be mapped directly to indices in the array) to simulate a set for checking the presence of values

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

// DFS function to find the longest unique value path
void dfs(struct TreeNode* node, int* visited, int depth, int* maxDepth) {
    if (!node || visited[node->val]) {
        *maxDepth = depth > *maxDepth ? depth : *maxDepth;
        return;
    }

    // Mark the current node value as visited
    visited[node->val] = 1;

    // Continue DFS traversal
    dfs(node->left, visited, depth + 1, maxDepth);
    dfs(node->right, visited, depth + 1, maxDepth);

    // Backtrack: unmark the current node value as visited
    visited[node->val] = 0;
}

// Main function to initiate DFS and find the longest unique value path
int longestUniqueValuePath(struct TreeNode* root) {
    int maxDepth = 0;
    int visited[1001] = {0}; // Assuming node values are in the range [0, 1000]
    dfs(root, visited, 0, &maxDepth);
    return maxDepth;
}

int main() {
    // Example usage
    // struct TreeNode* root = createNode(1);
    // root->left = createNode(2);
    // root->right = createNode(3);
    // root->left->left = createNode(4);
    // root->left->right = createNode(5);
    // root->right->left = createNode(6);
    // root->right->right = createNode(7);
    // root->left->left->left = createNode(8);
    // root->right->right->right = createNode(9);
    
    // int result = longestUniqueValuePath(root);
    // printf("Longest unique value path length: %d\n", result);

    return 0;
}

