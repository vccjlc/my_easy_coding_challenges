/*

Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.




To find the modes in a BST, we can perform an in-order traversal, which will visit the nodes in non-decreasing order because of the BST property. During the traversal, we can keep track of the current number count, update the mode(s) when a new maximum count is found, and handle the case when there are multiple modes with the same frequency.

Here's how you can do it in C:

*/


#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
} TreeNode;

// Function to create a new TreeNode
TreeNode* createTreeNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int* modes; // Array to store the modes
int modesSize; // Size of the modes array
int modesCapacity; // Capacity of the modes array
int currentVal; // Current value being counted
int currentCount; // Count of the current value
int maxCount; // Maximum count for a value seen so far

// Resize the modes array if necessary
void ensureCapacity(int newCapacity) {
    if (newCapacity > modesCapacity) {
        modes = realloc(modes, newCapacity * sizeof(int));
        modesCapacity = newCapacity;
    }
}

// Add a mode to the modes array
void addMode(int val) {
    if (modesSize == modesCapacity) {
        ensureCapacity(modesCapacity * 2);
    }
    modes[modesSize++] = val;
}

// Reset the current count and update the mode if necessary
void handleValue(int val) {
    if (val != currentVal) {
        currentVal = val;
        currentCount = 0;
    }
    currentCount++;
    if (currentCount > maxCount) {
        maxCount = currentCount;
        modesSize = 0; // Reset modes array
        addMode(val);
    } else if (currentCount == maxCount) {
        addMode(val);
    }
}

// In-order traversal to count values
void inOrder(TreeNode* root) {
    if (root == NULL) return;
    inOrder(root->left);
    handleValue(root->val);
    inOrder(root->right);
}

// Function to find the modes in the BST
int* findMode(TreeNode* root, int* returnSize) {
    modes = malloc(1 * sizeof(int));
    modesSize = 0;
    modesCapacity = 1;
    currentVal = 0; // Assuming val is non-negative, 0 is used for initialization
    currentCount = 0;
    maxCount = 0;

    inOrder(root);

    *returnSize = modesSize;
    return modes;
}

int main() {
    // Assume createTreeNode function is given and the tree is created

    // Example usage
    TreeNode* root = createTreeNode(1);
    root->right = createTreeNode(2);
    root->right->left = createTreeNode(2);

    int returnSize;
    int* result = findMode(root, &returnSize);
    printf("Modes: ");
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result); // Don't forget to free the result

    // Free memory if needed and perform other cleanups

    return 0;
}

