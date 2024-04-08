#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode *left, *right;
} TreeNode;

int countRightNodes(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    int count = 0;
    if (root->right != NULL) {
        count = 1 + countRightNodes(root->right);
    }
    count += countRightNodes(root->left); // Continue to traverse the rest of the tree

    return count;
}

