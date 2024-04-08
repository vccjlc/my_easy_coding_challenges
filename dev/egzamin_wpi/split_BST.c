/*


Contest 70: Problem 2 - Split BST
Given a Binary Search Tree (BST) with root node root, and a target value V, split the tree into two subtrees where one subtree has nodes that are all smaller or equal to the target value, while the other subtree has all nodes that are greater than the target value. It's not necessarily the case that the tree contains a node with value V.
Additionally, most of the structure of the original tree should remain. Formally, for any child C with parent P in the original tree, if they are both in the same subtree after the split, then node C should still have the parent P.
You should output the root TreeNode of both subtrees after splitting, in any order.
Note:
• The size of the BST will not exceed 50.
•
The BST is always valid and each node's value is different.




*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Helper function to create a new TreeNode
TreeNode* createTreeNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to split the BST
void splitBST(TreeNode* root, int V, TreeNode** left, TreeNode** right) {
    if (!root) {
        *left = NULL;
        *right = NULL;
        return;
    }

    if (root->val <= V) {
        // Include this node in the left subtree
        *left = root;
        splitBST(root->right, V, &(root->right), right);
    } else {
        // Include this node in the right subtree
        *right = root;
        splitBST(root->left, V, left, &(root->left));
    }
}

int main() {
    // Example usage:
    // Create the root of the BST
    TreeNode* root = createTreeNode(4);
    // Construct the BST
    root->left = createTreeNode(2);
    root->right = createTreeNode(6);
    root->left->left = createTreeNode(1);
    root->left->right = createTreeNode(3);
    root->right->left = createTreeNode(5);
    root->right->right = createTreeNode(7
...
