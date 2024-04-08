#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Helper function to create a new node
TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Recursive function to count nodes with even values
int countEvenNodes(TreeNode* root) {
    if (root == NULL) {
        return 0;  // Base case: if the node is NULL, return 0
    }

    // Check if the current node's value is even
    int isEven = (root->val % 2 == 0) ? 1 : 0;

    // Recursively count even nodes in the left and right subtrees
    int leftCount = countEvenNodes(root->left);
    int rightCount = countEvenNodes(root->right);

    // Return the sum of even nodes in the left and right subtrees plus the current node (if even)
    return isEven + leftCount + rightCount;
}

// Example usage
int main() {
    TreeNode* root = newNode(2);
    root->left = newNode(3);
    root->right = newNode(4);
    root->left->left = newNode(5);
    root->left->right = newNode(6);
    root->right->left = newNode(7);
    root->right->right = newNode(8);

    int evenCount = countEvenNodes(root);
    printf("Number of nodes with even values: %d\n", evenCount);

    // Remember to free the allocated memory for the nodes after usage
    return 0;
}

