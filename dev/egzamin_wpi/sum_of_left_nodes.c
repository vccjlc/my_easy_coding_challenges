int sumOfLeftNodes(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    int sum = 0;
    if (root->left != NULL) {
        // If a left child exists, add its value to the sum and recurse down the left subtree
        sum = root->left->value + sumOfLeftNodes(root->left);
    }
    // Also, continue to traverse down the right subtree to accumulate values of left children there
    sum += sumOfLeftNodes(root->right);

    return sum;
}

