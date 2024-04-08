/*
Return true if and only if the value at root is equal to the sum of (nodes below the root)


To determine if the value of the root of a binary tree is equal to the sum of the values of all nodes below the root, you can use a recursive function to traverse the tree and calculate the sum of all node values. Then, you can compare this sum to the value of the root node.

The function will traverse the tree in a depth-first manner, summing the values of all nodes, and then return this sum to the calling function. At the root level, you can then subtract the root's value from the total sum and compare the result to the root's value to decide the truth of the condition.

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

// Helper function to calculate the sum of all nodes in the tree
int sumOfNodes(struct TreeNode* node) {
    if (node == NULL) {
        return 0; // Base case: if the node is null, return 0
    }
    // Recursive call to sum the values of left and right subtrees, and add the current node's value
    return node->val + sumOfNodes(node->left) + sumOfNodes(node->right);
}

// Main function to check if the root's value is equal to the sum of all nodes below it
bool isRootEqualToSumOfNodesBelow(struct TreeNode* root) {
    if (root == NULL) {
        return true; // If the tree is empty, consider it as meeting the condition
    }
    int totalSum = sumOfNodes(root); // Calculate the total sum of all nodes in the tree
    int sumBelow = totalSum - root->val; // Calculate the sum of nodes below the root
    return root->val == sumBelow; // Return true if the root's value equals the sum of nodes below it
}

int main() {
    // Example usage
    // struct TreeNode* root = createNode(10);
    // root->left = createNode(4);
    // root->right = createNode(6);
    // root->left->left = createNode(3);
    // root->left->right = createNode(1);
    // root->right->left = createNode(5);

    // bool result = isRootEqualToSumOfNodesBelow(root);
    // if (result) {
    //     printf("The root's value is equal to the sum of all nodes below it.\n");
    // } else {
    //     printf("The root's value is NOT equal to the sum of all nodes below it.\n");
    // }

    return 0;
}

