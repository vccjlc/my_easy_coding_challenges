/*

To trim a Binary Search Tree (BST) so that all its elements lie in the range [L, R]
 (inclusive), you can use a recursive approach. For each node, you need to decide whether to keep it, trim it, or replace it with one of its subtrees based on its value relative to L and R.

Here's the strategy:

If a node's value is less than L, then the trimmed tree must be in the right subtree (since all values in the left subtree are also less than L, and thus outside the range).

If a node's value is greater than R, then the trimmed tree must be in the left subtree (since all values in the right subtree are also greater than R, and thus outside the range).
If a node's value is within the range [L, R], we recursively trim its left and right subtrees, and keep the current node.

*/

TreeNode* trimBST(TreeNode* root, int L, int R) {
    if (root == NULL) return NULL;

    // If the current node's value is less than L, then the trimmed tree is in the right subtree
    if (root->value < L) return trimBST(root->right, L, R);

    // If the current node's value is greater than R, then the trimmed tree is in the left subtree
    if (root->value > R) return trimBST(root->left, L, R);

    // If the current node's value is within the range [L, R], trim its subtrees
    root->left = trimBST(root->left, L, R);
    root->right = trimBST(root->right, L, R);

    return root;
}

