/*

Recover a BST: Two nodes of a BST are swapped by mistake. Restore the BST without changing its structure.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode *left, *right;
} TreeNode;

// Utility function to swap values of two nodes
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Recursive function to traverse the BST in-order and find the two nodes that are swapped
void recoverBSTUtil(TreeNode* root, TreeNode** first, TreeNode** middle, TreeNode** last, TreeNode** prev) {
    if (root == NULL) return;

    // Traverse the left subtree
    recoverBSTUtil(root->left, first, middle, last, prev);

    // Check for swapped nodes
    if (*prev && root->value < (*prev)->value) {
        // If this is the first violation, mark these two nodes as 'first' and 'middle'
        if (*first == NULL) {
            *first = *prev;
            *middle = root;
        }
        // If this is the second violation, mark this node as 'last'
        else {
            *last = root;
        }
    }

    // Update 'prev' for the next iteration
    *prev = root;

    // Traverse the right subtree
    recoverBSTUtil(root->right, first, middle, last, prev);
}

// Main function to recover the swapped nodes
void recoverBST(TreeNode* root) {
    TreeNode *first = NULL, *middle = NULL, *last = NULL, *prev = NULL;

    // Find the two swapped nodes using in-order traversal
    recoverBSTUtil(root, &first, &middle, &last, &prev);

    // If the swapped nodes are adjacent in in-order traversal
    if (last == NULL) {
        swap(&(first->value), &(middle->value));
    }
    // If the swapped nodes are not adjacent
    else {
        swap(&(first->value), &(last->value));
    }
}

