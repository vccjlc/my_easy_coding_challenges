/*


Calculate the average of subtree


To calculate the average value of a binary tree, you need to traverse the entire tree to sum up all the node values and count the number of nodes. Once you have the total sum and the node count, you can calculate the average by dividing the sum by the count.



*/


#include <stdio.h>
#include <stdlib.h>

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

// Helper function to sum up values and count nodes
void sumAndCountNodes(struct TreeNode* node, int* sum, int* count) {
    if (node == NULL) {
        return; // Base case: if the node is null, return
    }
    *sum += node->value; // Add the value of the current node to the sum
    *count += 1; // Increment the count of nodes
    sumAndCountNodes(node->left, sum, count); // Recur for left subtree
    sumAndCountNodes(node->right, sum, count); // Recur for right subtree
}

// Function to calculate the average value of a binary tree
double calculateAverage(struct TreeNode* root) {
    int sum = 0, count = 0;
    sumAndCountNodes(root, &sum, &count); // Calculate total sum and count of nodes
    if (count == 0) return 0.0; // To avoid division by zero
    return (double)sum / count; // Calculate and return the average
}

int main() {
    // Example usage
    // struct TreeNode* root = createNode(10);
    // root->left = createNode(5);
    // root->right = createNode(15);
    // root->left->left = createNode(2);
    // root->left->right = createNode(7);
    
    // double average = calculateAverage(root);
    // printf("Average value of the tree: %.2f\n", average);

    return 0;
}

