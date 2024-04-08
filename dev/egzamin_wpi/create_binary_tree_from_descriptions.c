/*

You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

If isLefti == 1, then childi is the left child of parenti.
If isLefti == 0, then childi is the right child of parenti.
Construct the binary tree described by descriptions and return its root.

The test cases will be generated such that the binary tree is valid.


*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* createBinaryTree(int** descriptions, int descriptionsSize, int* descriptionsColSize) {
    struct TreeNode* nodes[100001] = {NULL}; // Assuming values are <= 100000
    char isChild[100001] = {0}; // To identify the root node (0 indicates potential root)

    for (int i = 0; i < descriptionsSize; i++) {
        int parentVal = descriptions[i][0];
        int childVal = descriptions[i][1];
        int isLeft = descriptions[i][2];

        // Create or get parent node
        if (nodes[parentVal] == NULL) {
            nodes[parentVal] = newNode(parentVal);
        }
        struct TreeNode* parent = nodes[parentVal];

        // Create or get child node
        if (nodes[childVal] == NULL) {
            nodes[childVal] = newNode(childVal);
        }
        struct TreeNode* child = nodes[childVal];
        isChild[childVal] = 1; // Mark as child

        // Link parent and child
        if (isLeft) {
            parent->left = child;
        } else {
            parent->right = child;
        }
    }

    // Find root (the one not marked as child)
    struct TreeNode* root = NULL;
    for (int i = 0; i < descriptionsSize; i++) {
        int parentVal = descriptions[i][0];
        if (!isChild[parentVal]) {
            root = nodes[parentVal];
            break;
        }
    }

    return root;
}


