#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// A binary tree node has data, pointer to left child and a pointer to right child
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new binary tree node having a given key
struct Node* newNode(int key) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to check if a binary tree is complete
bool isComplete(struct Node* root) {
    if (root == NULL) return true;

    // Create an empty queue for level order traversal
    struct Node* queue[100]; // Assuming max 100 nodes in the tree
    int front = 0, rear = 0;

    // Enqueue root and initialize flag as false
    queue[rear++] = root;
    bool nonFullNodeSeen = false;

    while (front < rear) {
        struct Node* tempNode = queue[front++];

        // Check left child
        if (tempNode->left) {
            // If we have seen a non full node, and we see a node
            // with non-empty left child, the tree is not complete
            if (nonFullNodeSeen) return false;
            queue[rear++] = tempNode->left; // Enqueue left child
        } else {
            // If this a non-full node, set the flag as true
            nonFullNodeSeen = true;
        }

        // Check right child
        if (tempNode->right) {
            // If we have seen a non full node and we see a node
            // with non-empty right child, the tree is not complete
            if (nonFullNodeSeen) return false;
            queue[rear++] = tempNode->right; // Enqueue right child
        } else {
            // If this a non-full node, set the flag as true
            nonFullNodeSeen = true;
        }
    }

    // If we reach here, the tree is complete
    return true;
}

// Driver program to test above function
int main() {
    // Let's construct the following binary tree
    //       1
    //      / \
    //     2   3
    //    / \  /
    //   4  5 6
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);

    if (isComplete(root))
        printf("The binary tree is complete\n");
    else
        printf("The binary tree is not complete\n");

    return 0;
}

