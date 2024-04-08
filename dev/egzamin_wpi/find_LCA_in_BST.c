#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode *left, *right;
} TreeNode;

// Function to find the LCA in a BST
TreeNode* findLCAInBST(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL) return NULL;

    // If both p and q are greater than root, then LCA lies in right subtree
    if (root->value < p->value && root->value < q->value) {
        return findLCAInBST(root->right, p, q);
    }
    // If both p and q are lesser than root, then LCA lies in left subtree
    else if (root->value > p->value && root->value > q->value) {
        return findLCAInBST(root->left, p, q);
    }
    // If one of p or q is less than root and the other is greater, root is the LCA
    else {
        return root;
    }
}

int main() {
    // Example BST construction
    TreeNode n1 = {2, NULL, NULL};
    TreeNode n2 = {8, NULL, NULL};
    TreeNode n3 = {6, &n1, &n2}; // n3 is parent of n1 and n2
    TreeNode n4 = {14, NULL, NULL};
    TreeNode n5 = {10, &n3, &n4}; // n5 is the root and parent of n3 and n4

    TreeNode* lca = findLCAInBST(&n5, &n1, &n4); // Should return n5 as the LCA of n1 and n4

    if (lca != NULL) {
        printf("LCA of %d and %d is %d\n", n1.value, n4.value, lca->value);
    } else {
        printf("LCA not found.\n");
    }

    return 0;
}

