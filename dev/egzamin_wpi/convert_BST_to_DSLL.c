#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct DoublyLinkedListNode {
    int val;
    struct DoublyLinkedListNode *prev;
    struct DoublyLinkedListNode *next;
} DoublyLinkedListNode;

// Helper function to create a new DoublyLinkedListNode
DoublyLinkedListNode* createDoublyLinkedListNode(int value) {
    DoublyLinkedListNode* newNode = (DoublyLinkedListNode*)malloc(sizeof(DoublyLinkedListNode));
    newNode->val = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// The function to convert BST to sorted doubly linked list.
void convertBSTToSortedDoublyLinkedList(TreeNode* root, DoublyLinkedListNode** head, DoublyLinkedListNode** tail) {
    if (root == NULL) return;

    // Convert the left subtree and link to root
    if (root->left) {
        convertBSTToSortedDoublyLinkedList(root->left, head, tail);
        (*tail)->next = createDoublyLinkedListNode(root->val);
        (*tail)->next->prev = *tail;
        *tail = (*tail)->next;
    } else if (*tail == NULL) { // First node to be added (smallest element)
        *head = *tail = createDoublyLinkedListNode(root->val);
    }

    // Convert the right subtree and link to root
    if (root->right) {
        if (*tail != NULL && (*tail)->val != root->val) {
            (*tail)->next = createDoublyLinkedListNode(root->val);
            (*tail)->next->prev = *tail;
            *tail = (*tail)->next;
        }
        convertBSTToSortedDoublyLinkedList(root->right, head, tail);
    } else if (*tail != NULL && (*tail)->val != root->val) { // Last node to be added (largest element)
        (*tail)->next = createDoublyLinkedListNode(root->val);
        (*tail)->next->prev = *tail;
        *tail = (*tail)->next;
    }
}

int main() {
    // Assume createTreeNode function is given and the tree is created.

    TreeNode* root = /* Assume this is the BST root. */;
    DoublyLinkedListNode* head = NULL;
    DoublyLinkedListNode* tail = NULL;

    convertBSTToSortedDoublyLinkedList(root, &head, &tail);

    // The 'head' now points to the first node of the sorted doubly linked list.
    // You can traverse and print the list to verify it.

    // Don't forget to free the memory of both the BST and the doubly linked list.

    return 0;
}

