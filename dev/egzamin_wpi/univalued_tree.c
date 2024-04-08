/*

A binary tree is uni-valued if every node in the tree has the same value.

Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.


To check if a binary tree is uni-valued, you can use a simple recursive function that traverses the tree and checks if every node has the same value as the root node. Here's how you can implement this in C:

*/

int helper(struct TreeNode* root, int univalue) {
    if(!root) return 1;

    if(root->val != univalue) return 0;

    int left = helper(root->left, univalue);
    int right = helper(root->right, univalue);

    return (left + right == 2) ? 1 : 0;
}

bool isUnivalTree(struct TreeNode* root) {
    if (!root) return true;
    int univalue = root->val;
    return helper(root, univalue) == 1 ? true : false;
}

