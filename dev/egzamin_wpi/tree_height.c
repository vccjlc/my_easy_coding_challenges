#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

int max(int value1, int value2) {
    return value1 > value2 ? value1 : value2;
}

int height(TreeNode* root) {
    if (!root) return -1;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    return 1 + max(leftHeight, rightHeight);
}
