/*

Given the root of a binary tree, return the sum of values of nodes with an even-valued grandparent. If there are no nodes with an even-valued grandparent, return 0.

A grandparent of a node is the parent of its parent if it exists.

***

To solve this problem, you can perform a depth-first search (DFS) traversal of the binary tree. During the traversal, keep track of the value of the current node's parent and grandparent. Whenever you are at a node with an even-valued grandparent, add the node's value to the sum.

Here's a step-by-step approach:

Recursive DFS Function: Create a recursive function that traverses the tree. This function should take parameters for the current node, its parent's value, and its grandparent's value.

Sum Calculation: Inside the recursive function, check if the grandparent's value is even. If it is, add the current node's value to the sum.

Traverse the Tree: For each node, recursively call the function for its left and right children. Pass the current node's value as the parent value for the children, and the current parent's value as the grandparent value for the children.

Base Case: If the current node is NULL, return from the function without doing anything.

Initiate the Traversal: Call the recursive function with the root node, passing -1 or any other dummy value for the parent and grandparent values since the root node does not have a parent or grandparent.

*/


#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to create a new tree node.
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Recursive function to calculate the sum of nodes with even-valued grandparents.
void dfs(struct TreeNode* node, int parentVal, int grandParentVal, int* sum) {
    if (!node) return;

    // If grandparent's value is even, add current node's value to sum.
    if (grandParentVal % 2 == 0) {
        *sum += node->val;
    }

    // Traverse the left and right subtree.
    dfs(node->left, node->val, parentVal, sum);
    dfs(node->right, node->val, parentVal, sum);
}

// Function to return the sum of values of nodes with even-valued grandparents.
int sumEvenGrandparent(struct TreeNode* root) {
    int sum = 0;
    dfs(root, -1, -1, &sum);  // Start DFS with root, initializing parent and grandparent values as -1.
    return sum;
}

// Example usage
int main() {
    // Construct a simple binary tree:
    //       2
    //      / \
    //     3   4
    //        / \
    //       5   6
    struct TreeNode* root = newNode(2);
    root->left = newNode(3);
    root->right = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);

    int result = sumEvenGrandparent(root);
    printf("Sum of nodes with even-valued grandparents: %d\n", result);

    // Free the allocated memory for the tree nodes here...
    // This is left as an exercise.

    return 0;
}

