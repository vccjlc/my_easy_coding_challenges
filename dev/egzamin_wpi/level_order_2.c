/*
Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).

*/


#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode *left, *right;
} TreeNode;

typedef struct QueueNode {
    TreeNode* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode *front, *rear;
    int size;
} Queue;

// Queue operations
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(Queue* q, TreeNode* node) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = node;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

TreeNode* dequeue(Queue* q) {
    if (q->front == NULL) return NULL;
    QueueNode* temp = q->front;
    TreeNode* node = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    q->size--;
    return node;
}

int isEmpty(Queue* q) {
    return q->size == 0;
}

// Function to perform bottom-up level order traversal
void bottomUpLevelOrder(TreeNode* root, int*** result, int** columnSizes, int* returnSize) {
    if (root == NULL) return;

    Queue* q = createQueue();
    enqueue(q, root);
    *returnSize = 0;
    *result = malloc(0);
    *columnSizes = malloc(0);

    while (!isEmpty(q)) {
        int levelSize = q->size;
        int* currentLevel = malloc(levelSize * sizeof(int));
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = dequeue(q);
            currentLevel[i] = node->value;
            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }
        // Insert the current level at the beginning of the result list
        (*returnSize)++;
        *result = realloc(*result, (*returnSize) * sizeof(int*));
        memmove(*result + 1, *result, (*returnSize - 1) * sizeof(int*));
        (*result)[0] = currentLevel;

        *columnSizes = realloc(*columnSizes, (*returnSize) * sizeof(int));
        memmove(*columnSizes + 1, *columnSizes, (*returnSize - 1) * sizeof(int));
        (*columnSizes)[0] = levelSize;
    }

    free(q);
}

