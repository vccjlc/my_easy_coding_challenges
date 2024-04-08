/*

Given a binary tree root and a linked list with head as the first node. 

Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.

In this context downward path means a path that starts at some node and goes downwards.

***

To determine if all the elements in the linked list correspond to some downward path in the binary tree, you can use a recursive depth-first search (DFS) approach. Starting from the root of the binary tree, you compare the value of the current tree node with the current linked list node. If they match, you continue the search to the left and right child of the tree with the next node in the linked list. The search is successful if you reach the end of the linked list while traversing the tree.

*/


#include <stdbool.h>  // For using 'true' and 'false'

// Recursive helper function to check if the linked list corresponds to a downward path from the given tree node
bool dfs(TreeNode* root, ListNode* head) {
    // If the linked list is fully traversed, return true
    if (head == NULL) return true;
    
    // If the tree is fully traversed but linked list is not, return false
    if (root == NULL) return false;

    // If the current nodes do not match, return false
    if (root->val != head->val) return false;

    // Continue the search with the next linked list node and the left or right child of the tree
    return dfs(root->left, head->next) || dfs(root->right, head->next);
}

// Main function to check if the linked list corresponds to a downward path in the binary tree
bool isSubPath(ListNode* head, TreeNode* root) {
    // If the linked list is null, it's trivially a subpath
    if (head == NULL) return true;

    // If the tree is null, the linked list can't be a subpath
    if (root == NULL) return false;

    // Check if the linked list corresponds to a downward path from the current tree node or any of its children
    return dfs(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
}



