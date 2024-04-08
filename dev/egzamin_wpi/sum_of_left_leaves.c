/*


Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.


(assume createNode and struct are given)



To calculate the sum of all left leaves in a binary tree, you can perform a traversal of the tree and check for each node if it has a left child that is a leaf. If it does, add its value to the sum. Here's a recursive function in C that does this:

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to check if a node is a leaf node
int isLeaf(TreeNode* node) {
    return (node != NULL) && (node->left == NULL) && (node->right == NULL);
}

// Recursive function to calculate the sum of all left leaves
int sumOfLeftLeaves(TreeNode* root) {
    if (root == NULL) return 0;
    
    int sum = 0;
    if (isLeaf(root->left)) {  // Check if left child is a leaf
        sum += root->left->val;
    } else {
        // Recurse on the left child if it is not a leaf
        sum += sumOfLeftLeaves(root->left);
    }
    // Recurse on the right child
    sum += sumOfLeftLeaves(root->right);
    
    return sum;
}

int main() {
    // Assume createNode function is given and the tree is created

    // Example usage
    TreeNode* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    int result = sumOfLeftLeaves(root);
    printf("Sum of all left leaves: %d\n", result);

    // Free memory if needed and perform other cleanups

    return 0;
}

