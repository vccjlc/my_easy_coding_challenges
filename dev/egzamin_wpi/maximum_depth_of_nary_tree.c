// RETURN MAXIMUM DEPTH OF NARY TREE

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

int max(int a, int b) {
    return a > b ? a : b;
}
int maxDepth(struct Node* root) {
    if (!root) return 0;

    int max_depth = 0;

    for (int i = 0; i < root->numChildren; ++i) {
        int child_depth = maxDepth(root->children[i]);
        max_depth = max(max_depth, child_depth);
    }

    return max_depth + 1;
}
