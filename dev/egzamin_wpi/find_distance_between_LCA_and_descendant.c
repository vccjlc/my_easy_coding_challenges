// Function to find the distance from the LCA to a given subnode
int findDistanceFromLCAToSubnode(TreeNode* lca, TreeNode* subnode) {
    if (lca == NULL) return -1; // Base case: LCA is NULL
    if (lca == subnode) return 0; // Base case: Found the subnode, distance is 0

    // Recursively search for the subnode in the left and right subtrees
    int leftDistance = findDistanceFromLCAToSubnode(lca->left, subnode);
    int rightDistance = findDistanceFromLCAToSubnode(lca->right, subnode);

    // If the subnode is found in either subtree, increment the distance
    if (leftDistance != -1) return leftDistance + 1;
    if (rightDistance != -1) return rightDistance + 1;

    // If the subnode is not found in either subtree, return -1
    return -1;
}
