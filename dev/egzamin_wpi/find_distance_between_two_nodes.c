/*


find distance between two given nodes in a binary tree


To find the distance between two given nodes in a binary tree, you can use the following approach:

Find the Lowest Common Ancestor (LCA) of the two nodes.
Calculate the distance from the LCA to each of the two nodes.
The distance between the two nodes is the sum of the distances from each node to the LCA.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* newNode(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = data;
    node->left = node->right = NULL;
    return node;
}

// Function to find LCA of two nodes n1 and n2.
TreeNode* findLCA(TreeNode* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->val == n1 || root->val == n2) return root;

    TreeNode* left_lca = findLCA(root->left, n1, n2);
    TreeNode* right_lca = findLCA(root->right, n1, n2);

    if (left_lca && right_lca) return root;
    return (left_lca != NULL) ? left_lca : right_lca;
}

// Helper function to find the distance from the root to a given node.
int findDistance(TreeNode* root, int val, int distance) {
    if (root == NULL) return -1;
    if (root->val == val) return distance;

    int left = findDistance(root->left, val, distance + 1);
    if (left != -1) return left;

    return findDistance(root->right, val, distance + 1);
}

// Function to find the distance between two nodes.
int findDistanceBetweenNodes(TreeNode* root, int n1, int n2) {
    TreeNode* lca = findLCA(root, n1, n2);
    
    int d1 = findDistance(lca, n1, 0);
    int d2 = findDistance(lca, n2, 0);

    return d1 + d2; // The distance between the two nodes is the sum of the distances to the LCA.
}

// Main function
int main() {
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int n1 = 4, n2 = 5;
    printf("The distance between node %d and node %d is %d.\n",
           n1, n2, findDistanceBetweenNodes(root, n1, n2));

    // Free the allocated memory (not shown here)

    return 0;
}

