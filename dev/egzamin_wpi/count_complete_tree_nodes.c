/*

Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.


For a complete binary tree, you can achieve a time complexity better than O(n)
 by taking advantage of its properties. The idea is to determine the depth of the leftmost and rightmost paths separately. If they are equal, the tree is a perfect binary tree, and you can compute the number of nodes directly using the formula 2^(h-1), where h is the height of the tree. If the depths are not equal, you recursively apply the same logic to the left and right subtrees. This approach significantly reduces the number of nodes that need to be visited.

 */
 
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
} TreeNode;

// Function to calculate the depth of the tree
int computeDepth(TreeNode* node) {
    int depth = 0;
    while (node != NULL) {
        depth++;
        node = node->left;
    }
    return depth;
}

// Main function to count the nodes in a complete binary tree
int countNodes(TreeNode* root) {
    if (root == NULL) return 0;

    int leftDepth = computeDepth(root->left);
    int rightDepth = computeDepth(root->right);

    if (leftDepth == rightDepth) {
        s// The left subtree is a perfect binary tree
        return (1 << leftDepth) + countNodes(root->right);
    } else {
        // The right subtree is a perfect binary tree
        return (1 << rightDepth) + countNodes(root->left);
    }
}

