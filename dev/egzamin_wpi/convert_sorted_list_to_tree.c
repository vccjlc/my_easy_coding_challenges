// convert sorted list to BST


#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
} TreeNode;

// Function to create a new TreeNode
TreeNode* createTreeNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find the middle element of the linked list and split it into two halves
ListNode* findMiddleAndSplit(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev != NULL) prev->next = NULL;  // Split the list into two halves
    return slow;  // Middle element
}

// Main function to convert the sorted linked list to a height-balanced BST
TreeNode* sortedListToBST(ListNode* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) return createTreeNode(head->val);  // Base case: single node

    // Find the middle element of the list and split the list into two halves
    ListNode* mid = findMiddleAndSplit(head);

    // The middle element becomes the root
    TreeNode* root = createTreeNode(mid->val);

    // Recursively construct the left and right subtrees
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(mid->next);

    return root;
}

