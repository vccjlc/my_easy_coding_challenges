/*

Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

*/


#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// A utility function to create a new Binary Tree node
struct TreeNode* newNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to find the level with the maximum sum
int maxLevelSum(struct TreeNode* root) {
    if (root == NULL) return 0;

    int maxLevel = 1, currentLevel = 1;
    int maxSum = root->val;  // Initialize maxSum to root's value

    // Queue for level order traversal
    struct TreeNode* queue[10000];  // Assuming a maximum of 10000 nodes
    int front = 0, rear = 0;  // Queue front and rear

    // Enqueue root
    queue[rear++] = root;

    while (front < rear) {  // While queue is not empty
        int levelSum = 0;  // Sum of current level
        int levelCount = rear - front;  // Number of nodes at the current level

        // Process all nodes of the current level
        for (int i = 0; i < levelCount; i++) {
            struct TreeNode* node = queue[front++];
            levelSum += node->val;

            // Enqueue left child
            if (node->left != NULL) queue[rear++] = node->left;
            // Enqueue right child
            if (node->right != NULL) queue[rear++] = node->right;
        }

        // Update max sum and level if needed
        if (levelSum > maxSum) {
            maxSum = levelSum;
            maxLevel = currentLevel;
        }

        currentLevel++;  // Move to the next level
    }

    return maxLevel;
}

int main() {
    // Example usage
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(8);
    root->right->right->left = newNode(6);
    root->right->right->right = newNode(7);

    // Function call
    printf("The level with the maximum sum is: %d\n", maxLevelSum(root));

    // Clean up the allocated memory if necessary
    // Free the tree nodes...

    return 0;
}

