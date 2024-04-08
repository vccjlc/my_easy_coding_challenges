#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

// Function to find the leftmost node starting from a given node
Node* findLeftMostNode(Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Function to find the first parent node for which the given node is in the left subtree
Node* findFirstParent(Node* node) {
    while (node->parent != NULL && node->parent->right == node) {
        node = node->parent;
    }
    return node->parent;
}

// Main function to find the in-order successor of a given node
Node* inOrderSuccessor(Node* node) {
    if (node == NULL) return NULL;

    if (node->right) {
        return findLeftMostNode(node->right);
    } else {
        return findFirstParent(node);
    }
}

// Helper function to create a new Node
Node* createNode(int val, Node* left, Node* right, Node* parent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->left = left;
    newNode->right = right;
    newNode->parent = parent;
    return newNode;
}

int main() {
    // Example usage:
    // Creating a simple BST where the in-order successor of node 2 is node 3
    Node* root = createNode(3, NULL, NULL, NULL); // Root node
    root->left = createNode(2, NULL, NULL, root);
    root->left->left = createNode(1, NULL, NULL, root->left);
    root->right = createNode(4, NULL, NULL, root);

    Node* successor = inOrderSuccessor(root->left);
    if (successor) {
        printf("The in-order successor of node %d is node %d.\n", root->left->val, successor->val);
    } else {
        printf("The in-order successor does not exist.\n");
    }

    // Remember to free the allocated memory for the BST after use
    // ...

    return 0;
}

