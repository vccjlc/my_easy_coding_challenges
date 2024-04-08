/*

Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).



***

To find the maximum sum of all keys of any subtree which is also a Binary Search Tree (BST), you can perform a post-order traversal of the binary tree. At each node, you need to check whether the subtree rooted at that node is a BST. If it is, you calculate the sum of its keys and update the maximum sum if it's greater than the current maximum.

For each node, you need to return multiple pieces of information to its parent:

Whether the subtree rooted at this node is a BST.
The sum of keys in the subtree if it's a BST.
The minimum and maximum keys in the subtree to help the parent determine if the parent's subtree is a BST.


*/



#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

// Utility structure to return multiple values from the recursive function
typedef struct Result {
    int isBST;  // 1 if the subtree is a BST, 0 otherwise
    int sum;    // Sum of all nodes in the subtree if it's a BST
    int minKey; // Minimum key in the subtree
    int maxKey; // Maximum key in the subtree
} Result;

int maxSum = 0;  // Global variable to keep track of the maximum sum of BST subtrees

// Recursive function to calculate the maximum sum of BST subtrees
Result dfs(TreeNode* node) {
    // Base case: an empty subtree is a BST with a sum of 0
    if (!node) return (Result){1, 0, INT_MAX, INT_MIN};

    // Recursively calculate for left and right subtrees
    Result left = dfs(node->left);
    Result right = dfs(node->right);

    // Check if the current subtree is a BST
    if (left.isBST && right.isBST && node->val > left.maxKey && node->val < right.minKey) {
        // Calculate the sum of keys in the current subtree
        int sum = left.sum + right.sum + node->val;
        // Update the maximum sum
        if (sum > maxSum) maxSum = sum;
        // Return the result for the current subtree
        return (Result){1, sum, left.minKey != INT_MAX ? left.minKey : node->val, right.maxKey != INT_MIN ? right.maxKey : node->val};
    }

    // If the current subtree is not a BST, return isBST as 0 and keep the maximum sum unchanged
    return (Result){0, 0, 0, 0};
}

// Main function to find the maximum sum of BST subtrees
int maxSumBST(TreeNode* root) {
    maxSum = 0;  // Reset the global variable
    dfs(root);   // Start the DFS from the root
    return maxSum;
}

// Example usage
int main() {
    // Construct the binary tree here
    TreeNode* root = newNode(1);
    root->left = newNode(4);
    root->right = newNode(3);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->left = newNode(2);
    root->right->right = newNode(5);
    root->right->right->left = newNode(4);
    root->right->right->right = newNode(6);

    int result = maxSumBST(root);
    printf("Maximum sum of all keys of any BST subtree: %d\n", result);

    // Free the allocated memory for the tree nodes (not shown here)

    return 0;
}

