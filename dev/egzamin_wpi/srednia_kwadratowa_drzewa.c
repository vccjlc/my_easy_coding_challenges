// Srednia kwadratowa drzewa


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the structure for tree nodes
struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Utility function to create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Helper function to sum up the squares of node values
void sumOfSquares(struct TreeNode* node, double* sum, int* count) {
    if (node == NULL) {
        return; // Base case: if the node is null, return
    }
    *sum += pow(node->value, 2); // Add the square of the current node's value to the sum
    *count += 1; // Increment the count of nodes
    sumOfSquares(node->left, sum, count); // Recur for left subtree
    sumOfSquares(node->right, sum, count); // Recur for right subtree
}

// Function to calculate the Root Mean Square (RMS) of a binary tree
double calculateRMS(struct TreeNode* root) {
    double sum = 0;
    int count = 0;
    sumOfSquares(root, &sum, &count); // Calculate sum of squares of values and count of nodes
    if (count == 0) return 0.0; // To avoid division by zero
    return sqrt(sum / count); // Calculate and return the RMS
}

int main() {
    // Example usage
    // struct TreeNode* root = createNode(3);
    // root->left = createNode(4);
    // root->right = createNode(5);
    // root->left->left = createNode(-5);
    // root->left->right = createNode(2);
    
    // double rms = calculateRMS(root);
    // printf("Root Mean Square (RMS) of the tree: %.2f\n", rms);

    return 0;
}

