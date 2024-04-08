#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode *left, *right;
} TreeNode;

// Recursive function to check if two binary trees are the same
int isSameTree(TreeNode* p, TreeNode* q) {
    // Both nodes are NULL, so the trees are the same up to this point
    if (p == NULL && q == NULL) return 1;

    // Only one of the nodes is NULL, or the values of the nodes are different
    if (p == NULL || q == NULL || p->value != q->value) return 0;

    // Recursively check the left and right subtrees
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

