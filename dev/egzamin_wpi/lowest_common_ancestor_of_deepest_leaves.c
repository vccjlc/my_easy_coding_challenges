/*

Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.

Recall that:

The node of a binary tree is a leaf if and only if it has no children
The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is in the subtree with root A.


To find the lowest common ancestor (LCA) of the deepest leaves in a binary tree, you can use a depth-first search (DFS) approach to traverse the tree and keep track of the depth of each leaf node. During the traversal, you can also determine the LCA of the deepest leaves by comparing the depths of the left and right subtrees at each node.

Here's a step-by-step approach:

Depth Calculation: Perform a DFS traversal to calculate the depth of each node. The depth of a node is 1 more than the maximum depth of its children.

LCA Determination: During the DFS traversal, at each node, compare the depths of the left and right subtrees. If they are equal, it means the current node is the LCA of the deepest leaves (since the deepest leaves are at the same depth from this node). If they are not equal, the LCA is in the subtree with the larger depth.

Return LCA: The node that is identified as the LCA of the deepest leaves during the DFS traversal is returned as the result.


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

// Helper function to find the LCA of deepest leaves.
struct TreeNode* lcaDeepestLeavesHelper(struct TreeNode* root, int* depth) {
    if (!root) {
        *depth = 0;
        return NULL;
    }
    
    int leftDepth = 0, rightDepth = 0;
    struct TreeNode* left = lcaDeepestLeavesHelper(root->left, &leftDepth);
    struct TreeNode* right = lcaDeepestLeavesHelper(root->right, &rightDepth);
    
    *depth = 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
    
    if (leftDepth == rightDepth) {
        return root;
    } else if (leftDepth > rightDepth) {
        return left;
    } else {
        return right;
    }
}

// Function to find the LCA of the deepest leaves.
struct TreeNode* lcaDeepestLeaves(struct TreeNode* root) {
    int depth = 0;
    return lcaDeepestLeavesHelper(root, &depth);
}

// Example usage
int main() {
    // Construct a simple binary tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    struct TreeNode* lca = lcaDeepestLeaves(root);
    printf("The LCA of deepest leaves is: %d\n", lca->val);

    // Free the allocated memory for the tree nodes here...
    // This is left as an exercise.

    return 0;
}

