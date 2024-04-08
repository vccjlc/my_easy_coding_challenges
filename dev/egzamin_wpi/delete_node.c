/*


Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.



To delete a node from a Binary Search Tree (BST), we need to follow a specific set of rules to maintain the properties of the BST. The deletion process involves finding the node, then handling three possible scenarios:

Node is a leaf: Simply remove the node.
Node has one child: Remove the node and replace it with its child.
Node has two children: Find the inorder successor (smallest in the right subtree or largest in the left subtree) of the node, copy its value to the node, and then delete the successor. This way, the structure of the BST is preserved.


*/



#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new TreeNode
TreeNode* createTreeNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find the minimum value node in the given BST
TreeNode* findMin(TreeNode* node) {
    TreeNode* current = node;
    // loop down to find the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the BST
TreeNode* deleteNode(TreeNode* root, int key) {
    // base case
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    }
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    }
    // if key is same as root's key, then This is the node to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest in the right subtree)
        TreeNode* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->val = temp->val;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

