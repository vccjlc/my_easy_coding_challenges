/*

You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.
Return the minimum number of cameras needed to monitor all nodes of the tree.


To determine the minimum number of cameras needed to monitor all nodes of a binary tree, we can use a greedy recursive approach that operates on the idea that we should set cameras at all "grandparent" nodes. This is because installing a camera at a grandparent node covers the grandparent itself, its children, and its grandchildren.


*/


#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to create a new tree node.
struct TreeNode* createNode(int value) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// States for whether a node is covered, has a camera, or is not covered.
typedef enum { NOT_COVERED, COVERED, HAS_CAMERA } State;

// Helper function for the recursive greedy algorithm.
int minCameraCoverHelper(struct TreeNode* root, int* cameraCount) {
    // If there is no node, we consider it as covered.
    if (!root) return COVERED;

    // Post-order traversal: left, right, node.
    int left = minCameraCoverHelper(root->left, cameraCount);
    int right = minCameraCoverHelper(root->right, cameraCount);

    // If any of the children is not covered, we need to place a camera at the current node.
    if (left == NOT_COVERED || right == NOT_COVERED) {
        (*cameraCount)++;
        return HAS_CAMERA;
    }

    // If either of the children has a camera, the current node is covered.
    if (left == HAS_CAMERA || right == HAS_CAMERA) {
        return COVERED;
    }

    // Otherwise, the current node is not covered and requires the parent to have a camera.
    return NOT_COVERED;
}

// Main function to find the minimum number of cameras needed to cover the tree.
int minCameraCover(struct TreeNode* root) {
    int cameraCount = 0;
    // If the root is not covered, add one more camera.
    if (minCameraCoverHelper(root, &cameraCount) == NOT_COVERED) {
        cameraCount++;
    }
    return cameraCount;
}

int main() {
    // Example usage:
    // struct TreeNode* root = createNode(0);
    // root->left = createNode(0);
    // root->left->left = createNode(0);
    // root->left->left->left = createNode(0);
    // root->left->left->right = createNode(0);

    // int result = minCameraCover(root);
    // printf("Minimum number of cameras needed: %d\n", result);

    return 0;
}

