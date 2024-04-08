#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Utility function to create a new node
struct TreeNode* newNode(int value) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Helper function to compute the height of a subtree rooted at 'node'
// and update the count of subtrees of each height
int countSubtreesUtil(struct TreeNode* node, int* counts, int n) {
    if (node == NULL) {
        // A NULL node contributes to the count of subtrees of height -1,
        // which we don't count, so return -1
        return -1;
    }

    // Recursively find the height of the left and right subtrees
    int leftHeight = countSubtreesUtil(node->left, counts, n);
    int rightHeight = countSubtreesUtil(node->right, counts, n);

    // The height of the current node is 1 plus the maximum of the heights of its children
    int nodeHeight = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);

    // Increment the count for the subtree of this height
    if (nodeHeight < n) {
        counts[nodeHeight]++;
    }

    // Return the height of this node
    return nodeHeight;
}

// Function to count the number of subtrees of each height
void countSubtrees(struct TreeNode* root, int n) {
    int* counts = (int*)calloc(n, sizeof(int));
    if (!counts) {
        printf("Memory allocation failed.\n");
        return;
    }

    countSubtreesUtil(root, counts, n);

    // Print the counts
    for (int i = 0; i < n; i++) {
        printf("Height %d: %d subtrees\n", i, counts[i]);
    }

    free(counts);
}

// Example usage
int main() {
    // Construct a sample tree
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    // Assuming the maximum height of the tree won't exceed 10 for this example
    countSubtrees(root, 10);

    return 0;
}

