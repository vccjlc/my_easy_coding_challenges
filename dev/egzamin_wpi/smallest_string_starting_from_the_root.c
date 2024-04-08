/*

To find the lexicographically smallest string that starts at a leaf and ends at the root in a binary tree where nodes represent letters 'a' to 'z', we can use a Depth-First Search (DFS) approach. The idea is to traverse from the root to each leaf, keeping track of the path string. When a leaf is reached, compare the current path string with the previously stored smallest string and update it if the current one is smaller.

Since we're building strings from leaf to root but need to compare them as if they're from root to leaf, we can add each new character to the front of our current path string. This way, deeper characters (closer to the leaf) are added later and thus come first in the string.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new tree node
TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Utility function to find the lexicographically smaller of two strings
char* minString(char* a, char* b) {
    return strcmp(a, b) < 0 ? a : b;
}

// DFS function to find the smallest string from leaf to root
void dfs(TreeNode* node, char* path, int depth, char** smallest) {
    if (!node) return;

    // Prepend current character to the path
    path[depth] = 'a' + node->val;

    if (!node->left && !node->right) {  // Leaf node
        path[depth + 1] = '\0';  // Null-terminate the string
        // Reverse the string as we constructed it backwards
        for (int i = 0; i < depth / 2; ++i) {
            char temp = path[i];
            path[i] = path[depth - i];
            path[depth - i] = temp;
        }
        // Update smallest if the current path is lexicographically smaller
        if (!*smallest || strcmp(path, *smallest) < 0) {
            *smallest = strdup(path);  // Duplicate the path as smallest
        }
    } else {
        dfs(node->left, path, depth + 1, smallest);
        dfs(node->right, path, depth + 1, smallest);
    }
}

// Main function to find the lexicographically smallest string from leaf to root
char* smallestFromLeaf(TreeNode* root) {
    char* smallest = NULL;
    char path[8500];  // Assuming a maximum depth of 8500, which is reasonable for most practical binary trees
    dfs(root, path, 0, &smallest);
    return smallest;
}

// Example usage
int main() {
    TreeNode* root = newNode(0);  // 'a'
    root->left = newNode(1);      // 'b'
    root->right = newNode(2);     // 'c'
    root->left->left = newNode(3);    // 'd'
    root->right->right = newNode(4);  // 'e'

    char* result = smallestFromLeaf(root);
    printf("Smallest string from leaf to root: %s\n", result);

    free(result);  // Remember to free the dynamically allocated memory
    // Free the tree nodes here (not shown for brevity)

    return 0;
}

