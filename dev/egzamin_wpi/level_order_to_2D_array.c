// LEVEL ORDER TO 2D ARRAY LEFT TO RIGHT

// arrray[1][0] means second row, first column
/*
Rows represent tree levels: The first row (row 0) represents the root level of the tree, the second row (row 1) represents the level containing the children of the root, and so on. Each subsequent row represents the next level down in the tree.
Columns represent node positions within a level: Within each row, columns represent the positions of nodes at that level of the tree, from left to right or right to left, depending on the traversal order you choose.

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MIN

// Assuming the TreeNode structure is defined as follows:
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Assuming Queue and QueueNode structures and related functions (createQueue, enqueue, dequeue, isQueueEmpty) are defined elsewhere

// Function to calculate the height of the binary tree
int treeHeight(struct TreeNode* root) {
    if (!root) return 0;
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to insert node values into a 2D array in level order from left to right
void insertLevelOrderLeftToRight(struct TreeNode* root, int** arr, int height) {
    if (!root) return;

    Queue* q = createQueue();
    enqueue(q, root);
    int level = 0;

    while (!isQueueEmpty(q)) {
        int levelSize = q->front->rear - q->front + 1; // Number of nodes at the current level
        for (int i = 0; i < levelSize; ++i) {
            struct TreeNode* current = dequeue(q);
            arr[level][i] = current->val; // Insert left-to-right

            if (current->left != NULL) enqueue(q, current->left); // Enqueue left child first
            if (current->right != NULL) enqueue(q, current->right); // Then right child
        }
        // Fill the rest of the row with INT_MIN
        for (int j = levelSize; j < (1 << level); ++j) {
            arr[level][j] = INT_MIN;
        }
        level++;
    }

    // Free the queue
    while (!isQueueEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

// Main function to demonstrate the usage
int main() {
    // Assuming the binary tree is constructed here and 'root' points to its root node

    int height = treeHeight(root);
    int** arr = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; ++i) {
        arr[i] = (int*)malloc((1 << i) * sizeof(int)); // Allocate space for the maximum number of nodes at this level
        for (int j = 0; j < (1 << i); ++j) {
            arr[i][j] = INT_MIN; // Initialize all elements to INT_MIN
        }
    }

    insertLevelOrderLeftToRight(root, arr, height);

    // The array 'arr' now contains the tree node values in level order, left-to-right
    // Use 'arr' as needed here

    // Free the allocated memory
    for (int i = 0; i < height; ++i) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}

