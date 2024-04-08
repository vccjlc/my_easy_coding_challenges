// LEVEL ORDER TO 2D ARRAY RIGHT TO LEFT

// arrray[1][0] means second row, first column
/*
Rows represent tree levels: The first row (row 0) represents the root level of the tree, the second row (row 1) represents the level containing the children of the root, and so on. Each subsequent row represents the next level down in the tree.
Columns represent node positions within a level: Within each row, columns represent the positions of nodes at that level of the tree, from left to right or right to left, depending on the traversal order you choose.

*/

#include <limits.h> // For INT_MIN
#include <stdlib.h> // For malloc, free
#include <stdio.h> // For printf (optional, for demo purposes)

int treeHeight(struct TreeNode* root) {
    if (!root) return 0;
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void insertLevelOrderRightToLeft(struct TreeNode* root, int** arr, int level, int* index, int maxNodesPerLevel) {
    if (!root) return;

    Queue* q = createQueue();
    enqueue(q, root);

    while (!isQueueEmpty(q)) {
        int levelSize = q->front->rear - q->front + 1; // Number of nodes at the current level
        int startIndex = maxNodesPerLevel - levelSize; // Start from the right for right-to-left insertion

        for (int i = 0; i < levelSize; ++i) {
            struct TreeNode* current = dequeue(q);
            arr[level][startIndex + i] = current->val; // Insert right-to-left

            if (current->right != NULL) enqueue(q, current->right); // Enqueue right child first
            if (current->left != NULL) enqueue(q, current->left); // Then left child

            // Fill unused positions with INT_MIN
            for (int j = startIndex + levelSize; j < maxNodesPerLevel; ++j) {
                arr[level][j] = INT_MIN;
            }
        }
        level++;
    }

    // Free the queue
    while (!isQueueEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

// Example usage
int main() {
    struct TreeNode* root; // Assume root is initialized and points to your tree
    int height = treeHeight(root);
    int maxNodesPerLevel = 1 << (height - 1);
    int** arr = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; ++i) {
        arr[i] = (int*)malloc(maxNodesPerLevel * sizeof(int));
        for (int j = 0; j < maxNodesPerLevel; ++j) {
            arr[i][j] = INT_MIN; // Initialize all elements to INT_MIN
        }
    }

    int index = 0;
    insertLevelOrderRightToLeft(root, arr, 0, &index, maxNodesPerLevel);

    // Now arr contains the tree node values in level order, right-to-left
    // Remember to free arr when done
    for (int i = 0; i < height; ++i) {
        free(arr[i]);
    }
    free(arr);
}

