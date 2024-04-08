/*

Given two binary trees original and cloned and given a reference to a node target in the original tree.

The cloned tree is a copy of the original tree.

Return a reference to the same node in the cloned tree.

Note that you are not allowed to change any of the two trees or the target node and the answer must be a reference to a node in the cloned tree.


The reason the function getTargetCopy directly returns the result of the recursive call on the right side, but first checks the result from the left side before deciding to proceed to the right side, is based on how binary tree traversal works and the logic to avoid unnecessary operations.

When the function getTargetCopy is called recursively for the left subtree (original->left and cloned->left), there are three possible outcomes:

The target node is found in the left subtree. In this case, leftResult will be a non-NULL pointer to the corresponding node in the cloned tree. Since we've found the target, there's no need to search the right subtree. Therefore, the function returns leftResult immediately.

The target node is not in the left subtree, and leftResult is NULL. Only in this case does the function proceed to search the right subtree. This is an optimization to avoid unnecessary recursive calls: if the target is already found in the left subtree, we don't need to search the right subtree.

The left subtree is empty (original->left is NULL), so the function returns NULL immediately, and then the search proceeds to the right subtree.

For the right subtree, the function directly returns the result of the recursive call because:

If the target was not found in the left subtree (indicated by leftResult being NULL), we must search the right subtree.
If the target is found in the right subtree, this recursive call will return a non-NULL pointer to the corresponding node in the cloned tree, which is then returned by the function.
If the target is not found in the right subtree either, the function will return NULL, indicating that the target node does not exist in the tree (or was not properly identified).



*/


TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    // Base case: If the current node in the original tree is NULL, return NULL
    if (original == NULL) {
        return NULL;
    }
    
    // If the current node in the original tree is the target, return the corresponding node in the cloned tree
    if (original == target) {
        return cloned;
    }
    
    // Recursively search in the left subtree
    TreeNode* leftResult = getTargetCopy(original->left, cloned->left, target);
    if (leftResult != NULL) {
        return leftResult; // If the target is found in the left subtree, return the result
    }
    
    // Recursively search in the right subtree
    return getTargetCopy(original->right, cloned->right, target);
    // If the target is not found in the left subtree, the result from the right subtree is returned (could be NULL or the target node)
}

