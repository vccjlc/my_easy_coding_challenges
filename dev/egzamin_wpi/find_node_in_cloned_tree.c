/*

Given two binary trees original and cloned and given a reference to a node target in the original tree.

The cloned tree is a copy of the original tree.

Return a reference to the same node in the cloned tree.

Note that you are not allowed to change any of the two trees or the target node and the answer must be a reference to a node in the cloned tree.


***

To find a reference to the same node in the cloned tree as the target node in the original tree, you can traverse both trees simultaneously in a synchronized manner. Since the cloned tree is an exact copy of the original tree, corresponding nodes in both trees will be encountered at the same point during the traversal. When you find the target node in the original tree, you can return the corresponding node from the cloned tree.

*/


#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to traverse both trees simultaneously
TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    if (original == NULL || original == target) {
        return cloned;
    }

    TreeNode* leftResult = getTargetCopy(original->left, cloned->left, target);
    if (leftResult != NULL) {
        return leftResult;
    }

    return getTargetCopy(original->right, cloned->right, target);
}

// Example usage
int main() {
    // Assume original and cloned trees are constructed here
    // and 'target' is a reference to a node in the original tree

    TreeNode* result = getTargetCopy(original, cloned, target);
    // 'result' is now a reference to the same node in the cloned tree

    return 0;
}

