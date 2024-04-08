/*
write a function to return node with the third minimum value

To find the node with the third minimum value in a binary search tree (BST), where each node has a unique value, you can perform an in-order traversal which visits the nodes in ascending order. You keep a count of the nodes visited and return the node when the count reaches three.

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
    node->left = node->right = NULL;
    return node;
}

// Helper function to perform in-order traversal.
void inorderTraversal(struct TreeNode* root, int* count, int* thirdMin, struct TreeNode** thirdMinNode) {
    if (root == NULL || *count >= 3) return;

    inorderTraversal(root->left, count, thirdMin, thirdMinNode);
    
    // Increment count and check if it's the third node.
    (*count)++;
    if (*count == 3) {
        *thirdMin = root->val;
        *thirdMinNode = root;
        return;
    }
    
    inorderTraversal(root->right, count, thirdMin, thirdMinNode);
}

// Function to find the third minimum value in the BST.
struct TreeNode* findThirdMinimum(struct TreeNode* root) {
    int count = 0;
    int thirdMin = -1;
    struct TreeNode* thirdMinNode = NULL;
    
    inorderTraversal(root, &count, &thirdMin, &thirdMinNode);

    // If the thirdMinNode is still NULL, then there weren't enough nodes in the tree.
    if (thirdMinNode == NULL) {
        printf("The tree does not have a third minimum value.\n");
        return NULL;
    }
    
    printf("The third minimum value is: %d\n", thirdMin);
    return thirdMinNode;
}

int main() {
    // Example usage:
    struct TreeNode* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(6);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->left->left->left = createNode(1);

    struct TreeNode* thirdMinNode = findThirdMinimum(root);
    if (thirdMinNode != NULL) {
        printf("Node with the third minimum value: %d\n", thirdMinNode->val);
    }

    // Don't forget to free the memory for the nodes in a real program!
    return 0;
}

