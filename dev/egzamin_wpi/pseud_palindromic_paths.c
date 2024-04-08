/*

Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic if at least one permutation of the node values in the path is a palindrome.

Return the number of pseudo-palindromic paths going from the root node to leaf nodes.


***

To solve this problem, you can perform a Depth-First Search (DFS) traversal on the binary tree and keep track of the count of each digit along the path from the root to the current node. For a path to be pseudo-palindromic, you can have at most one digit with an odd count; all other digits must have even counts. This is because a palindrome can have at most one character that appears an odd number of times (in the middle of the palindrome).

You can use a bit vector (an integer variable) to efficiently track the counts of digits. Each bit in the integer will represent the odd/even count status of a digit from 1 to 9. Flipping a bit will correspond to encountering a digit in the path.

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

// Recursive DFS function to count pseudo-palindromic paths
int dfs(TreeNode* node, int count) {
    if (!node) return 0;
    
    // Flip the bit corresponding to the current node's value
    count ^= 1 << node->val;

    // If it's a leaf node, check if the path is pseudo-palindromic
    if (!node->left && !node->right) {
        // Check if count has at most one bit set
        if ((count & (count - 1)) == 0) {
            return 1; // This path is pseudo-palindromic
        }
        return 0;
    }

    // Recurse on left and right children
    return dfs(node->left, count) + dfs(node->right, count);
}

// Main function to return the number of pseudo-palindromic paths
int pseudoPalindromicPaths(TreeNode* root) {
    return dfs(root, 0);
}

// Example usage
int main() {
    // Construct the binary tree
    TreeNode* root = newNode(2);
    root->left = newNode(3);
    root->right = newNode(1);
    root->left->left = newNode(3);
    root->left->right = newNode(1);
    root->right->right = newNode(1);

    int result = pseudoPalindromicPaths(root);
    printf("Number of pseudo-palindromic paths: %d\n", result);

    // Free the allocated memory for the tree nodes (not shown here)

    return 0;
}

