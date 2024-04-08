/*

Given the roots of two binary search trees, root and root2, return true if and only if there is a node in the first tree and a node in the second tree whose values sum up to a given integer target.


*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Helper function to perform an in-order traversal and store the values in an array.
void inorder(struct TreeNode* root, int* arr, int* index) {
    if (root == NULL) return;
    inorder(root->left, arr, index);
    arr[(*index)++] = root->val;
    inorder(root->right, arr, index);
}

// Function to find two elements that sum up to the target value using the two-pointer technique.
bool findTarget(int* arr1, int size1, int* arr2, int size2, int target) {
    int i = 0;       // Start pointer for arr1
    int j = size2-1; // End pointer for arr2

    while (i < size1 && j >= 0) {
        int sum = arr1[i] + arr2[j];
        if (sum == target) {
            return true;
        } else if (sum < target) {
            i++;
        } else {
            j--;
        }
    }
    return false;
}

// Two Sum BSTs function to determine if two values sum up to the target.
bool twoSumBSTs(struct TreeNode* root1, struct TreeNode* root2, int target) {
    // Assuming that the number of nodes in each tree does not exceed 5000
    int arr1[5000], arr2[5000];
    int index1 = 0, index2 = 0;

    // Perform in-order traversal to store values in arrays
    inorder(root1, arr1, &index1);
    inorder(root2, arr2, &index2);

    // Use the two-pointer technique to find the target sum
    return findTarget(arr1, index1, arr2, index2, target);
}

// Example usage
int main() {
    struct TreeNode* root1 = newNode(2);
    root1->left = newNode(1);
    root1->right = newNode(4);

    struct TreeNode* root2 = newNode(1);
    root2->left = newNode(0);
    root2->right = newNode(3);

    int target = 5;
    if (twoSumBSTs(root1, root2, target)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    // Remember to free the memory allocated for the BSTs

    return 0;
}

