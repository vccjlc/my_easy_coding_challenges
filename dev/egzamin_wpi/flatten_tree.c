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

// Helper function to flatten the tree to a linked list
void flatten(TreeNode* root) {
    if (root == NULL) return;

    // Flatten the left and right subtrees
    flatten(root->left);
    flatten(root->right);

    // Store the right subtree
    TreeNode* tempRight = root->right;

    // Move the left subtree to the right
    root->right = root->left;
    root->left = NULL;  // Set the left child to NULL

    // Find the rightmost node of the new right subtree
    TreeNode* current = root;
    while (current->right != NULL) {
        current = current->right;
    }

    // Attach the original right subtree
    current->right = tempRight;
}

// Function to print the flattened tree (linked list)
void printFlattened(TreeNode* root) {
    TreeNode* current = root;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->right;  // Move to the next node in the list
    }
}

int main() {
    // Create a simple example tree
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(5);
    root->left->left = createNode(3);
    root->left->right = createNode(4);
    root->right->right = createNode(6);

    // Flatten the tree
    flatten(root);

    // Print the flattened tree
    printf("Flattened tree: \n");
    printFlattened(root);
    printf("\n");

    return 0;
}

