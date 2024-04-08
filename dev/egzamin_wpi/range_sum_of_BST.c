/*

Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

To solve this problem, you can use a recursive function that traverses the binary search tree (BST) and sums up the values of nodes that fall within the inclusive range [low, high]. The nature of the BST allows for efficient pruning of branches that do not need to be explored, i.e., if a node's value is less than low, there's no need to explore its left subtree, and similarly, if a node's value is greater than high, there's no need to explore its right subtree.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Helper function to create a new Binary Tree node
TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Recursive function to sum values in the range [low, high]
int rangeSumBST(TreeNode* root, int low, int high) {
    if (root == NULL) {
        return 0;  // Base case: if the node is NULL, return 0
    }
    
    int sum = 0;
    if (root->val >= low && root->val <= high) {
        sum += root->val;  // Include the current node's value if it's within the range
    }
    
    // If the current node's value is greater than low, explore the left subtree
    if (root->val > low) {
        sum += rangeSumBST(root->left, low, high);
    }
    
    // If the current node's value is less than high, explore the right subtree
    if (root->val < high) {
        sum += rangeSumBST(root->right, low, high);
    }
    
    return sum;
}

// Example usage
int main() {
    TreeNode* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(3);
    root->left->right = newNode(7);
    root->right->right = newNode(18);

    int low = 7, high = 15;
    int sum = rangeSumBST(root, low, high);
    printf("Range Sum: %d\n", sum);

    // Remember to free the allocated memory for the nodes after usage
    return 0;
}

