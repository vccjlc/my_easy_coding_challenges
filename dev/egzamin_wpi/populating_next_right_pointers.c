/*


You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
} Node;

// Function to create a new Node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->next = NULL;
    return newNode;
}

// Helper function to connect nodes at the same level
void connectHelper(Node* left, Node* right) {
    if (left == NULL || right == NULL) return;

    left->next = right;

    connectHelper(left->left, left->right);
    connectHelper(left->right, right->left);
    connectHelper(right->left, right->right);
}

// Main function to populate each next pointer to point to its next right node
void connect(Node* root) {
    if (root == NULL) return;

    connectHelper(root->left, root->right);
}

