#include <stdio.h>
#include <stdlib.h>

// Definition for an n-ary tree node.
struct NaryTreeNode {
    int val;
    int numChildren;
    struct NaryTreeNode** children;
};

// Helper function for n-ary tree to recursively find leaves.
void findLeavesOfNaryTree(struct NaryTreeNode* node, int* leaves, int* count) {
    if (node == NULL) return;

    if (node->numChildren == 0) { // Leaf node
        leaves[(*count)++] = node->val; // Add leaf value to array and increment count
    } else {
        for (int i = 0; i < node->numChildren; ++i) {
            findLeavesOfNaryTree(node->children[i], leaves, count);
        }
    }
}

// Function to copy all leaves of an n-ary tree to an array.
int* copyLeavesNaryTree(struct NaryTreeNode* root, int* returnSize) {
    int* leaves = (int*)malloc(1000 * sizeof(int)); // Allocate memory for leaves array
    *returnSize = 0; // Initialize return size
    findLeavesOfNaryTree(root, leaves, returnSize);
    return leaves;
}

