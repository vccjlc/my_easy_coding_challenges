/*


To solve the "Path Sum" problem, you can use a recursive approach to traverse the tree and keep track of the remaining sum as you go down from the root to the leaf nodes. At each node, you subtract the node's value from the sum. A path with the given sum exists if you can reach a leaf node (a node with no children) and the remaining sum equals the node's value.

*/

// Recursive function to check if there's a root-to-leaf path with the given sum
int hasPathSum(TreeNode* root, int sum) {
    // Base case: if the tree is empty
    if (root == NULL) {
        return 0;
    }

    // Check if we've reached a leaf node and the remaining sum equals the node's value
    if (root->left == NULL && root->right == NULL && root->value == sum) {
        return 1;  // Found the path
    }

    // Recursively check the left and right subtrees with the updated sum
    return hasPathSum(root->left, sum - root->value) || hasPathSum(root->right, sum - root->value);
}

int main() {
    // Create an example tree
    TreeNode* root = createNode(5);
    root->left = createNode(4);
    root->right = createNode(8);
    root->left->left = createNode(11);
    root->right->left = createNode(13);
    root->right->right = createNode(4);
    root->left->left->left = createNode(7);
    root->left->left->right = createNode(2);
    root->right->right->right = createNode(1);

    int sum = 22;

    if (hasPathSum(root, sum)) {
        printf("There exists a root-to-leaf path with sum %d.\n", sum);
    } else {
        printf("There is no root-to-leaf path with sum %d.\n", sum);
    }

    return 0;
}
