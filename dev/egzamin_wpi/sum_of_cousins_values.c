/*

Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Return the root of the modified tree.

Note that the depth of a node is the number of edges in the path from the root node to it.

*/


#include <stdio.h>
#include <stdlib.h>

// Binary tree node structure
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

// Queue node structure for level-order traversal
struct QueueNode {
    struct TreeNode* treeNode;
    struct TreeNode* parent;  // Track parent to identify siblings
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
struct QueueNode* newQueueNode(struct TreeNode* treeNode, struct TreeNode* parent) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->treeNode = treeNode;
    temp->parent = parent;
    temp->next = NULL;
    return temp;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to add an element to the queue
void enqueue(struct Queue* q, struct TreeNode* treeNode, struct TreeNode* parent) {
    struct QueueNode* temp = newQueueNode(treeNode, parent);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Function to remove an element from the queue
struct QueueNode* dequeue(struct Queue* q) {
    if (q->front == NULL) return NULL;
    struct QueueNode* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    return temp;
}

// Check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Main function to modify the tree
struct TreeNode* replaceWithCousinSum(struct TreeNode* root) {
    if (root == NULL) return NULL;

    struct Queue* q = createQueue();
    enqueue(q, root, NULL);  // Root node has no parent

    while (!isEmpty(q)) {
        int levelSum = 0, levelSize = 0;
        struct QueueNode* temp = q->front;

        // Calculate the sum of the current level and count the nodes
        while (temp != NULL) {
            levelSum += temp->treeNode->val;
            levelSize++;
            temp = temp->next;
        }

        // Update each node's value with the sum of its cousins
        for (int i = 0; i < levelSize; i++) {
            struct QueueNode* nodePair = dequeue(q);
            struct TreeNode* node = nodePair->treeNode;
            struct TreeNode* parent = nodePair->parent;
            free(nodePair);  // Free the queue node

            int cousinSum = levelSum - node->val;  // Subtract the node's value from the level sum
            if (parent != NULL) {  // Subtract the sibling's value if it exists
                if (parent->left != NULL && parent->left != node) cousinSum -= parent->left->val;
                if (parent->right != NULL && parent->right != node) cousinSum -= parent->right->val;
            }
            node->val = cousinSum;  // Update the node's value

            // Enqueue the children with the current node as their parent
            if (node->left != NULL) enqueue(q, node->left, node);
            if (node->right != NULL) enqueue(q, node->right, node);
        }
    }

    free(q);  // Free the queue
    return root;
}

int main() {
    // Example usage
    // Build your binary tree here and call replaceWithCousinSum(root)
    return 0;
}

