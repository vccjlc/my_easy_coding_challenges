/*

You are given the root of a binary tree and an integer sum and integer k

Return the node closest to root from which the path starts such that the sum of the path is equal to sum and the length of the path is k



To find the node closest to the root from which a path starts, with the path sum equal to a given sum and the length of the path equal to k, we can use a recursive depth-first search (DFS) strategy. The approach involves exploring each possible path from the root, keeping track of the current path length, and checking if the conditions (path length equals k and path sum equals the given sum) are met.

Here's a general approach:

DFS Function: Implement a DFS function that traverses the tree. This function should keep track of the current path sum, the path length, and store the current path in a data structure (like an array or a list).

Checking Conditions: At each step of the DFS, check if the current path length is equal to k. If it is, then check if the current path sum equals the given sum. If both conditions are met, return the starting node of this path.

Backtracking: As you return from the recursive calls, make sure to backtrack by removing the current node from the path and adjusting the current path sum and length.

Closest to Root: To ensure you find the node closest to the root, start the DFS from the root and search in a top-down manner. The first node you find that meets the conditions is the one closest to the root.


*/

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

// Helper function for DFS
struct TreeNode* dfs(struct TreeNode* node, int currentSum, int sum, int k, int currentLength, int* path) {
    if (node == NULL || currentLength > k) {
        return NULL;
    }

    // Update the current path and sum
    currentSum += node->val;
    path[currentLength] = node->val;
    currentLength++;

    // Check if the current path meets the conditions
    if (currentLength == k && currentSum == sum) {
        return node;  // Return the starting node of the path
    }

    // Continue the search in the left and right subtrees
    struct TreeNode* leftResult = dfs(node->left, currentSum, sum, k, currentLength, path);
    if (leftResult != NULL) {
        return leftResult;  // Path found in the left subtree
    }

    struct TreeNode* rightResult = dfs(node->right, currentSum, sum, k, currentLength, path);
    if (rightResult != NULL) {
        return rightResult;  // Path found in the right subtree
    }

    // Backtrack
    currentLength--;
    currentSum -= node->val;

    return NULL;  // No valid path found starting from this node
}

// Main function to find the node
struct TreeNode* findStartingNode(struct TreeNode* root, int sum, int k) {
    int path[k];  // Assuming maximum path length is k
    return dfs(root, 0, sum, k, 0, path);
}

