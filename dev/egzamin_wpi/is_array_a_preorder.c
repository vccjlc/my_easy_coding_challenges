/*


Given a 0-indexed integer 2D array nodes, your task is to determine if the given array represents the preorder traversal of some binary tree.

For each index i, nodes[i] = [id, parentId], where id is the id of the node at the index i and parentId is the id of its parent in the tree (if the node has no parent, then parentId -1).

Return true if the given array represents the preorder traversal of some tree, and false otherwise.
Note: the preorder traversal of a tree is a recursive way to traverse a tree in which we first visit the current node, then we do the preorder traversal for the left child, and finally, we do it for the right child.

*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack node
struct StackNode {
    int id;
    struct StackNode* next;
};

// Function to create a new stack node
struct StackNode* newStackNode(int id) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->id = id;
    stackNode->next = NULL;
    return stackNode;
}

// Function to push an id onto the stack
void push(struct StackNode** root, int id) {
    struct StackNode* stackNode = newStackNode(id);
    stackNode->next = *root;
    *root = stackNode;
}

// Function to check if the stack is empty
int isEmpty(struct StackNode* root) {
    return !root;
}

// Function to return the top item of the stack
int peek(struct StackNode* root) {
    if (isEmpty(root))
        return -1;
    return root->id;
}

// Function to pop an item from the stack
void pop(struct StackNode** root) {
    if (isEmpty(*root))
        return;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    free(temp);
}

// Main function to determine if the array represents a valid preorder traversal
int isValidPreorderTraversal(int nodes[][2], int nodeCount) {
    // A binary tree with no nodes is considered to have a valid preorder traversal
    if (nodeCount == 0)
        return 1;

    // Initialize the stack with the root node (id with parent -1)
    struct StackNode* stack = NULL;
    int rootFound = 0;
    for (int i = 0; i < nodeCount; ++i) {
        if (nodes[i][1] == -1) {
            push(&stack, nodes[i][0]);
            rootFound = 1;
            break;
        }
    }

    // If no root found, return false
    if (!rootFound)
        return 0;

    // Traverse the nodes array to simulate the preorder traversal
    for (int i = 1; i < nodeCount; ++i) {
        int foundParent = 0;
        // The current node should be a child of the node at the top of the stack
        while (!isEmpty(stack) && peek(stack) != nodes[i][1]) {
            pop(&stack); // Pop until we find the parent or the stack is empty
        }
        if (!isEmpty(stack) && peek(stack) == nodes[i][1]) {
            foundParent = 1;
            pop(&stack); // Pop the parent node
        }
        // If we didn't find the correct parent, the traversal is invalid
        if (!foundParent) {
            return 0;
        }
        push(&stack, nodes[i][0]); // Push the current node onto the stack
    }

    // If we completed the traversal without issues, it's a valid preorder
    return 1;
}

int main() {
    // Replace with the number of nodes and the actual nodes array
    int nodes[][2] = {{1, -1}, {2, 1}, {4, 2}, {5, 2}, {3, 1}, {6, 3}, {7, 3}};
    int nodeCount = sizeof(nodes) / sizeof(nodes[0]);

    int isValid = isValidPreorderTraversal(nodes, nodeCount);
    printf("The given array represents %sa valid preorder traversal of some tree.\n", isValid ? "" : "not ");

    return 0;
}


