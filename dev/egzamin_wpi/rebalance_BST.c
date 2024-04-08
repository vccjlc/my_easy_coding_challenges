/*
To rebalance an unbalanced Binary Search Tree (BST) without altering the node values' in-order sequence, you can follow a two-step process:

Convert the BST to a Sorted Array: Perform an in-order traversal of the BST to get the node values in ascending order, and store these values in a sorted array. This step ensures that the in-order sequence of the node values is preserved.

Build a Height-Balanced BST from the Sorted Array: Use the technique for constructing a height-balanced BST from a sorted array, similar to what was described in the previous solution. This step ensures that the new BST is height-balanced.

*/
void BSTToArray(TreeNode* root, int arr[], int* index) {
    if (root == NULL) return;

    // In-order traversal to preserve the ascending order
    BSTToArray(root->left, arr, index);
    arr[(*index)++] = root->value;  // Store the value in the array
    BSTToArray(root->right, arr, index);
}


TreeNode* sortedArrayToBST(int arr[], int start, int end) {
    if (start > end) return NULL;

    int mid = start + (end - start) / 2;
    TreeNode* node = createNode(arr[mid]);

    node->left = sortedArrayToBST(arr, start, mid - 1);
    node->right = sortedArrayToBST(arr, mid + 1, end);

    return node;
}

TreeNode* rebalanceBST(TreeNode* root) {
    int n = countNodes(root);  // Assume countNodes() counts the number of nodes in the BST
    int* arr = (int*)malloc(n * sizeof(int));
    int index = 0;

    // Convert the BST to a sorted array
    BSTToArray(root, arr, &index);

    // Build a height-balanced BST from the sorted array
    TreeNode* newRoot = sortedArrayToBST(arr, 0, n - 1);

    free(arr);  // Don't forget to free the allocated memory
    return newRoot;
}

