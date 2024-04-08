/*

Two BSTs share a common node (the same address in memory). Below the common node the subtree is the same for both trees. Write a function in C that will return the common node


To find the common node shared by two Binary Search Trees (BSTs) where the common node and all nodes beneath it in the subtree are the same (i.e., they share the same memory addresses for these nodes), you can use a function that compares the nodes of the two trees in a synchronized manner. Starting from the root of each tree, you move down both trees simultaneously. The first node that has the same address in both trees is the common node.


*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for BST nodes
struct Node {
    int data;
    struct Node* left, *right;
};

// Function to find the common node in two BSTs
struct Node* findCommonNode(struct Node* root1, struct Node* root2) {
    // Base case: If either tree is empty or if the nodes are the same, return the node
    if (root1 == NULL || root2 == NULL || root1 == root2) {
        return root1; // or root2, since root1 == root2 here
    }

    // Compare the addresses of left children
    struct Node* leftCommon = findCommonNode(root1->left, root2->left);
    if (leftCommon != NULL) {
        return leftCommon; // Common node found in the left subtree
    }

    // Compare the addresses of right children
    struct Node* rightCommon = findCommonNode(root1->right, root2->right);
    if (rightCommon != NULL) {
        return rightCommon; // Common node found in the right subtree
    }

    // No common node found
    return NULL;
}

// Utility function to create a new BST node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Add other functions to build and test your trees here

int main() {
    // Example usage:
    // struct Node* root1 = ...; // Construct the first BST
    // struct Node* root2 = ...; // Construct the second BST with a common subtree with root1

    // struct Node* commonNode = findCommonNode(root1, root2);
    // if (commonNode != NULL) {
    //     printf("Common node found: %d\n", commonNode->data);
    // } else {
    //     printf("No common node found.\n");
    // }

    return 0;
}




