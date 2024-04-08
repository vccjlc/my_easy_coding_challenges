#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode *left, *right;
} TreeNode;

// Helper function to find the distance from the current node to the target node
int findDistance(TreeNode* node, int target, int distance) {
    // Base case: if the tree is empty or we have found the target node
    if (node == NULL) return -1;
    if (node->value == target) return distance;

    // Recurse down to find the target in the left and right subtrees
    int leftDistance = findDistance(node->left, target, distance + 1);
    if (leftDistance != -1) return leftDistance; // Target found in left subtree

    int rightDistance = findDistance(node->right, target, distance + 1);
    if (rightDistance != -1) return rightDistance; // Target found in right subtree

    // Target not found in either subtree
    return -1;
}

// Wrapper function to call the helper with initial distance 0
int distanceFromAncestor(TreeNode* ancestor, int target) {
    return findDistance(ancestor, target, 0);
}

int main() {
    // Example tree construction
    TreeNode n1 = {1, NULL, NULL};
    TreeNode n2 = {2, NULL, NULL};
    TreeNode n3 = {3, &n1, &n2}; // n3 is parent of n1 and n2
    TreeNode n4 = {4, NULL, NULL};
    TreeNode n5 = {5, &n3, &n4}; // n5 is the root and parent of n3 and n4

    // Calculate distance from ancestor n3 to node n1
    int dist = distanceFromAncestor(&n3, 1); // Should return 1
    if (dist != -1) {
        printf("Distance from ancestor to node is %d\n", dist);
    } else {
        printf("Node not found in the subtree of the given ancestor.\n");
    }

    return 0;
}

