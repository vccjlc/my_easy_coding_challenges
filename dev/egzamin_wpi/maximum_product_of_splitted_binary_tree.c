/*

Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.

Note that you need to maximize the answer before taking the mod and not after taking it.


***

To solve this problem, you can perform a two-pass Depth-First Search (DFS) on the binary tree. In the first pass, compute the total sum of all nodes in the tree. In the second pass, for each node, calculate the sum of the subtree rooted at that node, and use it to compute the product of the sum of the subtree and the sum of the remaining part of the tree. Keep track of the maximum product found during the traversal.

Here's a step-by-step approach:

First DFS pass: Compute the total sum of the tree. This sum represents the sum of all nodes in the tree and will be used to compute the sum of the "other" subtree when we consider splitting the tree at any node.

Second DFS pass: For each node, calculate the sum of the subtree rooted at that node. The product of this sum and the sum of the rest of the tree (total sum - subtree sum) gives the product for the split at this node. Keep track of the maximum product.

Return the result: Since the result can be large, return the maximum product found modulo 

*/

#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Helper function to create a new tree node
TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// First DFS pass to compute total sum of the tree
long dfsTotalSum(TreeNode* root) {
    if (!root) return 0;
    return root->val + dfsTotalSum(root->left) + dfsTotalSum(root->right);
}

// Second DFS pass to find the maximum product
long dfsMaxProduct(TreeNode* root, long totalSum, long* maxProduct) {
    if (!root) return 0;

    // Sum of the subtree rooted at the current node
    long subtreeSum = root->val + dfsMaxProduct(root->left, totalSum, maxProduct) + dfsMaxProduct(root->right, totalSum, maxProduct);

    // Product of the sum of the current subtree and the rest of the tree
    long product = subtreeSum * (totalSum - subtreeSum);

    // Update maxProduct if the current product is greater
    if (product > *maxProduct) *maxProduct = product;

    return subtreeSum;
}

// Main function to find the maximum product of sums of two subtrees
int maxProduct(TreeNode* root) {
    long maxProduct = 0;
    long totalSum = dfsTotalSum(root);
    dfsMaxProduct(root, totalSum, &maxProduct);
    return maxProduct % MOD;
}

// Example usage
int main() {
    // Construct the binary tree
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);

    int result = maxProduct(root);
    printf("Maximum product of sums of two subtrees: %d\n", result);

    // Free the allocated memory for the tree nodes (not shown here)

    return 0;
}

