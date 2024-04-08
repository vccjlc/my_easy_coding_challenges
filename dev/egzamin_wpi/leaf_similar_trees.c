/*

Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.


Here's how you can approach this problem in C:

Perform an in-order traversal on both trees to extract their leaf value sequences.
Compare the leaf value sequences of the two trees to determine if they are identical.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to add leaves to an array and count them
void addLeaves(struct TreeNode* node, int* leaves, int* count) {
    if (node == NULL) { // Base case: empty node
        return;
    }
    if (node->left == NULL && node->right == NULL) { // Check if it's a leaf node
        leaves[(*count)++] = node->val; // Add leaf value to array and increment count
    } else { // If it's not a leaf node, recurse on children
        addLeaves(node->left, leaves, count); // Recurse on left child
        addLeaves(node->right, leaves, count); // Recurse on right child
    }
}

// Function to compare leaf sequences of two trees
bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int leaves1[100], leaves2[100], count1 = 0, count2 = 0;
    addLeaves(root1, leaves1, &count1);
    addLeaves(root2, leaves2, &count2);

    if (count1 != count2) {
        return false;
    }
    for (int i = 0; i < count1; i++) {
        if (leaves1[i] != leaves2[i]) {
            return false;
        }
    }
    return true;
}
