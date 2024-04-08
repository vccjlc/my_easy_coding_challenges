#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode *left, *right;
} TreeNode;

// Function to find the Lowest Common Ancestor (LCA)
TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q) {
    // Base case: if root is NULL or equals to one of the nodes
    if (root == NULL || root == p || root == q) {
        return root;
    }

    // Search for nodes in left and right subtrees
    TreeNode* left = findLCA(root->left, p, q);
    TreeNode* right = findLCA(root->right, p, q);

    // If both subtrees return non-NULL, it means both nodes are in different subtrees,
    // so this node is their LCA
    if (left != NULL && right != NULL) {
        return root;
    }

    // Else, return the non-NULL node
    return left ? left : right;
}

int main() {
    // Example tree construction
    TreeNode n1 = {1, NULL, NULL};
    TreeNode n2 = {2, NULL, NULL};
    TreeNode n3 = {3, &n1, &n2}; // n3 is parent of n1 and n2
    TreeNode n4 = {4, NULL, NULL};
    TreeNode n5 = {5, &n3, &n4}; // n5 is the root and parent of n3 and n4

    TreeNode* lca = findLCA(&n5, &n1, &n2); // Should return n3 as the LCA of n1 and n2

    if (lca != NULL) {
        printf("LCA of %d and %d is %d\n", n1.value, n2.value, lca->value);
    } else {
        printf("LCA not found.\n");
    }

    return 0;
}

