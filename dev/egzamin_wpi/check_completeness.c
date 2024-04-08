/*

check completeness of a binary tree

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

To check the completeness of a binary tree, you can perform a level-order traversal using a queue. During the traversal, once a NULL node is encountered, there should not be any more non-NULL nodes in the queue. If you find a non-NULL node after encountering a NULL, the tree is not complete.


*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// A queue node
typedef struct QueueNode {
    TreeNode* treeNode;
    struct QueueNode* next;
} QueueNode;

// A queue structure
typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
    int size;
} Queue;

// Function to create a queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

// Function to add an element to the queue
void enqueue(Queue* q, TreeNode* treeNode) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->treeNode = treeNode;
    temp->next = NULL;
    
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
    q->size++;
}

// Function to remove an element from the queue
TreeNode* dequeue(Queue* q) {
    if (q->front == NULL) {
        return NULL;
    }
    
    QueueNode* temp = q->front;
    TreeNode* treeNode = temp->treeNode;
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    q->size--;
    return treeNode;
}

// Function to check if the queue is empty
bool isEmpty(Queue* q) {
    return (q->front == NULL);
}

// Function to check the completeness of a binary tree
bool isCompleteTree(TreeNode* root) {
    if (root == NULL) return true;

    Queue* q = createQueue();
    enqueue(q, root);
    bool nullSeen = false;  // Flag to indicate if a NULL has been seen

    while (!isEmpty(q)) {
        TreeNode* currentNode = dequeue(q);

        if (currentNode == NULL) {
            nullSeen = true;  // Set the flag once we see a NULL
        } else {
            if (nullSeen) {
                // If we see a non-NULL node after seeing a NULL, the tree is not complete
                return false;
            }
            enqueue(q, currentNode->left);
            enqueue(q, currentNode->right);
        }
    }

    // If we've gone through the entire tree without seeing a non-NULL after a NULL, the tree is complete
    return true;
}

// Helper function to create a new Binary Tree node
TreeNode* newNode(int val) {
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

