/*

Kth largest sum


You are given the root of a binary tree and a positive integer k.

The level sum in the tree is the sum of the values of the nodes that are on the same level.

Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.

Note that two nodes are on the same level if they have the same distance from the root.



To find the kth largest level sum in a binary tree, you can perform a level-order traversal (also known as a breadth-first search) to calculate the sum of nodes at each level. You can store these sums in an array or a vector, sort it in descending order, and then find the kth largest sum. If there are fewer than k levels in the tree, you return -1.


*/



#include <stdio.h>
#include <stdlib.h>

// Define the structure for tree nodes
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

// Utility function to create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue node structure for level-order traversal
struct QueueNode {
    struct TreeNode* treeNode;
    struct QueueNode* next;
};

// Queue structure
struct Queue {
    struct QueueNode *front, *rear;
};

// Function to create a new queue node
struct QueueNode* newQueueNode(struct TreeNode* treeNode) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->treeNode = treeNode;
    temp->next = NULL;
    return temp;
}

// Function to create an empty queue
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

// Function to compare two integers for qsort
int compareInts(const void* a, const void* b) {
    int int_a = *((int*)a);
    int int_b = *((int*)b);

    return int_b - int_a; // For descending order
}

// Function to find the kth largest level sum
int kthLargestLevelSum(struct TreeNode* root, int k) {
    if (root == NULL) return -1;

    struct Queue* q = createQueue();
    enqueue(q, root);
    int levelSums[1000]; // Adjust the size based on maximum expected tree depth
    int levelCount = 0;

    while (!isEmpty(q)) {
        int levelSize = 0;
        int levelSum = 0;
        struct QueueNode* temp = q->front;

        while (temp != NULL) {
            levelSize++;
            temp = temp->next;
        }

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = dequeue(q);
            levelSum += node->val;

            if (node->left != NULL) enqueue(q, node->left);
            if (node->right != NULL) enqueue(q, node->right);
        }

        levelSums[levelCount++] = levelSum;
    }

    // Sort the level sums in descending order
    qsort(levelSums, levelCount, sizeof(int), compareInts);

    // Check if we have enough levels
    if (k > levelCount) return -1;

    // Return the kth largest level sum
    return levelSums[k - 1];
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

    // int k = 2;
    // printf("The %dth largest level sum is: %d\n", k, kthLargestLevelSum(root, k));

    return 0;
}

