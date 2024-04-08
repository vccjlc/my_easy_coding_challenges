/*

Given the root of a binary tree and a node u in the tree, return the nearest node on the same level that is to the right of u, or return null if u is the rightmost node in its level.
Example 1:
Input: root = [1,2,3,null,4,5,6], u = 4
Output: 5
Explanation: The nearest node on the same level to the right of
node 4 is node 5.


To find the nearest right node in a binary tree for a given node u, you can perform a level-order traversal (BFS) and keep track of nodes at each level. When you find node u, the next node in the traversal (if there is one) at the same level is the answer.


*/



#include <stdio.h>
#include <stdlib.h>

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

// Function to find the nearest right node in the binary tree for node u
TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
    if (root == NULL) return NULL;
    
    // Define a Queue data structure for level order traversal.
    typedef struct QueueNode {
        struct TreeNode* node;
        struct QueueNode* next;
    } QueueNode;

    QueueNode *front = NULL, *rear = NULL, *temp, *levelMarker = NULL;
    TreeNode* current;
    int found = 0; // Flag to mark the finding of node u

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

    TreeNode* dequeue() {
        if (!front) return NULL;
        current = front->node;
        temp = front;
        front = front->next;
        free(temp);
        if (!front) rear = NULL;
        return current;
    }

    // Enqueue the root node and a marker for the level
    enqueue(root);
    enqueue(levelMarker);

    while (front) {
        current = dequeue();

        // Check if we have reached the level marker
        if (current == levelMarker) {
            // If node u was found in this level, the next node is null
            if (found) return NULL;
            if (front) enqueue(levelMarker); // Enqueue marker for the next level
        } else {
            // Check if the current node is node u
            if (found) return current; // The next node is the nearest right node
            if (current == u) found = 1;

            // Enqueue the children of the current node
            if (current->left) enqueue(current->left);
            if (current->right) enqueue(current->right);
        }
    }

    return NULL; // If node u is not found or it is the rightmost node
}

// Example usage
int main() {
    // Assume root and u are already given and constructed
    TreeNode* root

