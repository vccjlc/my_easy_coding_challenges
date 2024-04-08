// write a function to check if a given value exists in a tree

/*


To check if a given value exists in a binary tree, you can use a simple depth-first search (DFS) or breadth-first search (BFS) approach. The DFS approach is typically implemented using recursion, while BFS is usually implemented using a queue. Here, I'll show you how to implement the DFS approach using recursion.

This function will traverse the tree, checking at each node if the value matches the given value. If the value is found, the function returns 1 (true); otherwise, it returns 0 (false) after fully traversing the tree without finding the value.

*/

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to check if a given value exists in the tree.
// 'root' is the root of the tree, and 'value' is the value to search for.
int existsInTree(struct TreeNode* root, int value) {
    if (root == NULL) {
        return 0; // Base case: if the tree is empty or we reach a leaf's child, the value does not exist.
    }
    if (root->val == value) {
        return 1; // The value is found.
    }

    // Recursively search the left and right subtrees.
    return existsInTree(root->left, value) || existsInTree(root->right, value);
}

// Utility function to create a new TreeNode
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Example usage
int main() {
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int value = 3; // The value to search for
    if (existsInTree(root, value)) {
        printf("Value %d exists in the tree.\n", value);
    } else {
        printf("Value %d does not exist in the tree.\n", value);
    }

    // Free allocated memory for the tree nodes (omitted for brevity)

    return 0;
}

