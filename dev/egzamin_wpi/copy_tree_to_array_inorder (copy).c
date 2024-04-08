#include <stdio.h>
#include <stdlib.h>

// Define the structure for tree nodes
typedef struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function prototypes
int countNodes(TreeNode *root);
void copyInorder(TreeNode *root, int arr[], int *index);

// Function to copy a tree into an array using inorder traversal
void copyTreeToArrayInorder(TreeNode *root) {
    // Count the number of nodes in the tree
    int totalNodes = countNodes(root);

    // Declare the array of the required size
    int treeArray[totalNodes];
    int index = 0; // Index to keep track of the position in the array

    // Copy the tree elements to the array using inorder traversal
    copyInorder(root, treeArray, &index);

    // Print the array elements to verify
    printf("Tree elements in inorder: ");
    for (int i = 0; i < totalNodes; i++) {
        printf("%d ", treeArray[i]);
    }
    printf("\n");
}

// Helper function to count the nodes in the tree
int countNodes(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    // Count the nodes in both subtrees and add 1 for the current node
    return countNodes(root->left) + countNodes(root->right) + 1;
}

// Helper function to perform inorder traversal and copy elements to the array
void copyInorder(TreeNode *root, int arr[], int *index) {
    if (root != NULL) {
        copyInorder(root->left, arr, index); // Traverse left subtree
        arr[(*index)++] = root->value; // Copy the root's value and increment index
        copyInorder(root->right, arr, index); // Traverse right subtree
    }
}

// Example usage
int main() {
    // Example tree construction
    TreeNode n1 = {1, NULL, NULL};
    TreeNode n2 = {2, NULL, NULL};
    TreeNode n3 = {3, &n1, &n2};
    TreeNode n4 = {4, NULL, NULL};
    TreeNode n5 = {5, &n3, &n4};

    copyTreeToArrayInorder(&n5); // Copy the tree starting from root n5 into an array

    return 0;
}

