/*

Two binary trees are connected at one node (and the subtree starting at this node is the same for both). Write a function that will return the root of a greater tree.

To find the root of the greater tree when two binary trees are connected at one node, with the subtree starting from this node being the same for both trees, you can use a recursive function to traverse both trees simultaneously. The function will compare the values at each node and return the root of the tree that has the greater value at the first differing node. If the trees are identical up to the point of connection, the function will return the root of the tree that contains the connected subtree.



*/


#include <stdio.h>
#include <stdlib.h>

// Define the structure for tree nodes
struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to find the root of the greater tree
struct TreeNode* findRootOfGreaterTree(struct TreeNode* root1, struct TreeNode* root2) {
    // If either tree is empty, return the non-empty tree's root
    if (root1 == NULL) return root2;
    if (root2 == NULL) return root1;

    // If roots are connected (i.e., have the same address), return any as they are identical from this point
    if (root1 == root2) return root1;

    // If values differ, return the root of the tree with the greater value
    if (root1->value != root2->value) {
        return root1->value > root2->value ? root1 : root2;
    }

    // Recursively find the greater tree in the left and right subtrees
    struct TreeNode* leftGreater = findRootOfGreaterTree(root1->left, root2->left);
    struct TreeNode* rightGreater = findRootOfGreaterTree(root1->right, root2->right);

    // If the left or right subtrees are different, return the root of the tree with the greater subtree
    if (leftGreater != root1->left || rightGreater != root1->right) {
        return leftGreater != root1->left ? leftGreater : rightGreater;
    }

    // If no difference is found, the trees are equal up to the connection point; return any root
    return root1;
}

// Utility function to create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Add functions to build and test your trees here

int main() {
    // Example usage:
    // struct TreeNode* root1 = ...; // Construct the first tree
    // struct TreeNode* root2 = ...; // Construct the second tree, connected to the first at some node

    // struct TreeNode* greaterRoot = findRootOfGreaterTree(root1, root2);
    // printf("The root of the greater tree has the value: %d\n", greaterRoot->value);

    return 0;
}

