/*


In a binary tree, a lonely node is a node that is the only child of its parent node. The root of the tree is not lonely because it does not have a parent node.
Given the root of a binary tree, retu an array containing the
values of all lonely nodes in the tree. Return the list in any order.

***


To find all the lonely nodes in a binary tree, you can perform a Depth-First Search (DFS) traversal of the tree and identify any nodes that are the only child of their parent. These nodes are considered "lonely". You can collect these nodes in a dynamic array or a linked list as you traverse the tree.



*/


#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void find_lonely_nodes_helper(struct TreeNode* root, int* array, int* index) {
    if (!root) return;

    // Check for lonely node: only one child exists.
    if ((root->left && !root->right) || (!root->left && root->right)) {
        array[(*index)++] = root->left ? root->left->val : root->right->val;
    }

    find_lonely_nodes_helper(root->left, array, index);
    find_lonely_nodes_helper(root->right, array, index);
}

int* find_lonely_nodes(struct TreeNode* root, int* returnSize) {
    // Estimate the maximum number of nodes that can be lonely (which is total nodes / 2).
    int* array = malloc(sizeof(int) * 1024); // Assuming 1024 is the maximum number of nodes
    *returnSize = 0; // Initialize the returnSize to 0.

    find_lonely_nodes_helper(root, array, returnSize);

    return array;
}s
