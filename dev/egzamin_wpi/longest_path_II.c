/*


Given the root of a binary tree, return the length of the longest consecutive path in the tree.
A consecutive path is a path where the values of the consecutive nodes in the path differ by one. This path can be either increasing or decreasing.


For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is not valid.
On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.


To solve this problem, we can perform a depth-first search (DFS) where at each node we will return both the length of the increasing and decreasing consecutive sequences that end at the current node. We will consider four cases at each node:

The consecutive sequence increases from the left child to the current node.
The consecutive sequence increases from the current node to the right child.
The consecutive sequence decreases from the left child to the current node.
The consecutive sequence decreases from the current node to the right child.
We will recursively calculate these values for the children of the current node and use them to update the lengths of the consecutive sequences at the current node. While doing so, we keep track of the maximum length seen so far.


*/


#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// A utility function to create a new Binary Tree node
TreeNode* newNode(int val) {
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Helper function to find the longest consecutive sequence
void longestConsecutiveHelper(TreeNode* node, int* maxLength, int currentLength, int expected, int direction) {
    if (node == NULL) {
        return;
    }
    if (node->val == expected) {
        currentLength++;
    } else {
        currentLength = 1;
    }

    *maxLength = (currentLength > *maxLength) ? currentLength : *maxLength;

    longestConsecutiveHelper(node->left, maxLength, currentLength, node->val + direction, direction);
    longestConsecutiveHelper(node->right, maxLength, currentLength, node->val + direction, direction);
}

// Main function to find the longest consecutive sequence
int longestConsecutive(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int maxLength = 0;

    // Check increasing sequences using +1
    longestConsecutiveHelper(root, &maxLength, 0, root->val, 1);
    // Check decreasing sequences using -1
    longestConsecutiveHelper(root, &maxLength, 0, root->val, -1);

    return maxLength;
}


