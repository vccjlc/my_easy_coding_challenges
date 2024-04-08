/*

write the function to find the width of the lowest level (count all deepest leaves)

To find the width of the lowest level in a binary tree, you can perform a level-order traversal (Breadth-First Search, BFS) and count the number of nodes at the last level. The level-order traversal ensures that you visit all nodes level by level, starting from the root. When you reach the last level, you simply count the number of nodes on that level, which gives you the width of the lowest level.



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

int widthOfLowestLevel(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    Queue q = {NULL, NULL};
    enqueue(&q, root);
    int width = 0;

    while (!isQueueEmpty(&q)) {
        int levelSize = 0;
        Queue tempQueue = q; // Copy the current queue to count the nodes at this level

        // Count nodes at the current level
        while (!isQueueEmpty(&tempQueue)) {
            dequeue(&tempQueue);
            levelSize++;
        }

        width = levelSize; // Update width to the current level's size

        // Enqueue children of all nodes at the current level
        for (int i = 0; i < levelSize; i++) {
            TreeNode *node = dequeue(&q);
            if (node->left != NULL) {
                enqueue(&q, node->left);
            }
            if (node->right != NULL) {
                enqueue(&q, node->right);
            }
        }
    }

    return width;
}

