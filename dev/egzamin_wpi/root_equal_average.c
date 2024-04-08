/*

Return true if and only if the value at root is equal to the average of (nodes below the root)



To determine if the value at the root of a binary tree is equal to the average of the values of all nodes below the root, we can adapt the previous approach with a slight modification. Instead of just calculating the sum of the nodes below the root, we also need to count these nodes so we can calculate their average. We can then compare this average to the root's value to determine if the condition is met.

We'll use a helper function that calculates both the sum of the node values and the count of the nodes. Then, we'll use these values to calculate the average and compare it to the root's value.


*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for tree nodes
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

// Utility function to create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Helper function to calculate the sum and count of nodes in the tree
void sumAndCountNodes(struct TreeNode* node, int* sum, int* count) {
    if (node == NULL) {
        return; // Base case: if the node is null, return
    }
    *sum += node->val; // Add the current node's value to the sum
    *count += 1; // Increment the count of nodes
    sumAndCountNodes(node->left, sum, count); // Recursive call for the left subtree
    sumAndCountNodes(node->right, sum, count); // Recursive call for the right subtree
}

// Main function to check if the root's value equals the average of nodes below it
bool isRootEqualToAverageOfNodesBelow(struct TreeNode* root) {
    if (root == NULL) {
        return true; // If the tree is empty, consider it as meeting the condition
    }
    int sum = 0, count = -1; // Initialize count as -1 to exclude the root node from the count
    sumAndCountNodes(root, &sum, &count); // Calculate the total sum and count of nodes
    if (count == 0) return true; // If there are no nodes below the root, consider the condition met
    int average = sum / count; // Calculate the average (integer division automatically rounds down)
    return root->val == average; // Return true if the root's value equals the average
}

int main() {
    // Example usage
    // struct TreeNode* root = createNode(3);
    // root->left = createNode(2);
    // root->right = createNode(4);
    // root->left->left = createNode(1);
    // root->left->right = createNode(3);

    // bool result = isRootEqualToAverageOfNodesBelow(root);
    // if (result) {
    //     printf("The root's value is equal to the average of all nodes below it.\n");
    // } else {
    //     printf("The root's value is NOT equal to the average of all nodes below it.\n");
    // }

    return 0;
}

