// Assuming findLCA and distanceFromAncestor are already implemented

int findDistanceBetweenNodes(TreeNode* root, TreeNode* p, TreeNode* q) {
    // Find the Lowest Common Ancestor of nodes p and q
    TreeNode* LCA = findLCA(root, p, q);

    // Find the distance from the LCA to node p
    int dist1 = distanceFromAncestor(LCA, p->value); // Assuming distanceFromAncestor accepts the value of the target node

    // Find the distance from the LCA to node q
    int dist2 = distanceFromAncestor(LCA, q->value); // Same assumption as above

    // The total distance between nodes p and q is the sum of dist1 and dist2
    int result = dist1 + dist2;

    return result;
}

