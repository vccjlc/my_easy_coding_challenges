/*

Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

To solve this problem, we can perform a level-order traversal of the binary tree using a queue. During the traversal, we process nodes level by level and keep track of the largest value in each level.





*/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MIN

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// A utility function to create a new Binary Tree node
TreeNode* newNode(int data) {
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->val = data;
    temp->left = temp->right = NULL;
    return temp;
}

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
int isEmpty(Queue* q) {
    return (q->front == NULL);
}

// Function to return the largest values in each row of the binary tree
int* largestValues(TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    int* largestVals = (int*)malloc(1000 * sizeof(int)); // Assuming the height of the tree will not exceed 1000
    int levelSize = 0, i = 0;
    
    Queue* q = createQueue();
    enqueue(q, root);
    
    while (!isEmpty(q)) {
        levelSize = q->size;
        int maxVal = INT_MIN;
        for (i = 0; i < levelSize; ++i) {
            TreeNode* node = dequeue(q);
            if (node->val > maxVal) {
                maxVal = node->val;
            }
            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }
        largestVals[*returnSize] = maxVal;
        (*returnSize)++;
    }
    
    return largestVals;
}

