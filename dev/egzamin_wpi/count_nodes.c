int count_nodes(struct TreeNode* root) {
    if (!root) return 0; // Base case: If the tree is empty, return 0
    int left_nodes = count_nodes(root->left); // Count nodes in the left subtree
    int right_nodes = count_nodes(root->right); // Count nodes in the right subtree

    return 1 + left_nodes + right_nodes; // Count the current node and add to the count of left and right subtree nodes
}

