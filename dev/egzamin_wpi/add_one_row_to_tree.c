/*


Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.

Note that the root node is at depth 1.

The adding rule is:

Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree root and right subtree root.
cur's original left subtree should be the left subtree of the new left subtree root.
cur's original right subtree should be the right subtree of the new right subtree root.
If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original tree, and the original tree is the new root's left subtree.


***


To add a row of nodes with a given value at a specified depth in a binary tree, you can use a level order traversal approach to reach the level just above the target depth and then insert the new nodes. Here's how you can implement this in C:

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Helper function to create a new TreeNode
TreeNode* createTreeNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to add one row to the tree
TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    if (depth == 1) {
        TreeNode* newRoot = createTreeNode(val);
        newRoot->left = root;
        return newRoot;
    }

    int currentDepth = 1;
    TreeNode* queue[10000]; // Assuming a maximum of 10000 nodes in the tree
    int front = 0, rear = 0;
    
    // Start with the root node in the queue
    queue[rear++] = root;

    // Perform level order traversal until the level just above the target depth
    while (front < rear && currentDepth < depth - 1) {
        int levelSize = rear - front;
        for (int i = 0; i < levelSize; i++) {
            TreeNode* currentNode = queue[front++];
            if (currentNode->left) queue[rear++] = currentNode->left;
            if (currentNode->right) queue[rear++] = currentNode->right;
        }
        currentDepth++;
    }

    // Insert the new row
    for (int i = front; i < rear; i++) {
        TreeNode* node = queue[i];
        TreeNode* tempLeft = node->left;
        TreeNode* tempRight = node->right;
        
        node->left = createTreeNode(val);
        node->left->left = tempLeft;

        node->right = createTreeNode(val);
        node->right->right = tempRight;
    }

    return root;
}

int main() {
    // Example usage:
    TreeNode* root = createTreeNode(4);
    root->left = createTreeNode(2);
    root->right = createTreeNode(6);
    root->left->left = createTreeNode(3);
    root->left->right = createTreeNode(1);
    root->right->left = createTreeNode(5);

    int valToAdd = 1;
    int depthToAdd = 2;

    root = addOneRow(root, valToAdd, depthToAdd);

    // Perform other operations with the modified tree
    // Remember to free all allocated memory when done

    return 0;
}

