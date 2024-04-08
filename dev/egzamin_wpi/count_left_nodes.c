int countLeftNodes(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    int count = 0;
    if (root->left != NULL) {
        // If a left child exists, increment the count and recurse down the left subtree
        count = 1 + countLeftNodes(root->left);
    }
    // Also, continue to traverse down the right subtree to check for left children there
    count += countLeftNodes(root->right);

    return count;
}

