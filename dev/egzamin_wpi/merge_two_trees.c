/*

You are given two binary trees root1 and root2.

Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.

Return the merged tree.

Note: The merging process must start from the root nodes of both trees.

*/	

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2) {

    if (!root1) return root2;
    if (!root2) return root1;


    struct TreeNode* merged_tree = malloc(sizeof(struct TreeNode));
    if (!merged_tree) return NULL;

    merged_tree->val = (root1 ? root1->val : 0) + (root2 ? root2->val : 0);

    merged_tree->left = mergeTrees(root1 ? root1->left : NULL, root2 ? root2->left : NULL);
    merged_tree->right = mergeTrees(root1 ? root1->right : NULL, root2 ? root2->right : NULL);


    return merged_tree;

} 
