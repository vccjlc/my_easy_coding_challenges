/*

The diameter of a binary tree is the length of the longest path between any two nodes in the tree. This path may or may not pass through the root. To find the diameter, we can use a depth-first search (DFS) approach, where at each node, we calculate:

The height of the left subtree.
The height of the right subtree.
The path through the current node, which is the sum of the heights of the left and right subtrees plus 1 (for the current node).
The diameter at each node is the maximum of:

The diameter of the left subtree.
The diameter of the right subtree.
The longest path through the current node (left height + right height + 1).
We update the global maximum diameter at each node with the maximum of the current global maximum and the longest path through the current node.


*/


int diameterOfBinaryTreeUtil(TreeNode* root, int* diameter) {
    if (root == NULL) return 0;

    // Get heights of left and right subtrees
    int leftHeight = diameterOfBinaryTreeUtil(root->left, diameter);
    int rightHeight = diameterOfBinaryTreeUtil(root->right, diameter);

    // Update the diameter if the path through the root is larger
    *diameter = max(*diameter, leftHeight + rightHeight);

    // Return height of the current subtree
    return 1 + max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;  // Initialize diameter
    diameterOfBinaryTreeUtil(root, &diameter);
    return diameter;
}

