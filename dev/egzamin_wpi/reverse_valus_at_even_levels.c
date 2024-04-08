/*

Given the root of a perfect binary tree, reverse the node values at each odd level of the tree.


To reverse the node values at each even level of a perfect binary tree, you can follow a similar approach to the one used for reversing odd levels, but with a slight adjustment to target even levels instead. Since the root is considered level 1 (odd), you'll want to reverse the levels that are even numbers.

The approach involves performing a level-order traversal of the tree and reversing the node values at each even level. You can use a queue to facilitate the level-order traversal. For each level, you'll collect the nodes in a list, and if the level is even, you'll reverse the values within that list.

*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for tree nodes
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

// Define the structure for queue nodes
struct QueueNode {
    struct TreeNode* treeNode;
    struct QueueNode* next;
};

// Define the structure for the queue
struct Queue {
    struct QueueNode *front, *rear;
};

// Utility function to create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Utility function to create a new queue node
struct QueueNode* newQueueNode(struct TreeNode* treeNode) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->treeNode = treeNode;
    temp->next = NULL;
    return temp;
}

// Utility function to create an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to add a treeNode to the queue
void enqueue(struct Queue* q, struct TreeNode* treeNode) {
    struct QueueNode* temp = newQueueNode(treeNode);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Function to remove a treeNode from the queue
struct TreeNode* dequeue(struct Queue* q) {
    if (q->front == NULL) return NULL;
    struct QueueNode* temp = q->front;
    struct TreeNode* treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return treeNode;
}

// Check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Main function to reverse node values at each even level of the tree
struct TreeNode* reverseEvenLevels(struct TreeNode* root) {
    if (root == NULL) return NULL;
    struct Queue* q = createQueue();
    enqueue(q, root);

    int level = 0; // Start from level 0 for the root

    while (!isEmpty(q)) {
        int levelSize = 0;
        for (struct QueueNode* temp = q->front; temp != NULL; temp = temp->next) {
            levelSize++;
        }

        int values[levelSize];
        struct TreeNode* nodes[levelSize];
        int i = 0;

        while (levelSize > 0) {
            struct TreeNode* currentNode = dequeue(q);
            nodes[i] = currentNode;
            values[i++] = currentNode->val;

            if (currentNode->left != NULL) enqueue(q, currentNode->left);
            if (currentNode->right != NULL) enqueue(q, currentNode->right);

            levelSize--;
        }

        if (level % 2 == 0) { // Reverse values for even levels
            for (int j = 0; j < i / 2; j++) {
                int temp = values[j];
                values[j] = values[i - j - 1];
                values[i - j - 1] = temp;
            }
        }

        for (int j = 0; j < i; j++) {
            nodes[j]->val = values[j];
        }

        level++; // Increment level after processing all nodes at the current level
    }

    free(q);
    return root;
}

int main() {
    // Example usage
    // struct TreeNode* root = createNode(1);
    // root->left = createNode(2);
    // root->right = createNode(3);
    // root->left->left = createNode(4);
    // root->left->right = createNode(5);
    // root->right->left = createNode(6);
    // root->right->right = createNode(7);

    // struct TreeNode* result = reverseEvenLevels(root);

    // Proceed to use the result tree as needed

    return 0;
}

