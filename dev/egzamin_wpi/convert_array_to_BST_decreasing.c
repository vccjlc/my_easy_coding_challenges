/*

DECREASING ARRAY

When converting a sorted array in decreasing order to a height-balanced Binary Search Tree (BST), the approach is similar to handling an increasing order array, but with a key difference in how you select elements for the left and right subtrees due to the reversed order of elements.

*/

TreeNode* sortedArrayToBSTDecreasing(int arr[], int start, int end) {
    // Base case: empty subarray
    if (start > end) return NULL;

    // Find the middle element of the current subarray
    int mid = start + (end - start) / 2;

    // Create a new node with the middle element as the root
    TreeNode* node = createNode(arr[mid]);

    // Recursively construct the "right" subtree using the left half of the current subarray
    // Note the swap of 'right' and 'left' compared to the increasing order case
    node->right = sortedArrayToBSTDecreasing(arr, start, mid - 1);

    // Recursively construct the "left" subtree using the right half of the current subarray
    node->left = sortedArrayToBSTDecreasing(arr, mid + 1, end);

    return node;
}

// Helper function to initiate the recursive construction
TreeNode* sortedArrayToBSTDecreasingHelper(int arr[], int n) {
    return sortedArrayToBSTDecreasing(arr, 0, n - 1);
}

