// FIND INORDER SUCCESSOR OF A GIVEN NODE

struct TreeNode* findLeftMostNode(struct TreeNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

struct TreeNode* findInorderSuccessor(struct TreeNode* root, struct TreeNode* p) {
    if (p->right != NULL) {
        // The successor is the leftmost child of the right subtree
        return findLeftMostNode(p->right);
    }

    // When there's no right subtree, move up to the closest ancestor
    // for which the given node is in the left subtree
    struct TreeNode* successor = NULL;
    struct TreeNode* current = root;
    while (current != NULL) {
        if (p->val < current->val) {
            successor = current;  // Potential successor
            current = current->left;
        } else if (p->val > current->val) {
            current = current->right;
        } else {
            break;
        }
    }
    return successor;
}

