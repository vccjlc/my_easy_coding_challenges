int checkMaxLeaf(struct TreeNode* node, int* max) {
    // Base case: If the current node is NULL, return the current max
    if (node == NULL) {
        return *max;
    }

    // Leaf node: If both left and right children are NULL, update max if the current node's value is greater
    if (node->left == NULL && node->right == NULL) {
        if (node->val > *max) {
            *max = node->val; // Update max with the value of the current leaf node
        }
    } else {
        // Recursive case: Traverse the left and right subtrees
        checkMaxLeaf(node->left, max);
        checkMaxLeaf(node->right, max);
    }

    return *max;
}

// Wrapper function to simplify the initial call to checkMaxLeaf
int findMaxLeafValue(struct TreeNode* root) {
    int max = INT_MIN; // Initialize max to the smallest possible integer value
    return checkMaxLeaf(root, &max); // Pass the address of max to keep track of the maximum leaf value
}

