/*

Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.






To calculate the vertical order traversal of a binary tree, we can use a combination of Depth-First Search (DFS) to record the row, column, and value of each node, and then sort the nodes according to the problem's requirements: primarily by column, then by row, and if there are multiple nodes in the same position, by their values.

Here's a step-by-step approach:

DFS Traversal: Perform a DFS traversal starting from the root (which is at (0, 0)), and at each node, record the node's value along with its (row, col) position.

Storing Nodes: Store the recorded information in a data structure that allows sorting by column, then by row, and then by value if necessary.

Sorting: After the DFS traversal is complete, sort the nodes primarily by column, then by row, and then by value if there are nodes in the same position.

Building the Result: Based on the sorted nodes, build the final result that represents the vertical order traversal.


*/



#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct Node {
    int row, col, val;
} Node;

Node* nodes;  // Array to store nodes information
int size = 0;  // Number of elements added to the array

// Comparator function for qsort
int compare(const void* a, const void* b) {
    Node* node1 = (Node*)a;
    Node* node2 = (Node*)b;
    if (node1->col != node2->col) return node1->col - node2->col;
    if (node1->row != node2->row) return node1->row - node2->row;
    return node1->val - node2->val;
}

// DFS to populate nodes information
void dfs(TreeNode* root, int row, int col) {
    if (!root) return;
    nodes[size++] = (Node){row, col, root->val};
    dfs(root->left, row + 1, col - 1);
    dfs(root->right, row + 1, col + 1);
}

// Main function to perform vertical order traversal
int** verticalTraversal(TreeNode* root, int* returnSize, int** returnColumnSizes) {
    size = 0;
    nodes = malloc(10000 * sizeof(Node));  // Assuming a maximum of 10000 nodes
    dfs(root, 0, 0);

    // Sort the nodes based on column, then row, then value
    qsort(nodes, size, sizeof(Node), compare);

    int** result = malloc(size * sizeof(int*));
    *returnColumnSizes = malloc(size * sizeof(int));
    *returnSize = 0;
    int lastCol = INT_MIN;

    // Build the result based on the sorted nodes
    for (int i = 0; i < size; ++i) {
        if (nodes[i].col != lastCol) {
            lastCol = nodes[i].col;
            (*returnColumnSizes)[*returnSize] = 1;
            result[*returnSize] = malloc(size * sizeof(int));  // Allocate enough space
            result[*returnSize][0] = nodes[i].val;
            (*returnSize)++;
        } else {
            int idx = *returnSize - 1;  // Index of the current column in the result
            int pos = (*returnColumnSizes)[idx]++;  // Position to insert the node value in the current column
            result[idx][pos] = nodes[i].val;
        }
    }

    free(nodes);  // Free the allocated memory for nodes
    return result;
}



