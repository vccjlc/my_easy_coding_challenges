/*

Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.


*/

void inorder(struct TreeNode** ans, struct TreeNode* root) {
    if (!root) return;

    inorder(ans, root->left);

    (*ans)->right = (struct TreeNode*)malloc(sizeof(struct TreeNode)); // Allocate memory for the new node
    if (!(*ans)->right) { // Check if malloc was successful
        // Handle memory allocation failure (e.g., by returning or setting an error code)
        return;
    }

    (*ans)->right->val = root->val; // Set the value of the new node
    (*ans)->right->left = NULL; // Ensure the left child is NULL
    (*ans)->right->right = NULL; // Ensure the right child is also NULL
    *ans = (*ans)->right; // Move the pointer to the right

    inorder(ans, root->right);
}


struct TreeNode* increasingBST(struct TreeNode* root) {
    struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (!temp) { // Check if malloc was successful
        // Handle memory allocation failure
        return NULL;
    }
    temp->left = NULL; // Initialize left child of the dummy node
    temp->right = NULL; // Initialize right child of the dummy node

    struct TreeNode* ans = temp; // 'ans' is used to build the new tree, 'temp' will be used to return the result

    inorder(&ans, root);

    struct TreeNode* newRoot = temp->right; // The first node is a dummy, so we return its right child
    free(temp); // Free the dummy node
    return newRoot;
}

