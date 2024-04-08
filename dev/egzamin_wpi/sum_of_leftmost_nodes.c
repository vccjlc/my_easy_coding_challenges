/*

write a function to calculate the sum of leftmost nodes


To calculate the sum of the leftmost nodes in a binary tree, you can perform a level-order traversal (Breadth-First Search, BFS) similar to the approach for rightmost nodes. However, for each level, you only add the value of the first (leftmost) node you encounter to the sum. This approach ensures that only the leftmost node at each level contributes to the sum.


*/


#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode *left, *right;
} TreeNode;

typedef struct QueueNode {
    TreeNode *treeNode;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front, *rear;
} Queue;

void enqueue(Queue *q, TreeNode *node) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->treeNode = node;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

TreeNode* dequeue(Queue *q) {
    if (q->front == NULL) {
        return NULL;
    }
    QueueNode *temp = q->front;
    TreeNode *node = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return node;
}

int isQueueEmpty(Queue *q) {
    return q->front == NULL;
}

int sumOfLeftmostNodes(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    Queue q = {NULL, NULL};
    enqueue(&q, root);
    int sum = 0;

    while (!isQueueEmpty(&q)) {
        int levelSize = 0;
        Queue tempQueue = q; // Copy the current queue to count the nodes at this level

        // Count nodes at the current level
        while (!isQueueEmpty(&tempQueue)) {
            dequeue(&tempQueue);
            levelSize++;
        }

        // Process all nodes at the current level and add the leftmost node's value to the sum
        for (int i = 0; i < levelSize; i++) {
            TreeNode *node = dequeue(&q);
            if (i == 0) { // Check if it is the leftmost node at the current level
                sum += node->value;
            }
            if (node->left != NULL) {
                enqueue(&q, node->left);
            }
            if (node->right != NULL) {
                enqueue(&q, node->right);
            }
        }
    }

    return sum;
}

