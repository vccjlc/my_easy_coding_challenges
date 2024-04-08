#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function prototypes
void convertBSTToSortedSinglyLinkedList(TreeNode* root, TreeNode** prev, TreeNode** head);

// Main conversion function
void convertBSTToSortedSinglyLinkedList(TreeNode* root, TreeNode** prev, TreeNode** head) {
    if (root == NULL) return;

    // Convert the left subtree
    convertBSTToSortedSinglyLinkedList(root->left, prev, head);

    // Current node's left will be NULL, and right will act as next
    root->left = NULL;
    if (*prev) {
        // Link the previous node's next to the current node
        (*prev)->right = root;
    } else {
        // This is the leftmost node, set it as the head of the list
        *head = root;
    }
    *prev = root; // Update the prev pointer

    // Convert the right subtree
    convertBSTToSortedSinglyLinkedList(root->right, prev, head);
}

// Helper function to create a new TreeNode
TreeNode* createTreeNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to initiate the conversion process
TreeNode* bstToSinglyLinkedList(TreeNode* root) {
    TreeNode* prev = NULL;
    TreeNode* head = NULL;
    convertBSTToSortedSinglyLinkedList(root, &prev, &head);
    return head;
}

int main() {
    // Example usage:
    TreeNode* root = createTreeNode(4);
    root->left = createTreeNode(2);
    root->right = createTreeNode(5);
    root->left->left = createTreeNode(1);
    root->left->right = createTreeNode(3);

    TreeNode* listHead = bstToSinglyLinkedList(root);

    // Output the values in the list
    TreeNode* current = listHead;
    while (current != NULL) {
        printf("%d ", current->val);
        TreeNode* temp = current;
        current = current->right; // Move to the next node in the list
        free(temp); // Optionally, free the node
    }

    // Since we are reusing the tree nodes as list nodes, no new memory is allocated for list nodes.
    // If the original tree nodes need to be preserved, you should create new nodes for the list.

    return 0;
}

