/*

Given the root of a binary tree, return the inorder traversal of its nodes' values.


*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int count_nodes(struct TreeNode* root) {
    if (!root) return 0; // Base case: If the tree is empty, return 0
    int left_nodes = count_nodes(root->left); // Count nodes in the left subtree
    int right_nodes = count_nodes(root->right); // Count nodes in the right subtree
    return 1 + left_nodes + right_nodes; // Count the current node and add to the count of left and right subtree nodes
}

void helper(int* array, struct TreeNode* root, int* index) {
    if (!root) return;
    helper(array, root->left, index);
    array[(*index)++] = root->val;
    helper(array, root->right, index);
}
 
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int node_count = count_nodes(root);
    *returnSize = node_count;
    int* array = malloc(sizeof(int)*node_count);
    if (!array) {
        *returnSize = 0;
        return NULL;
    }
    int index = 0;
    helper(array, root, &index);
    return array;
}

