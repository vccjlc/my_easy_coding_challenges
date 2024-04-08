/*

Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.


To calculate the average value of the nodes on each level of a binary tree, you can perform a level-order traversal (also known as breadth-first search) of the tree. During the traversal, keep track of the sum of the node values and the count of nodes at each level. After visiting all nodes at a level, calculate the average for that level.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    struct TreeNode** queue = (struct TreeNode**)malloc(10000 * sizeof(struct TreeNode*));
    double* averages = (double*)malloc(1000 * sizeof(double));
    int front = 0, rear = 0, levelSize, i;
    double sum;
    *returnSize = 0;

    queue[rear++] = root; // Enqueue root (QUEUE HAS FRONT ON THE LEFT)

    while (front < rear) { // While queue is not empty
        levelSize = rear - front; // Number of nodes at current level
        sum = 0;
        for (i = 0; i < levelSize; ++i) { // Process each node of the current level
            struct TreeNode* node = queue[front++];
            sum += node->val;
            if (node->left) queue[rear++] = node->left; // Enqueue left child
            if (node->right) queue[rear++] = node->right; // Enqueue right child
        }
        averages[(*returnSize)++] = sum / levelSize; // Calculate and store average
    }

    free(queue); // Free the queue
    return averages; // Return the array of averages
}



// Można też bez post-increment

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    struct TreeNode** queue = (struct TreeNode**)malloc(10000 * sizeof(struct TreeNode*));
    double* averages = (double*)malloc(1000 * sizeof(double));
    int front = 0, rear = 0, levelSize, i;
    double sum;
    *returnSize = 0;

    // Enqueue root (QUEUE HAS FRONT ON THE LEFT)
    queue[rear] = root;
    rear = rear + 1;

    while (front < rear) { // While queue is not empty
        levelSize = rear - front; // Number of nodes at current level
        sum = 0;
        for (i = 0; i < levelSize; ++i) { // Process each node of the current level
            struct TreeNode* node = queue[front];
            front = front + 1; // Move front pointer forward

            sum += node->val;
            if (node->left) {
                queue[rear] = node->left; // Enqueue left child
                rear = rear + 1; // Move rear pointer forward
            }
            if (node->right) {
                queue[rear] = node->right; // Enqueue right child
                rear = rear + 1; // Move rear pointer forward
            }
        }	
        averages[*returnSize] = sum / levelSize; // Calculate and store average
        *returnSize = *returnSize + 1; // Increment returnSize
    }

    free(queue); // Free the queue
    return averages; // Return the array of averages
}


