// write a function to calculate the number of edges


/*

there is a simple formula to find the number of edges in a binary tree given the number of nodes. In any tree (not just binary trees), the number of edges is always one less than the number of nodes. This is because every tree is a connected graph with no cycles, and each edge connects two nodes.

So, if N is the number of nodes in a binary tree, the number of edges E is:

�
=
�
−
1
E=N−1

*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for tree nodes
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

// Utility function to create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Recursive function to count the number of edges in the binary tree
int countEdges(struct TreeNode* root) {
    if (root == NULL) {
        // Base case: if the current node is NULL, it contributes 0 edges
        return 0;
    }

    // Count edges in the left and right subtrees
    int leftEdges = countEdges(root->left);
    int rightEdges = countEdges(root->right);

    // The total number of edges for this subtree is the sum of left edges and right edges
    // plus 1 for each non-null child
    int totalEdges = leftEdges + rightEdges;
    if (root->left != NULL) totalEdges++;
    if (root->right != NULL) totalEdges++;

    return totalEdges;
}

int main() {
    // Example usage
    // struct TreeNode* root = createNode(1);
    // root->left = createNode(2);
    // root->right = createNode(3);
    // root->left->left = createNode(4);
    // root->left->right = createNode(5);
    // root->right->left = createNode(6);
    // root->right->right = createNode(7);

    // int edgeCount = countEdges(root);
    // printf("Number of edges in the tree: %d\n", edgeCount);

    return 0;
}

