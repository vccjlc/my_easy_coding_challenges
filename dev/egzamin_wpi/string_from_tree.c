/*

Given the root node of a binary tree, your task is to create a string representation of the tree following a specific set of formatting rules. The representation should be based on a preorder traversal of the binary tree and must adhere to the following guidelines:

Node Representation: Each node in the tree should be represented by its integer value.

Parentheses for Children: If a node has at least one child (either left or right), its children should be represented inside parentheses. Specifically:

If a node has a left child, the value of the left child should be enclosed in parentheses immediately following the node's value.
If a node has a right child, the value of the right child should also be enclosed in parentheses. The parentheses for the right child should follow those of the left child.
Omitting Empty Parentheses: Any empty parentheses pairs (i.e., ()) should be omitted from the final string representation of the tree, with one specific exception: when a node has a right child but no left child. In such cases, you must include an empty pair of parentheses to indicate the absence of the left child. This ensures that the one-to-one mapping between the string representation and the original binary tree structure is maintained.

In summary, empty parentheses pairs should be omitted when a node has only a left child or no children. However, when a node has a right child but no left child, an empty pair of parentheses must precede the representation of the right child to reflect the tree's structure accurately.


***


To create the string representation based on the rules provided, we need to perform a pre-order traversal (process the node, then visit the left and right subtrees) of the binary tree and use a string (or character array in C) to build the representation.

*/


#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Helper function to create a new TreeNode
TreeNode* createTreeNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to calculate the size needed for the string representation
int getStringSize(TreeNode* node) {
    if (!node) return 0;
    int size = snprintf(NULL, 0, "%d", node->val); // +1 for the node value
    size += getStringSize(node->left);  // Size for the left subtree
    size += getStringSize(node->right); // Size for the right subtree
    if (node->left || node->right) size += 2; // +2 for parentheses
    if (node->right && !node->left) size += 2; // +2 for empty parentheses for the left
    return size;
}

// Recursive helper function to build the string representation
void buildString(TreeNode* node, char** str, int* index) {
    if (!node) return;

    int len = snprintf(*str + *index, getStringSize(node) + 1, "%d", node->val);
    *index += len;

    if (node->left || node->right) {
        *(*str + (*index)++) = '(';
        buildString(node->left, str, index);
        *(*str + (*index)++) = ')';

        if (node->right) {
            *(*str + (*index)++) = '(';
            buildString(node->right, str, index);
            *(*str + (*index)++) = ')';
        }
    }
}

// Main function to create the string representation of the binary tree
char* tree2str(TreeNode* root) {
    int size = getStringSize(root) + 1; // +1 for the null-terminator
    char* str = (char*)malloc(size);
    int index = 0;
    buildString(root, &str, &index);
    str[index] = '\0'; // Null-terminate the string
    return str;
}

int main() {
    // Example usage:
    TreeNode* root = createTreeNode(1);
    root->left = createTreeNode(2);
    root->right = createTreeNode(3);
    root->left->right = createTreeNode(4);

    char* result = tree2str(root);
    printf("String representation of the binary tree: %s\n", result);

    free(result); // Free the allocated string memory

    // Free memory for the binary tree nodes

    return 0;
}


