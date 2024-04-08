/*

find distance between three nodes given by pointers. Distance is the shortest path that will visit all three of them

***

Finding the shortest path that visits three nodes in a binary tree, given pointers to the nodes, involves the following steps:

Find the Lowest Common Ancestor (LCA): Determine the LCAs for the pairs of nodes. You'll have to find the LCA for two pairs out of the three nodes (e.g., LCA of node1 and node2, then LCA of node3 with the result of the first LCA).

Calculate Distances: Compute the distances from the LCA to each of the nodes.

Sum the Distances: Add the distances together to get the total distance that visits all three nodes.

To find the LCA of two nodes using pointers, you need a function that traverses the tree and checks if the current node matches any of the two nodes. The LCA is the node where the search paths for the two nodes diverge.

*/


#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Helper function to find the LCA of two nodes given by pointers
TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;

    TreeNode* left = findLCA(root->left, p, q);
    TreeNode* right = findLCA(root->right, p, q);

    if (left && right) return root;  // If p and q found in diff. branches, root is LCA.
    return left ? left : right;  // Else return the non-null child.
}

// Helper function to find the distance from a node to a given target node
int findDistance(TreeNode* root, TreeNode* target, int level) {
    if (!root) return -1;
    if (root == target) return level;

    int left = findDistance(root->left, target, level + 1);
    if (left != -1) return left;

    return findDistance(root->right, target, level + 1);
}

// Function to find the shortest path that visits all three nodes given by pointers
int findShortestPath(TreeNode* root, TreeNode* p1, TreeNode* p2, TreeNode* p3) {
    TreeNode* lca_p1_p2 = findLCA(root, p1, p2);
    TreeNode* lca_all = findLCA(root, lca_p1_p2, p3);

    int dist_p1 = findDistance(lca_all, p1, 0);
    int dist_p2 = findDistance(lca_all, p2, 0);
    int dist_p3 = findDistance(lca_all, p3, 0);

    return dist_p1 + dist_p2 + dist_p3;  // The total distance is the sum of individual distances to the LCA.
}

int main() {
    // Construct the binary tree and pointers to the nodes
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = 1;
    root->left = (TreeNode*)malloc(sizeof(TreeNode));
    root->right = (




