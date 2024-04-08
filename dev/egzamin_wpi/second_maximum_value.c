// Return second maximum value

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to create a new tree node.
struct TreeNode* createNode(int value) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = value;
    node->left = node->right = NULL;
    return node;
}

// Helper function to perform reverse in-order traversal.
void reverseInorderTraversal(struct TreeNode* root, int* count, struct TreeNode** secondMaxNode) {
    if (root == NULL || *count >= 2) return;

    // Visit right subtree first (higher values)
    reverseInorderTraversal(root->right, count, secondMaxNode);

    // Increment count and check if it's the second node.
    (*count)++;
    if (*count == 2) {
        *secondMaxNode = root;
        return;  // Found the second maximum, no need to traverse further
    }

    // Visit left subtree last (lower values)
    reverseInorderTraversal(root->left, count, secondMaxNode);
}

// Function to find the second maximum value in the BST.
struct TreeNode* findSecondMaximum(struct TreeNode* root) {
    int count = 0;
    struct TreeNode* secondMaxNode = NULL;
    reverseInorderTraversal(root, &count, &secondMaxNode);

    if (secondMaxNode == NULL) {
        printf("The tree does not have a second maximum value.\n");
        return NULL;
    }

    printf("The second maximum value is: %d\n", secondMaxNode->val);
    return secondMaxNode;
}

int main() {
    // Example usage:
    struct TreeNode* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(7);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->right->left = createNode(6);
    root->right->right = createNode(8);

    struct TreeNode* secondMaxNode = findSecondMaximum(root);
    if (secondMaxNode != NULL) {
        printf("Node with the second maximum value: %d\n", secondMaxNode->val);
    }

    // Don't forget to free the memory for the nodes in a real program!
    return 0;
}

