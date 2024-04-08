// Find longest consecutive sequence path


/*

To solve this problem, a recursive function can be used to traverse the binary tree. For each node, we check if its left or right child has a value that is one greater than its own value, which indicates a consecutive sequence. As we traverse, we keep track of the length of the current consecutive sequence and the maximum length found so far.

Here's the algorithm outline:

Start with a recursive function that checks the current node and its children.
If the current node's child has a value one greater than the current node, we continue the sequence; otherwise, we start a new sequence from the child.
Pass along the current sequence length and the maximum sequence length found so far.
The maximum sequence length is updated whenever we find a longer sequence.


*/
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
} TreeNode;

// Helper function to create a new TreeNode
TreeNode* createTreeNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive function to find the length of the longest consecutive sequence
void longestConsecutiveUtil(TreeNode* node, int currentLength, int expected, int* maxLength) {
    if (node == NULL) return;

    if (node->val == expected) {
        currentLength++;
    } else {
        currentLength = 1;  // Start a new sequence at this node
    }

    *maxLength = (currentLength > *maxLength) ? currentLength : *maxLength;

    // Recurse on left and right subtrees with expected values incremented by 1
    longestConsecutiveUtil(node->left, currentLength, node->val + 1, maxLength);
    longestConsecutiveUtil(node->right, currentLength, node->val + 1, maxLength);
}

// Main function to initiate the longest consecutive sequence search
int longestConsecutive(TreeNode* root) {
    if (root == NULL) return 0;

    int maxLength = 0;
    longestConsecutiveUtil(root, 0, root->val, &maxLength);
    return maxLength;
}

int main() {
    // Example usage
    TreeNode* root = createTreeNode(1);
    root->left = createTreeNode(2);
    root->left->left = createTreeNode(3);
    root->left->left->left = createTreeNode(4);
    root->left->left->left->right = createTreeNode(5);

    int result = longestConsecutive(root);
    printf("Longest consecutive sequence length: %d\n", result);

    // Free memory if needed and perform other cleanups

    return 0;
}

