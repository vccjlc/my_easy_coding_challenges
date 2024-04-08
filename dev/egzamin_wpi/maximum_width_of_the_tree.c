/*

Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.



To solve this problem, you can perform a level-order traversal (BFS) using a queue, while keeping track of the indices of the nodes as if the tree was a complete binary tree. For a node at index i, its left child is at index 2*i + 1 and its right child is at index 2*i + 2. By tracking the indices, you can calculate the width of each level as the difference between the maximum and minimum indices at that level plus one.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Queue entry that includes the tree node and its index
typedef struct QueueEntry {
    TreeNode *node;
    unsigned long long index; // Use unsigned long long to prevent overflow
} QueueEntry;

// A simple queue implementation
typedef struct Queue {
    QueueEntry *entries;
    int front, rear, size, capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->entries = (QueueEntry*)malloc(sizeof(QueueEntry) * capacity);
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->capacity = capacity;
    return q;
}

int isFull(Queue* q) { return (q->size == q->capacity); }
int isEmpty(Queue* q) { return (q->size == 0); }

void enqueue(Queue* q, TreeNode* node, unsigned long long index) {
    if (isFull(q)) return;
    q->rear = (q->rear + 1) % q->capacity;
    q->entries[q->rear].node = node;
    q->entries[q->rear].index = index;
    q->size++;
}

QueueEntry dequeue(Queue* q) {
    QueueEntry item = {NULL, 0};
    if (isEmpty(q)) return item;
    item = q->entries[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return item;
}

// Function to find the maximum width of the binary tree
int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    
    int maxWidth = 0;
    Queue *q = createQueue(1000); // Assume the maximum number of nodes at a level does not exceed 1000
    enqueue(q, root, 0);

    while (!isEmpty(q)) {
        int count = q->size;
        unsigned long long leftIndex = q->entries[q->front].index; // Leftmost index at the current level
        unsigned long long rightIndex = leftIndex; // Rightmost index at the current level
        while (count--) {
            QueueEntry current = dequeue(q);
            TreeNode* node = current.node;
            rightIndex = current.index; // Update the rightmost index
            if (node->left) enqueue(q, node->left, rightIndex * 2 + 1);
            if (node->right) enqueue(q, node->right, rightIndex * 2 + 2);
        }
        int currentWidth = rightIndex - leftIndex + 1;
        if (currentWidth > maxWidth) maxWidth = currentWidth;
    }

    free(q->entries);
    free(q);
    return maxWidth;
}

// Helper function to create a new TreeNode
TreeNode* createTreeNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    // Example usage:
    TreeNode* root = createTreeNode(1);
    root->left = createTreeNode(3);
    root->right = createTreeNode(2);
    root->left->left = createTreeNode(5);
    root->left->right = createTreeNode(3);
    root->right->right = createTreeNode(9);

    int result = widthOfBinaryTree(root);
    printf("Maximum width of the binary tree: %d\n", result);

    // Free memory if needed and perform other cleanups

    return 0;
}

