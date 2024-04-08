/*

find distance betweeen two nodes given by pointers

If you have pointers to the two nodes for which you need to find the distance, the approach changes slightly from when you have the values of the nodes. Since you cannot directly compare the values to find the Lowest Common Ancestor (LCA), you'll need to modify the LCA finding function to work with pointers instead.

*/


#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to find LCA of nodes pointed to by n1 and n2.
TreeNode* findLCA(TreeNode* root, TreeNode* n1, TreeNode* n2) {
    if (root == NULL || root == n1 || root == n2) return root;

    TreeNode* left_lca = findLCA(root->left, n1, n2);
    TreeNode* right_lca = findLCA(root->right, n1, n2);

    if (left_lca && right_lca) return root;
    return left_lca ? left_lca : right_lca;
}

// Helper function to find the distance from the root to a given node pointed to by p.
int findDistance(TreeNode* root, TreeNode* p, int distance) {
    if (root == NULL) return -1;
    if (root == p) return distance;

    int left = findDistance(root->left, p, distance + 1);
    if (left != -1) return left;

    return findDistance(root->right, p, distance + 1);
}

// Function to find the distance between two nodes pointed to by p1 and p2.
int findDistanceBetweenNodes(TreeNode* root, TreeNode* p1, TreeNode* p2) {
    TreeNode* lca = findLCA(root, p1, p2);
    int d1 = findDistance(lca, p1, 0);
    int d2 = findDistance(lca, p2, 0);
    return d1 + d2;
}

int main() {
    // Construct the binary tree and get pointers to the nodes
    TreeNode* root = (TreeNode


