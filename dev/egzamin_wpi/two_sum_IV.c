/*

Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.



To find if there exist two elements in the Binary Search Tree (BST) such that their sum equals a given integer k, you can use an in-order traversal to get a sorted list of elements and then use two pointers to check for the existence of the two numbers.

However, since we want to optimize for space, we can avoid the sorted list and use the BST property to search for the required pair in a more space-efficient manner. Here's an approach using a helper function that works like a two-pointer technique:

Perform an in-order traversal for the 'left pointer'.
Perform a reverse in-order traversal for the 'right pointer'.
If the sum of the two pointers is equal to k, return true.
If the sum is less than k, move the 'left pointer' to get a larger value.
If the sum is greater than k, move the 'right pointer' to get a smaller value.
Continue this process and if the two pointers meet/cross each other, return false.

*/


#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Utility function to create a new node
TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Utility function to perform an in-order traversal
void inOrder(TreeNode* root, int* arr, int* index) {
    if (root == NULL) return;
    inOrder(root->left, arr, index);
    arr[(*index)++] = root->val;
    inOrder(root->right, arr, index);
}

// Utility function to perform a reverse in-order traversal
void reverseInOrder(TreeNode* root, int* arr, int* index) {
    if (root == NULL) return;
    reverseInOrder(root->right, arr, index);
    arr[(*index)++] = root->val;
    reverseInOrder(root->left, arr, index);
}

// Main function to find if there exist two elements in the BST such that their sum equals k
int findTarget(TreeNode* root, int k) {
    // Calculate the size of the BST by in-order traversal
    int count = 0;
    inOrder(root, NULL, &count);
    
    // Store in-order elements
    int* inOrderElements = (int*)malloc(count * sizeof(int));
    int index = 0;
    inOrder(root, inOrderElements, &index);

    // Store reverse in-order elements
    int* reverseInOrderElements = (int*)malloc(count * sizeof(int));
    index = 0;
    reverseInOrder(root, reverseInOrderElements, &index);

    // Two-pointer technique
    int left = 0, right = count - 1;
    while (left < right) {
        int sum = inOrderElements[left] + reverseInOrderElements[right];
        if (sum == k) {
            free(inOrderElements);
            free(reverseInOrderElements);
            return 1;
        } else if (sum < k) {
            left++;
        } else {
            right--;
        }
    }
    
    free(inOrderElements);
    free(reverseInOrderElements);
    return 0;
}

// Example usage
int main() {
    TreeNode *root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(6);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->right = newNode(7);

    int k = 9;
    int result = findTarget(root, k);
    printf("Result: %d\n", result);

    // Free allocated memory
    free(root->left->left);
    free(root->left->right);
    free(root->right->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}

