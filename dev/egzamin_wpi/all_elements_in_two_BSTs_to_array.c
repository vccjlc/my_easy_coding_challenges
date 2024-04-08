/*

Given two binary search trees root1 and root2, return an array containing all the integers from both trees sorted in ascending order.


To merge two binary search trees (BSTs) into a sorted array, you can perform an in-order traversal on both trees to get two sorted lists and then merge these two sorted lists.



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

// Helper function to perform in-order traversal and fill the array with BST elements
void inOrderTraversal(TreeNode* root, int* arr, int* index) {
    if (root == NULL) return;
    inOrderTraversal(root->left, arr, index);
    arr[(*index)++] = root->val;
    inOrderTraversal(root->right, arr, index);
}

// Function to merge two sorted arrays into one
int* mergeArrays(int* arr1, int size1, int* arr2, int size2, int* returnSize) {
    int* mergedArr = (int*)malloc((size1 + size2) * sizeof(int));
    int i = 0, j = 0, k = 0;

    // Merge the two arrays
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            mergedArr[k++] = arr1[i++];
        } else {
            mergedArr[k++] = arr2[j++];
        }
    }

    // If there are remaining elements in arr1, add them
    while (i < size1) {
        mergedArr[k++] = arr1[i++];
    }

    // If there are remaining elements in arr2, add them
    while (j < size2) {
        mergedArr[k++] = arr2[j++];
    }

    *returnSize = size1 + size2;
    return mergedArr;
}

// Main function to get all elements from both BSTs sorted in ascending order
int* getAllElements(TreeNode* root1, TreeNode* root2, int* returnSize) {
    int size1 = 1000; // Assuming the BSTs have at most 1000 nodes each
    int size2 = 1000;
    int* arr1 = (int*)malloc(size1 * sizeof(int));
    int* arr2 = (int*)malloc(size2 * sizeof(int));
    int index1 = 0, index2 = 0;

    // Perform in-order traversal to get sorted arrays from BSTs
    inOrderTraversal(root1, arr1, &index1);
    inOrderTraversal(root2, arr2, &index2);

    // Merge the two sorted arrays
    int* mergedArr = mergeArrays(arr1, index1, arr2, index2, returnSize);

    // Free the allocated memory for the individual arrays
    free(arr1);
    free(arr2);

    return mergedArr;
}

// Add your functions to construct the BSTs, print the result, and free the nodes

