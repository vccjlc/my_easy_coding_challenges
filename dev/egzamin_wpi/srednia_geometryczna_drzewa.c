// srednia geometryczna drzewa

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the structure for tree nodes
struct TreeNode {
    int value; // Assuming all values are positive for the geometric mean calculation
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

// Helper function to sum up the logarithms of node values and count nodes
void sumOfLogarithms(struct TreeNode* node, double* sum, int* count) {
    if (node == NULL) {
        return; // Base case: if the node is null, return
    }
    *sum += log(node->value); // Add the logarithm of the current node's value to the sum
    *count += 1; // Increment the count of nodes
    sumOfLogarithms(node->left, sum, count); // Recur for left subtree
    sumOfLogarithms(node->right, sum, count); // Recur for right subtree
}

// Function to calculate the geometric mean of a binary tree
double calculateGeometricMean(struct TreeNode* root) {
    double sum = 0;
    int count = 0;
    sumOfLogarithms(root, &sum, &count); // Calculate sum of logarithms of values and count of nodes
    if (count == 0) return 0.0; // To avoid division by zero
    return exp(sum / count); // Calculate and return the geometric mean
}

int main() {
    // Example usage
    // struct TreeNode* root = createNode(2);
    // root->left = createNode(8);
    // root->right = createNode(4);
    
    // double geometricMean = calculateGeometricMean(root);
    // printf("Geometric Mean of the tree: %.2f\n", geometricMean);

    return 0;
}

