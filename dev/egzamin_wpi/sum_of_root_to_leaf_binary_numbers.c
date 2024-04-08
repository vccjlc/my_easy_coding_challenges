/*


You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit.

For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.

The test cases are generated so that the answer fits in a 32-bits integer.

*/


int dfs(struct TreeNode* root, int value) {
    if (!root) return 0;

    value = value * 2 + root->val;
    // The same as value = (value << 1) | node->value;

    // If it's a leaf node, return the current value.
    if (root->left == NULL && root->right == NULL) {
        return value;
    }

    // Recurse on left and right children.
    int leftSum = dfs(root->left, value);
    int rightSum = dfs(root->right, value);

    // Return the sum of values from both subtrees.
    return leftSum + rightSum;
}

int sumRootToLeaf(struct TreeNode* root) {
    return dfs(root, 0);
}

