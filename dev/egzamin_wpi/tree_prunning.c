/*

Given the root of a binary tree, return the same tree where every subtree (of the given tree) not containing a 1 has been removed.

A subtree of a node node is node plus every node that is a descendant of node.


To solve this problem, you can traverse the tree using post-order traversal (left-right-root). At each node, you decide whether to keep or remove the node based on the value of the node and the existence of the value 1 in its subtrees.


*/

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* pruneTree(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    // Recursively prune the left and right subtrees
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);

    // If the current node is a 0 node and has no children, or if both pruned
    // subtrees are NULL and the current node's value is not 1, prune it
    if (root->val == 0 && root->left == NULL && root->right == NULL) {
        free(root); // Assuming that free() is correctly handling NULL pointers
        return NULL;
    }

    // Return the possibly pruned subtree rooted at this node
    return root;
}

