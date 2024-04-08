/*
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    
    if (!root) return 0;

    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);

    return left_depth > right_depth ? 1+ left_depth : 1 + right_depth;
}
