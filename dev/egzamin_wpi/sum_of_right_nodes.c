int sumOfRightNodes(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    int sum = 0;
    if (root->right != NULL) {
        sum = root->right->value + sumOfRightNodes(root->right);
    }
    sum += sumOfRightNodes(root->left); // Continue to traverse the rest of the tree

    return sum;
}

