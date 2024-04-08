/*

Given the root of a binary tree, return the length of the longest path, where each node in the path has the same value. This path may or may not pass through the root.

The length of the path between two nodes is represented by the number of edges between them.


To solve this problem, a recursive depth-first search (DFS) approach can be used. The idea is to go through each node and recursively find the longest path in both the left and right subtrees that includes the node itself with the same value.

The length of the longest path at each node will be the sum of the lengths of the left and right paths if the values of the left and right children are the same as the current node. While calculating this, we also keep track of the overall longest path found in the tree.

*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to find longest same value path starting from a given node
int longestUnivaluePathFromNode(struct TreeNode* node, int* maxLen) {
    if (!node) return 0;

    int leftLen = longestUnivaluePathFromNode(node->left, maxLen);
    int rightLen = longestUnivaluePathFromNode(node->right, maxLen);

    int leftPath = 0, rightPath = 0;

    if (node->left && node->val == node->left->val) {
        leftPath = leftLen + 1;
    }

    if (node->right && node->val == node->right->val) {
        rightPath = rightLen + 1;
    }

    // Update maxLen if the sum of leftPath and rightPath is greater
    *maxLen = (leftPath + rightPath) > *maxLen ? leftPath + rightPath : *maxLen;


    // Return the longer one of leftPath and rightPath
    return leftPath > rightPath ? leftPath : rightPath;
}

int longestUnivaluePath(struct TreeNode* root) {
    int maxLen = 0;
    longestUnivaluePathFromNode(root, &maxLen);
    return maxLen;
}

