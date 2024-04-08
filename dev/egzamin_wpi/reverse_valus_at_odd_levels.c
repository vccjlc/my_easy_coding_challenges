/*

Given the root of a perfect binary tree, reverse the node values at each odd level of the tree.

For example, suppose the node values at level 3 are [2,1,3,4,7,11,29,18], then it should become [18,29,11,7,4,3,1,2].
Return the root of the reversed tree.

A binary tree is perfect if all parent nodes have two children and all leaves are on the same level.

The level of a node is the number of edges along the path between it and the root node.


To reverse the node values at each odd level of a perfect binary tree, you can perform a level-order traversal (also known as breadth-first search, BFS) of the tree. During the traversal, for each level, collect the nodes (or values) in a list. If the level is odd, reverse the list. Then, assign the values from the (potentially reversed) list back to the nodes at the current level.

Here's a step-by-step approach:

Use a queue to perform a level-order traversal of the tree. The queue will store pairs consisting of a node and its level number (starting from 0 for the root).
For each level, extract all nodes at that level from the queue and collect their values in a list.
If the level number is odd, reverse the list.
Iterate over the nodes at the current level again (you may need to store them in a temporary list during step 2) and assign the values from the (potentially reversed) list back to the nodes.
Continue this process until you have processed all levels of the tree.

*/



#include <stdio.h>
#include <stdlib.h>

// Tree node structure
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

// Queue node structure
struct QueueNode {
    struct TreeNode* treeNode;
    int level;
    struct QueueNode* next;
};

// Queue structure
struct Queue {
    struct QueueNode *front, *rear;
};

// Function to create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a new queue node
struct QueueNode* newQueueNode(struct TreeNode* treeNode, int level) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->treeNode = treeNode;
    temp->level = level;
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
void enqueue(struct Queue* q, struct TreeNode* treeNode, int level) {
    struct QueueNode* temp = newQueueNode(treeNode, level);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Function to remove a treeNode from the queue
struct QueueNode* dequeue(struct Queue* q) {
    if (q->front == NULL) return NULL;
    struct QueueNode* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    return temp;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Function to reverse node values at each odd level of the tree
struct TreeNode* reverseOddLevels(struct TreeNode* root) {
    if (root == NULL) return NULL;
    struct Queue* q = createQueue();
    enqueue(q, root, 0);

    while (!isEmpty(q)) {
        int levelSize = 0;
        struct QueueNode* temp = q->front;
        while (temp != NULL && temp->level == q->front->level) {
            levelSize++;
            temp = temp->next;
        }

        int values[levelSize];
        struct TreeNode* nodes[levelSize];
        int i = 0;

        while (levelSize > 0) {
            struct QueueNode* nodePair = dequeue(q);
            struct TreeNode* node = nodePair->treeNode;
            int level = nodePair->level;
            free(nodePair);

            nodes[i] = node;
            values[i++] = node->val;

            if (node->left != NULL) enqueue(q, node->left, level + 1);
            if (node->right != NULL) enqueue(q, node->right, level + 1);

            levelSize--;
        }

        if (i > 0 && nodes[0]->level % 2 != 0) {
            for (int j = 0; j < i / 2; j++) {
                int temp = values[j];
                values[j] = values[i - j - 1];
                values[i - j - 1] = temp;
            }
        }

        for (int j = 0; j < i; j++) {
            nodes[j]->val = values[j];
        }
    }

    free(q);
    return root;
}

// Example usage
int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    struct TreeNode* result = reverseOddLevels(root);

    // Proceed to use the result tree as needed

    return 0;
}


