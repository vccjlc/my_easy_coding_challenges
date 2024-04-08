/*

To convert a binary tree into its mirror, you need to traverse the tree and swap the left and right child nodes at every node. This can be done using a simple recursive function. Here's how you can implement this in C:

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode *left, *right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to swap the left and right children of a node
void swap(TreeNode** a, TreeNode** b) {
    TreeNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Recursive function to convert a binary tree into its mirror
void mirror(TreeNode* node) {
    if (node == NULL) {
        return;
    }

    // Swap the left and right children
    swap(&node->left, &node->right);

    // Recursively convert the left and right subtrees
    mirror(node->left);
    mirror(node->right);
}

// Function to print inorder traversal of the tree
void printInorder(TreeNode* node) {
    if (node == NULL) {
        return;
    }

    printInorder(node->left);
    printf("%d ", node->value);
    printInorder(node->right);
}

// Function to create a simple example tree and demonstrate mirror conversion
int main() {
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Inorder traversal of the original tree: \n");
    printInorder(root);
    printf("\n");

    // Convert the tree to its mirror
    mirror(root);

    printf("Inorder traversal of the mirror tree: \n");
    printInorder(root);
    printf("\n");

    return 0;
}

