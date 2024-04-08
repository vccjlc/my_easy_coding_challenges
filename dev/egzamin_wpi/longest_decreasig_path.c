/*

To find the longest consecutive decreasing path in a binary tree, we need to traverse the tree and at each node keep track of the length of the current consecutive decreasing sequence. We need to increment the length when we move from a node to a child node with a value that is one less than the current node. If this is not the case, we reset the length of the path.



*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// A utility function to create a new Binary Tree node
TreeNode* newNode(int val) {
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Helper function to find the longest consecutive decreasing sequence
void findLongestConsecutiveDecreasing(TreeNode* node, int* maxLength, int currentLength, int prevVal) {
    if (node == NULL) return;

    // Check if current node is decreasing by 1 from its parent
    if (node->val == prevVal - 1) {
        currentLength++;
    } else {
        currentLength = 1;
    }

    // Update the maximum length
    if (currentLength > *maxLength) {
        *maxLength = currentLength;
    }

    // Recur for left and right subtrees
    findLongestConsecutiveDecreasing(node->left, maxLength, currentLength, node->val);
    findLongestConsecutiveDecreasing(node->right, maxLength, currentLength, node->val);
}

// Main function to find the longest decreasing consecutive sequence
int longestConsecutiveDecreasing(TreeNode* root) {
    int maxLength = 0;
    findLongestConsecutiveDecreasing(root, &maxLength, 0, root->val + 1); // Initialize prevVal to root->val + 1 to start the sequence
    return maxLength;
}

// Example usage
int main() {
    TreeNode *root = newNode(3);
    root->left = newNode(2);
    root->left->left = newNode(1);
    root->right = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);

    int maxLength = longestConsecutiveDecreasing(root);
    printf("The length of the longest consecutive decreasing path is: %d\n", maxLength);

    // Free the allocated memory
    free(root->left->left);
    free(root->left);
    free(root->right->left);
    free(root->right->right);
    free(root->right);
    free(root);

    return 0;
}

