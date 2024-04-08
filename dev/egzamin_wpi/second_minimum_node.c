/*

Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. More formally, the property root.val = min(root.left.val, root.right.val) always holds.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.



In this special binary tree, since every non-leaf node's value is the minimum of its children, the root always has the minimum value in the entire tree. Therefore, the second minimum value must be the root of the smallest value that is larger than the root, which can only be found in the root's subtrees.

*/

#include <limits.h> // For INT_MAX
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int findSecondMinimumValue(struct TreeNode* root) {
    if (!root || !root->left) return -1; // If it's a leaf or empty node

    int leftVal = root->left->val;
    int rightVal = root->right->val;

    // If the left value is the same as root value, we need to find the next minimum in left subtree
    if (leftVal == root->val) {
        leftVal = findSecondMinimumValue(root->left);
    }

    // Similarly for the right child
    if (rightVal == root->val) {
        rightVal = findSecondMinimumValue(root->right);
    }

    // If we found a second minimum in both left and right subtree, return the smaller one
    if (leftVal != -1 && rightVal != -1) {
        return leftVal < rightVal ? leftVal : rightVal;
    }

    // If we found a second minimum in either left or right subtree, return it
    if (leftVal != -1) return leftVal;
    if (rightVal != -1) return rightVal;

    // If no second minimum was found in either subtree, return -1
    return -1;
}

