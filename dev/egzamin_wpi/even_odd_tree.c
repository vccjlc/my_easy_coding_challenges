/*


A binary tree is named Even-Odd if it meets the following conditions:

The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.


***


To determine if a binary tree is Even-Odd according to the given conditions, we need to perform a level-order traversal of the tree, checking the values of nodes at each level to ensure they meet the criteria:

On even-indexed levels, values should be odd and strictly increasing.
On odd-indexed levels, values should be even and strictly decreasing.
We can use a queue to perform the level-order traversal and track the level index by keeping count of the number of nodes at the current level and preparing the count for the next level.

*/



#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MAX and INT_MIN

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Helper function to create a new tree node
TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Function to check if the tree is Even-Odd
int isEvenOddTree(struct TreeNode* root) {
    if (!root) return 1; // An empty tree is considered Even-Odd.

    // Define a Queue data structure for level order traversal.
    typedef struct QueueNode {
        struct TreeNode* node;
        struct QueueNode* next;
    } QueueNode;

    QueueNode* front = NULL;
    QueueNode* rear = NULL;
    QueueNode* temp;
    struct TreeNode* current;
    int level = 0;
    int levelCount, nextLevelCount;
    int prevVal; // Previous value to compare with the current node's value

    // Helper functions for Queue operations
    void enqueue(struct TreeNode* node) {
        QueueNode* newRear = (QueueNode*)malloc(sizeof(QueueNode));
        newRear->node = node;
        newRear->next = NULL;
        if (!front) {
            front = rear = newRear;
        } else {
            rear->next = newRear;
            rear = newRear;
        }
    }

    struct TreeNode* dequeue() {
        if (!front) return NULL;
        current = front->node;
        temp = front;
        front = front->next;
        free(temp);
        if (!front) rear = NULL;
        return current;
    }

    // Start with the root node in the queue
    enqueue(root);
    levelCount = 1; // One node at the root level

    while (front) {
        nextLevelCount = 0;
        prevVal = (level % 2 == 0) ? INT_MIN : INT_MAX; // Set initial previous value based on level

        // Process all nodes at the current level
        while (levelCount > 0) {
            current = dequeue();
            levelCount--;

            // Check node value against the Even-Odd rule and compare with the previous value
            if ((level % 2 == current->val % 2) || 
               (level % 2 == 0 && current->val <= prevVal) ||
               (level % 2 == 1 && current->val >= prevVal)) {
                return 0; // The tree is not Even-Odd
            }
            prevVal = current->val;

            // Enqueue children for the next level
            if (current->left) {
                enqueue(current->left);
                nextLevelCount++;
            }
            if (current->right) {
                enqueue(current->right);

