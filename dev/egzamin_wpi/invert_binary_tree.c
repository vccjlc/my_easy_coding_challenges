// Given the root of a binary tree, invert the tree, and return its root.

// Recursive function to invert a binary tree
TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) return NULL;

    // Swap the left and right subtrees
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively invert the left and right subtrees
    invertTree(root->left);
    invertTree(root->right);

    return root;
}
