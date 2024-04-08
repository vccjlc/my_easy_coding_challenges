/*


You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins in total throughout the whole tree.

In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.

Return the minimum number of moves required to make every node have exactly one coin.


To solve this problem, you can use a recursive depth-first search (DFS) approach. The key insight is to understand that the number of moves required for a node is the absolute value of the number of coins it needs or has in excess. A node needs 1 coin for itself, and any excess or deficiency of coins must be moved to or from its parent.

For each node, you can calculate the balance as node.val - 1 (since each node needs to keep 1 coin for itself) and then add the balances of its left and right children. A positive balance indicates excess coins that need to be moved up to the parent, while a negative balance indicates a deficit that needs to be filled by moving coins from the parent down to this node. The total number of moves is the sum of the absolute values of the balances of all nodes.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new tree node
TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Recursive function to calculate the balance of coins and accumulate the total moves
int distributeCoinsDFS(TreeNode* node, int* moves) {
    if (!node) return 0;

    // Get the balance from left and right subtrees
    int leftBalance = distributeCoinsDFS(node->left, moves);
    int rightBalance = distributeCoinsDFS(node->right, moves);

    // Current node's balance: coins - 1 (+ve if excess, -ve if deficit)
    int balance = node->val + leftBalance + rightBalance - 1;

    // Accumulate the absolute balance to moves (since each move can only transfer 1 coin)
    *moves += abs(balance);

    return balance;  // Return the balance to the parent
}

// Main function to find the minimum number of moves to balance the coins
int distributeCoins(TreeNode* root) {
    int moves = 0;
    distributeCoinsDFS(root, &moves);
    return moves;
}

// Example usage
int main() {
    // Construct the binary tree here...
    // TreeNode* root = ...

    int result = distributeCoins(root);
    printf("Minimum number of moves required: %d\n", result);

    // Remember to free the allocated memory for the tree nodes after usage (not shown here)

    return 0;
}

