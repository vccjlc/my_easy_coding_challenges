#include <stdio.h>
#include <stdlib.h>

// Traverse the tree level by level and print nodes at each level from left to right.

typedef struct TreeNode {
    int value;
    struct TreeNode *left, *right;
} TreeNode;

typedef struct QueueNode {
    TreeNode *tNode;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front, *rear;
} Queue;

Queue* createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue *q, TreeNode *node) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->tNode = node;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

TreeNode* dequeue(Queue *q) {
    if (q->front == NULL) return NULL;
    QueueNode *temp = q->front;
    TreeNode *node = temp->tNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return node;
}

int isQueueEmpty(Queue *q) {
    return (q->front == NULL);
}

void levelOrderTraversal(TreeNode *root) {
    if (root == NULL) return;
    Queue *q = createQueue();
    enqueue(q, root);
    while (!isQueueEmpty(q)) {
        TreeNode *node = dequeue(q);
        printf("%d ", node->value);
        if (node->left != NULL) enqueue(q, node->left);
        if (node->right != NULL) enqueue(q, node->right);
    }
}

