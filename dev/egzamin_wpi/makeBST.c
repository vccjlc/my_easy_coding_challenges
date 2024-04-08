//Two functions to assign values from 1 to n in a binary tree of n nodes so that we will have a BST

void assignValues(struct TreeNode* node, int* counter) {
    if (node == NULL) return;

    // Traverse the left subtree
    assignValues(node->left, counter);

    // Assign value to the current node
    node->value = *counter;
    (*counter)++; // Increment the counter

    // Traverse the right subtree
    assignValues(node->right, counter);
}


void makeBST(struct TreeNode* root) {
    int startValue = 1;
    assignValues(root, &startValue);
}

