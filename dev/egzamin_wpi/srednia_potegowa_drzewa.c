// Srednia potegowa drzewa

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

// Helper function to sum up values raised to the power k
void sumOfPowers(struct TreeNode* node, int k, double* sum, int* count) {
    if (node == NULL) {
        return; // Base case: if the node is null, return
    }
    *sum += pow(node->value, k); // Add the value of the current node raised to k to the sum
    *count += 1; // Increment the count of nodes
    sumOfPowers(node->left, k, sum, count); // Recur for left subtree
    sumOfPowers(node->right, k, sum, count); // Recur for right subtree
}

// Function to calculate the generalized mean of a binary tree for exponent k
double calculateGeneralizedMean(struct TreeNode* root, int k) {
    double sum = 0;
    int count = 0;
    sumOfPowers(root, k, &sum, &count); // Calculate sum of values raised to k and count of nodes
    if (count == 0) return 0.0; // To avoid division by zero
    return pow(sum / count, 1.0 / k); // Calculate and return the generalized mean
}

int main() {
    // Example usage
    // struct TreeNode* root = createNode(4);
    // root->left = createNode(2);
    // root->right = createNode(6);
    // root->left->left = createNode(1);
    // root->left->right = createNode(3);
    
    // int k = 2; // Exponent for generalized mean
    // double generalizedMean = calculateGeneralizedMean(root, k);
    // printf("Generalized mean with k=%d: %.2f\n", k, generalizedMean);

    return 0;
}

