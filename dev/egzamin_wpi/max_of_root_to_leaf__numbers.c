/* RETURN MAX ROOT TO LEAF NUMBER

To find the maximum number represented by a root-to-leaf path in a binary tree where each node has a value from 0 to 9, you can use a depth-first search (DFS) approach. As you traverse from the root to each leaf, you build the numbers by appending the current node's value to the current path number. When a leaf node is reached, you compare the number formed by the current path with the current maximum number and update the maximum if necessary.


*/

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val; // Node value can be from 0 to 9
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to perform DFS traversal and find the maximum number.
void findMaxNumber(struct TreeNode* node, int currentNum, int* maxNum) {
    if (node == NULL) return; // Base case: empty node

    // Update the current number by appending the current node's value.
    currentNum = currentNum * 10 + node->val;

    // Check if the current node is a leaf
    if (node->left == NULL && node->right == NULL) {
        // Update maxNum if the current number is greater than the maxNum
        if (currentNum > *maxNum) {
            *maxNum = currentNum;
        }
    } else {
        // Continue DFS traversal on left and right children
        findMaxNumber(node->left, currentNum, maxNum);
        findMaxNumber(node->right, currentNum, maxNum);
    }
}

// Function to return the maximum number represented by any root-to-leaf path.
int maxNumberFromRootToLeaf(struct TreeNode* root) {
    int maxNum = 0;
    findMaxNumber(root, 0, &maxNum); // Start DFS with the root, initial number is 0
    return maxNum;
}

// Utility function to create a new TreeNode
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Example usage
int main() {
    // Construct an example tree:
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left

