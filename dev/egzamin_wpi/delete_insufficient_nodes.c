/*

Given the root of a binary tree and an integer limit, delete all insufficient nodes in the tree simultaneously, and return the root of the resulting binary tree.

A node is insufficient if every root to leaf path intersecting this node has a sum strictly less than limit.

A leaf is a node with no children.



To delete all insufficient nodes in a binary tree with respect to a given limit, you can use a recursive function that traverses the tree in a post-order fashion (left-right-root). The function will calculate the sum of the path from the root to each leaf, and if the sum is less than the limit, it will delete the node.

*/

#include <stdio.h>
#include <stdlib.h>

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

// Helper function to delete a tree node
void deleteNode(TreeNode* node) {
    if (node) {
        deleteNode(node->left);
        deleteNode(node->right);
        free(node);
    }
}

// Recursive function to remove insufficient nodes
TreeNode* removeInsufficientNodes(TreeNode* root, int limit, int sum) {
    if (!root) return NULL;

    // Include the current node's value in the sum
    sum += root->val;

    // If it's a leaf and the sum is less than the limit, delete this node
    if (!root->left && !root->right && sum < limit) {
        deleteNode(root);
        return NULL;
    }

    // Post-order traversal to check subtrees
    root->left = removeInsufficientNodes(root->left, limit, sum);
    root->right = removeInsufficientNodes(root->right, limit, sum);

    // If both subtrees are pruned and the current node becomes a leaf, check it again
    if (!root->left && !root->right && sum < limit) {
        deleteNode(root);
        return NULL;
    }

    return root;
}

// Wrapper function that initiates the pruning process
TreeNode* sufficientSubset(TreeNode* root, int limit) {
    return removeInsufficientNodes(root, limit, 0);
}

// Example usage
int main() {
    // Construct the binary tree here...
    TreeNode* root = newNode(1);
    // ... Populate the tree with nodes
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(10);
    root->right->left->left = newNode(11);
    // ...

    int limit = 22;
    TreeNode* resultRoot = sufficientSubset(root, limit);

    // The binary tree is now pruned. Use resultRoot for further processing.
    // Add code to print the tree inorder to verify the result (not shown here)
return 0;
}
