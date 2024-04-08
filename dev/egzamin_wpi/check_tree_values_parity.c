// funciton to check if every left node has odd value, analog. right

bool checkTree(TreeNode* node, int depth) {
    // Base case: an empty node is considered valid
    if (!node) return true;

    // Check the node's value if it's not the root (depth > 0)
    if (depth > 0) {
        // For non-root nodes, check if left child nodes have odd values and right child nodes have even values
        if ((node->left && node->left->val % 2 == 0) || // Left child exists and has an even value
            (node->right && node->right->val % 2 != 0)) { // Right child exists and has an odd value
            return false;
        }
    }

    // Recursively check the left and right subtrees, increasing the depth
    return checkTree(node->left, depth + 1) && checkTree(node->right, depth + 1);
}


// When you call checkTree for the root node, you start with depth 0:
bool isValid = checkTree(root, 0);

