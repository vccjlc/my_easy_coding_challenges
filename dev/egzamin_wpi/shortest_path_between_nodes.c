// Find shortest path between nodes given by pointers


#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode *left, *right;
} TreeNode;

// Helper function to find the LCA of two nodes in a binary tree
TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL || root == p || root == q) return root;

    TreeNode* left = findLCA(root->left, p, q);
    TreeNode* right = findLCA(root->right, p, q);

    if (left != NULL && right != NULL) return root;
    return left != NULL ? left : right;
}

// Helper function to find the level (distance from the root) of a given node
int findLevel(TreeNode* root, TreeNode* p, int level) {
    if (root == NULL) return -1;
    if (root == p) return level;

    int left = findLevel(root->left, p, level + 1);
    if (left == -1) {
        return findLevel(root->right, p, level + 1);
    }
    return left;
}

// Function to calculate the shortest path between two nodes in a binary tree
int shortestPath(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* lca = findLCA(root, p, q);

    int pDist = findLevel(lca, p, 0);
    int qDist = findLevel(lca, q, 0);

    return pDist + qDist; // Sum of distances from LCA to each node
}

