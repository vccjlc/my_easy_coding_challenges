#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function prototypes
void inOrderTraversal(struct TreeNode* root, int* array, int* index);
struct TreeNode* insert(struct TreeNode* node, int val);
void printArray(int* array, int size);

int main() {
    struct TreeNode* root = NULL;
    int elements[] = {5, 3, 2, 4, 7, 6, 8}; // Example BST elements
    int n = sizeof(elements) / sizeof(elements[0]);
    int* array = (int*)malloc(n * sizeof(int));
    int index = 0;

    // Inserting elements into the BST
    for (int i = 0; i < n; i++) {
        root = insert(root, elements[i]);
    }

    // Convert BST to an increasing array
    inOrderTraversal(root, array, &index);

    // Print the resulting array
    printArray(array, n);

    free(array);
    return 0;
}

// Function to perform in-order traversal of the BST and fill the array
void inOrderTraversal(struct TreeNode* root, int* array, int* index) {
    if (root != NULL) {
        inOrderTraversal(root->left, array, index);
        array[(*index)++] = root->val;
        inOrderTraversal(root->right, array, index);
    }
}

// Function to insert a new node with the given value into the BST
struct TreeNode* insert(struct TreeNode* node, int val) {
    if (node == NULL) {
        struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        temp->val = val;
        temp->left = temp->right = NULL;
        return temp;
    }

    if (val < node->val)
        node->left = insert(node->left, val);
    else if (val > node->val)
        node->right = insert(node->right, val);

    return node;
}

// Function to print elements of an array
void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

