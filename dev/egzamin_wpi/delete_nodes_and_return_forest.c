/*

Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.


To solve this problem, you can perform a post-order traversal of the binary tree. During the traversal, you decide whether to delete a node by checking if its value is in the to_delete list. If a node needs to be deleted, you remove it from the tree by connecting its parent directly to its children (if any). The crucial part is handling the remaining subtrees (if a node is deleted) and adding them to the forest if they are not null.

Here's a step-by-step approach:

Convert to_delete to a more efficient search structure: Since you need to frequently check if a node's value is in to_delete, convert to_delete to a HashSet (or an equivalent fast-lookup data structure) to reduce the lookup time from O(n) to O(1).

Recursive Function: Implement a recursive function that performs a post-order traversal (process the children before the node itself). The function should return NULL if the current node is deleted, or the node itself if not. This way, the parent can connect to the correct children after deletions.

Handling Deletions: When you encounter a node that needs to be deleted, add its non-null children to the result forest before setting the link to them as NULL (effectively deleting the node).

Root Cases: If the root itself needs to be deleted, ensure you handle this case by not adding it back to the forest after deletion.


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

// Helper function to create a new tree node
struct TreeNode* newNode(int value) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to check if a value should be deleted
bool shouldDelete(int val, int* to_delete, int to_deleteSize) {
    for (int i = 0; i < to_deleteSize; i++) {
        if (val == to_delete[i]) {
            return true;
        }
    }
    return false;
}

// Recursive function to handle deletions and return new roots
struct TreeNode* deleteNodes(struct TreeNode* root, int* to_delete, int to_deleteSize, struct TreeNode*** forest, int* forestSize) {
    if (!root) return NULL;

    root->left = deleteNodes(root->left, to_delete, to_deleteSize, forest, forestSize);
    root->right = deleteNodes(root->right, to_delete, to_deleteSize, forest, forestSize);

    if (shouldDelete(root->val, to_delete, to_deleteSize)) {
        if (root->left) {
            (*forest)[*forestSize] = root->left;
            (*forestSize)++;
        }
        if (root->right) {
            (*forest)[*forestSize] = root->right;
            (*forestSize)++;
        }
        free(root); // Free the memory of the deleted node
        return NULL;
    }

    return root;
}

struct TreeNode** delNodes(struct TreeNode* root, int* to_delete, int to_deleteSize, int* returnSize) {
    *returnSize = 0;
    struct TreeNode** forest = (struct TreeNode**)malloc(1000 * sizeof(struct TreeNode*)); // Assuming a maximum of 1000 trees in the forest

    if (!shouldDelete(root->val, to_delete, to_deleteSize)) {
        forest[0] = root;
        (*returnSize)++;
    }

    deleteNodes(root, to_delete, to_deleteSize, &forest, returnSize);

    return forest;
}

// Example usage
int main() {
    // Construct a simple tree:
    //       1
    //      / \
    //     2   3
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    // Nodes to delete
    int to_delete[] = {2};
    int to_deleteSize = sizeof(to_delete) / sizeof(to_delete[0]);
    int returnSize;

    struct TreeNode** forest = delNodes(root, to_delete, to_deleteSize, &returnSize);

    // Print the roots of the trees in the forest
    for (int i = 0; i < returnSize; i++) {
        printf("Root of tree %d: %d\n", i + 1, forest[i]->val);
    }

    // Don't forget to free the allocated memory for the forest and tree nodes!
    // This is left as an exercise.

    return 0;
}

