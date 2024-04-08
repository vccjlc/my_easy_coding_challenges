/*

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

example:

Input: root = [3,2,3,null,3,null,1]
Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.


***

This problem, often referred to as the "House Robber III" problem, can be solved using a tree-based Dynamic Programming approach. The solution involves a post-order traversal of the binary tree while calculating two values for each node:

The maximum amount of money that can be robbed if the current node is not robbed.
The maximum amount of money that can be robbed if the current node is robbed.
For each node, there are two scenarios:

The node is robbed: the maximum money from this node will be the value of the node plus the maximum money from not robbing its left and right children.
The node is not robbed: the maximum money from this node will be the maximum of robbing or not robbing its left child, plus the maximum of robbing or not robbing its right child.
The maximum of these two amounts at the root will be the solution.

*/



// Function to calculate the maximum amount of money that can be robbed
void robHelper(TreeNode* node, int* withRob, int* withoutRob) {
    if (node == NULL) {
        *withRob = 0;
        *withoutRob = 0;
        return;
    }

    int leftWithRob, leftWithoutRob, rightWithRob, rightWithoutRob;
    
    // Post-order traversal to solve sub-problems first
    robHelper(node->left, &leftWithRob, &leftWithoutRob);
    robHelper(node->right, &rightWithRob, &rightWithoutRob);

    // If we rob this node, we cannot rob its children
    *withRob = node->val + leftWithoutRob + rightWithoutRob;

    // If we do not rob this node, we take the maximum of robbing or not robbing its children
    *withoutRob = fmax(leftWithRob, leftWithoutRob) + fmax(rightWithRob, rightWithoutRob);
}

// Main function to find the maximum amount of money the thief can rob
int rob(TreeNode* root) {
    int withRob, withoutRob;
    robHelper(root, &withRob, &withoutRob);
    return fmax(withRob, withoutRob);
}
