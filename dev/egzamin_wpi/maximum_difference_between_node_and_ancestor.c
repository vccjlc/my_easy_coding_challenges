/*


Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.

Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.



To find the maximum value v for which there exist different nodes a and b such that v = |a.val - b.val| and a is an ancestor of b, we can use a recursive Depth-First Search (DFS) approach. During the recursion, we keep track of the maximum and minimum values encountered along the path from the root to the current node.

*/


#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Helper function to create a new tree node
TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Helper function to calculate the maximum absolute difference
int maxAncestorDiffHelper(TreeNode* node, int minVal, int maxVal) {
    if (!node) return maxVal - minVal;

    // Update the max and min values on the path from root to this node
    maxVal = (node->val > maxVal) ? node->val : maxVal;
    minVal = (node->val < minVal) ? node->val : minVal;

    // Recursively find the maximum difference in the left and right subtrees
    int leftMaxDiff = maxAncestorDiffHelper(node->left, minVal, maxVal);
    int rightMaxDiff = maxAncestorDiffHelper(node->right, minVal, maxVal);

    // Return the maximum of the two differences
    return (leftMaxDiff > rightMaxDiff) ? leftMaxDiff : rightMaxDiff;
}

// Main function to find the maximum absolute difference
int maxAncestorDiff(TreeNode* root) {
    if (!root) return 0;
    // Initialize the min and max values with root's value
    return maxAncestorDiffHelper(root, root->val, root->val);
}

// Example usage
int main() {
    // Construct the binary tree from the problem's example
    TreeNode* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
    root->right->right->left = newNode(13);

    int result = maxAncestorDiff(root);
    printf("Maximum ancestor difference: %d\n", result);

    // Free the allocated memory for the tree nodes (not shown here)

    return 0;
}

