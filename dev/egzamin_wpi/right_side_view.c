/*

Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
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

// Function to see the binary tree from the right side
int* rightSideView(TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    Queue* q = createQueue();
    enqueue(q, root);
    int* rightView = malloc(0);
    *returnSize = 0;

    while (!isEmpty(q)) {
        int levelSize = q->size;  // Number of nodes at the current level
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = dequeue(q);
            if (i == levelSize - 1) {  // Last node in the level
                (*returnSize)++;
                rightView = realloc(rightView, (*returnSize) * sizeof(int));
                rightView[*returnSize - 1] = node->val;
            }
            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }
    }

    free(q);
    return rightView;
}

