/*

You are given a binary tree of integers. Return the number of palindromic paths that have length greater than 1 



DFS Traversal: Start a DFS traversal from the root. Along each path, keep track of the count of each node value encountered using a frequency array or map.

Check for Palindrome: At each node (especially at leaf nodes), check if the path formed up to this point can create a palindrome. A path can form a palindrome if at most one node value has an odd frequency, and all other node values have even frequencies.

Backtracking: As you backtrack from a leaf to the root (or from a child to its parent), decrement the frequency count of the node being backtracked from, so the frequency array or map reflects the correct frequencies for the current path in the DFS traversal.

Count Palindromic Paths: Increment a global or static counter each time a palindromic path is identified. Ensure that the length of the path is greater than 1.


*/




#include <stdio.h>
#include <stdlib.h>

// Binary tree node structure
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

// Function to create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Utility function to check if a path can form a palindrome
int canFormPalindrome(int *freq) {
    int oddCount = 0;
    for (int i = 0; i < 10; i++) {  // Assuming node values are in the range [0, 9]
        if (freq[i] % 2 != 0) {
            oddCount++;
            if (oddCount > 1) return 0;  // More than one odd frequency count
        }
    }
    return 1;  // Can form a palindrome
}

// DFS function to count palindromic paths
int dfs(struct TreeNode* node, int *freq) {
    if (node == NULL) return 0;

    freq[node->val]++;  // Increment frequency of current node value

    int count = 0;
    if (node->left == NULL && node->right == NULL) {  // Leaf node
        if (canFormPalindrome(freq)) count = 1;  // Check if the path can form a palindrome
    } else {
        count += dfs(node->left, freq);   // DFS on left child
        count += dfs(node->right, freq);  // DFS on right child
    }

    freq[node->val]--;  // Backtrack

    return count;
}

// Main function to find the number of palindromic paths
int countPalindromicPaths(struct TreeNode* root) {
    int freq[10] = {0};  // Frequency array for node values
    return dfs(root, freq);
}

int main() {
    // Example usage
    // struct TreeNode* root = createNode(2);
    // root->left = createNode(3);
    // root->right = createNode(1);
    // root->left->left = createNode(3);
    // root->right->left = createNode(1);
    // root->right->right = createNode(1);

    // int result = countPalindromicPaths(root);
    // printf("Number of palindromic paths: %d\n", result);

    return 0;
}

