/*
write a simple function to calculate shortest path between two nodes given by values in a binary tree. Values may repeat


*/


#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode *left, *right;
} TreeNode;

// Helper function to add a path to the list of paths
void addPath(int** paths, int* pathSizes, int* numPaths, int* currentPath, int currentPathSize) {
    paths[*numPaths] = (int*)malloc((currentPathSize + 1) * sizeof(int));
    for (int i = 0; i < currentPathSize; i++) {
        paths[*numPaths][i] = currentPath[i];
    }
    pathSizes[*numPaths] = currentPathSize;
    (*numPaths)++;
}

// DFS to find all paths to nodes with the given value
void findAllPaths(TreeNode* root, int value, int** paths, int* pathSizes, int* numPaths, int* currentPath, int currentPathSize) {
    if (root == NULL) {
        return;
    }

    // Add the current node to the path
    currentPath[currentPathSize++] = root->value;

    // If the current node matches the value, add the path to the list
    if (root->value == value) {
        addPath(paths, pathSizes, numPaths, currentPath, currentPathSize);
    }

    // Continue searching in the left and right subtrees
    findAllPaths(root->left, value, paths, pathSizes, numPaths, currentPath, currentPathSize);
    findAllPaths(root->right, value, paths, pathSizes, numPaths, currentPath, currentPathSize);

    // Backtrack: remove the current node from the path
    currentPathSize--;
}

// Function to calculate the length of the shortest path between two nodes given by values
int shortestPath(TreeNode* root, int value1, int value2) {
    int* paths1[100]; // Assuming a maximum of 100 paths
    int pathSizes1[100];
    int numPaths1 = 0;
    int* paths2[100]; // Assuming a maximum of 100 paths
    int pathSizes2[100];
    int numPaths2 = 0;
    int currentPath[100]; // Assuming a maximum depth of 100
    int currentPathSize = 0;

    // Find all paths to the nodes with value1
    findAllPaths(root, value1, paths1, pathSizes1, &numPaths1, currentPath, currentPathSize);

    // Find all paths to the nodes with value2
    findAllPaths(root, value2, paths2, pathSizes2, &numPaths2, currentPath, currentPathSize);

    int minPathLength = INT_MAX;

    // Compute the shortest path for all pairs of paths
    for (int i = 0; i < numPaths1; i++) {
        for (int j = 0; j < numPaths2; j++) {
            int path1Size = pathSizes1[i];
            int path2Size = pathSizes2[j];
            int commonPathSize = 0;

            // Find the length of the common path
            while (commonPathSize < path1Size && commonPathSize < path2Size && paths1[i][commonPathSize] == paths2[j][commonPathSize]) {
                commonPathSize++;
            }

            // Calculate the total path length
            int totalPathLength = path1Size + path2Size - 2 * commonPathSize;

            // Update the minimum path length
            if (totalPathLength < minPathLength) {
                minPathLength = totalPathLength;
            }
        }
    }

    // Free the allocated memory for paths
    for (int i = 0; i < numPaths1; i++) {
        free(paths1[i]);
    }
    for (int j = 0; j < numPaths2; j++) {
        free(paths2[j]);
    }

    return minPathLength;
}

// Example usage and tree construction omitted for brevity

