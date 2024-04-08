/*
INCREASING ARRAY

Convert Sorted Array to Binary Search Tree (BST): Given a sorted (increasing order) array, convert it to a height-balanced BST.

To convert a sorted array into a height-balanced Binary Search Tree (BST), you can use a divide and conquer approach. The key idea is to select the middle element of the sorted array as the root of the BST, which ensures that the resulting BST is height-balanced. Then, recursively apply the same strategy to the left half of the array to construct the left subtree and to the right half of the array to construct the right subtree.


*/

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to create a new TreeNode.
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* sortedArrayToBSTHelper(int* nums, int start, int end) {
    if (start > end) {
        return NULL;
    }

    int mid = start + (end - start) / 2;

    struct TreeNode* root = newNode(nums[mid]);

    root->left = root->left = sortedArrayToBSTHelper(nums, start, mid - 1);
    root->right = sortedArrayToBSTHelper(nums, mid + 1, end);

    return root;

}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return sortedArrayToBSTHelper(nums, 0, numsSize - 1);
}

// Utility function to print the pre-order traversal of the BST.
void preOrderTraversal(struct TreeNode* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->val);
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

// Example usage
int main() {
    int nums[] = {-10, -3, 0, 5, 9};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    struct TreeNode* root = sortedArrayToBST(nums, numsSize);

    printf("Pre-order Traversal of the constructed BST: ");
    preOrderTraversal(root);
    printf("\n");

    // Free allocated memory (omitted for brevity)

    return 0;
}

