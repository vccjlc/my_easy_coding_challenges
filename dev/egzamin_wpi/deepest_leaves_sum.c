/*

Given the root of a binary tree, return the sum of values of its deepest leaves.


***

We can do a simple Depth-First Traversal on the Tree. We can obviously do one dfs traversal and find the depth of the deepest level and in the second dfs pass, we will add only those nodes that are on the deepest level. But we don't actually need two passes. This can be done in just one DFS pass.

We maintain sum which will store sum of values of deepest level nodes till now and deepest which will store the depth or level of the deepest nodes. There will be following cases available to us where current Node is -

Not a Leaf Node - Traverse the left and right node of the current node.
A Leaf Node - This case will have 3 sub-cases possible -
depth > deepest - If current node is the deepest node observed till now, reset the sum to current node value and set deepest = depth.
depth == deepest - The current node is part of the deepest nodes observed till now. Add current root value to sum.
depth < deepest - This node is not the deepest node. Just ignore this node.
A NULL Node - We can't traverse any further. So just return.
Lastly, we will return the sum accumulated till now. The finaly value stored in sum will contain only the sum of value of the nodes (leaves) at deepest level. The implementation of this is given below


*/


/**
 * Definition for a binary tree node.
 * struct struct TreeNode {
 *     int val;
 *     struct struct TreeNode *left;
 *     struct struct TreeNode *right;
 * };
 */


// Helper function to create a new tree node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Recursive helper function to find the sum of deepest leaves
void deepestLeavesSumHelper(struct TreeNode* root, int level, int* maxDepth, int* sum) {
    if (root == NULL) {
        return;
    }

    // If this is the deepest level seen so far
    if (level > *maxDepth) {
        *maxDepth = level;
        *sum = root->val;  // Start a new sum for the new deepest level
    } else if (level == *maxDepth) {
        *sum += root->val;  // Add to the existing sum
    }

    // Recur for left and right subtrees with increased level
    deepestLeavesSumHelper(root->left, level + 1, maxDepth, sum);
    deepestLeavesSumHelper(root->right, level + 1, maxDepth, sum);
}

// Main function to find the sum of the deepest leaves
int deepestLeavesSum(struct TreeNode* root) {
    int maxDepth = -1;
    int sum = 0;
    deepestLeavesSumHelper(root, 0, &maxDepth, &sum);
    return sum;
}

