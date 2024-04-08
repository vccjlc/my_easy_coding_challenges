// Function to merge two trees to create infimum
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 == NULL && t2 == NULL) return NULL; // If both nodes are NULL, return NULL
    if (t1 == NULL) return t2; // If t1 is NULL, return t2
    if (t2 == NULL) return t1; // If t2 is NULL, return t1

    // Create a new node with the smaller value among t1 and t2
    TreeNode* root = createNode(t1->value < t2->value ? t1->value : t2->value);

    // Recursively merge the left and right subtrees
    root->left = mergeTrees(t1->left, t2->left);
    root->right = mergeTrees(t1->right, t2->right);

    return root;
}

