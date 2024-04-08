/* Max Path Sum: Find the maximum path sum in the tree. The path may start and end at any node in the tree. 

Time complexity O(n)



*/

int maxPathSumUtil(TreeNode* node, int* globalMax) {
    if (node == NULL) return 0;

    // Calculate max path sum for left and right subtrees, ignoring paths with negative sums
    int leftMax = max(0, maxPathSumUtil(node->left, globalMax));
    int rightMax = max(0, maxPathSumUtil(node->right, globalMax));

    // Update global maximum if the path through the current node is greater
    *globalMax = max(*globalMax, node->value + leftMax + rightMax);

    // Return the maximum path sum including the current node
    return node->value + max(leftMax, rightMax);
}

int maxPathSum(TreeNode* root) {
    int globalMax = INT_MIN;  // Initialize global maximum with the smallest integer
    maxPathSumUtil(root, &globalMax);
    return globalMax;
}

