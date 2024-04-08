/*

Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.


To determine whether one binary tree is a subtree of another, you need to compare the nodes of the two trees. The algorithm typically involves a recursive function that traverses the larger tree (root) and for each node in the larger tree, another recursive function checks if the subtree starting at that node matches the smaller tree (subRoot).

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Helper function to check if two trees are identical
int isIdentical(TreeNode *tree1, TreeNode *tree2) {
    if (tree1 == NULL && tree2 == NULL) return 1;
    if (tree1 == NULL || tree2 == NULL) return 0;
    
    if (tree1->val != tree2->val) return 0;

    return isIdentical(tree1->left, tree2->left) && isIdentical(tree1->right, tree2->right);
}

// Main function to check if there is a subtree of root with the same structure and node values of subRoot
int isSubtree(TreeNode *root, TreeNode *subRoot) {
    if (root == NULL) return 0; // The larger tree is empty
    if (subRoot == NULL) return 1; // An empty tree is always a subtree

    if (isIdentical(root, subRoot)) return 1;

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

// Helper function to create a new TreeNode
TreeNode* createTreeNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    // Example usage:
    // Tree root = [3,4,5,1,2], subRoot = [4,1,2]
    TreeNode* root = createTreeNode(3);
    root->left = createTreeNode(4);
    root->right = createTreeNode(5);
    root->left->left = createTreeNode(1);
    root->left->right = createTreeNode(2);

    TreeNode* subRoot = createTreeNode(4);
    subRoot->left = createTreeNode(1);
    subRoot->right = createTreeNode(2);

    int result = isSubtree(root, subRoot);
    printf("Is subRoot a subtree of root? %s\n", result ? "Yes" : "No");

    // Free memory if needed and perform other cleanups

    return 0;
}


