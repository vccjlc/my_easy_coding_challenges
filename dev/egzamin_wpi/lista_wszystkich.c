#include <stdio.h>
#include <stdlib.h>

Node* createNode(int value);
Node* insertNode(Node* root, int value);
ListNode* createListNode(int value);
void appendToList(ListNode** head, int value);



// Functions to merge two BSTs into a list (without repetitions)


ListNode* Insert_at_position(ListNode** head, ListNode* start, int value) {
    ListNode* current_node = start ? start : *head;
    ListNode* previous_node = NULL;

    // If starting node is not the head, set previous node correctly
    if (start && start != *head) {
        previous_node = start;
    }

    // Allocate a new node for insertion
    ListNode* inserted_node = createListNode(value);

    // Handle insertion at the beginning or before the start node
    if (current_node == *head && (!current_node || current_node->value >= value)) {
        if (current_node && current_node->value == value) {
            // If the first node is a duplicate, free the new node and return the current node
            free(inserted_node);
            return current_node;
        }
        inserted_node->next = current_node;
        *head = inserted_node;
        return inserted_node;
    }

    // Traverse the list from the start node to find the insertion point
    while (current_node && current_node->value < value) {
        previous_node = current_node;
        current_node = current_node->next;
    }

    // Check for duplicates
    if (current_node && current_node->value == value) {
        // If it's a duplicate, free the new node and return the current node
        free(inserted_node);
        return current_node;
    }

    // Insert the new node at the correct position
    inserted_node->next = current_node;
    if (previous_node) {
        previous_node->next = inserted_node;
    }

    return inserted_node; // Return the inserted node
}

// Function to perform in-order traversal and append values to the list
void inorderTraversal(Node* root, ListNode** listHead) {
    if (root != NULL) {
        inorderTraversal(root->left, listHead); // Visit the left subtree
        appendToList(listHead, root->value); // Append the node's value to the list
        inorderTraversal(root->right, listHead); // Visit the right subtree
    }
}

void inorderTraversal2(Node* root, ListNode** listHead, ListNode** lastInserted) {
    if (root != NULL) {
        inorderTraversal2(root->left, listHead, lastInserted); // Visit the left subtree
        *lastInserted = Insert_at_position(listHead, *lastInserted, root->value); // Insert the node's value into the list
        inorderTraversal2(root->right, listHead, lastInserted); // Visit the right subtree
    }
}

// Function to print the list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}


























































// Define the structure for a BST node
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new BST node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Failed to allocate memory for a new BST node");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
Node* insertNode(Node* root, int value) {
    if (root == NULL) { // Base case: The tree is empty or we've reached an empty spot
        return createNode(value);
    }

    if (value < root->value) { // Value is less than the root, go to the left subtree
        root->left = insertNode(root->left, value);
    } else if (value > root->value) { // Value is greater than the root, go to the right subtree
        root->right = insertNode(root->right, value);
    }

    return root; // Return the (unchanged) root pointer
}

// Define the structure for a list node
typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;

// Function to create a new list node
ListNode* createListNode(int value) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        perror("Failed to allocate memory for a new list node");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to append a value to the list
void appendToList(ListNode** head, int value) {
    ListNode* newNode = createListNode(value);
    if (*head == NULL) {
        *head = newNode; // The list was empty, new node is now the head
    } else {
        ListNode* current = *head;
        while (current->next != NULL) { // Traverse to the end of the list
            current = current->next;
        }
        current->next = newNode; // Append the new node at the end
    }
}


int main() {
    Node* root1 = NULL; // First BST
    Node* root2 = NULL; // Second BST
    ListNode* listHead = NULL; // Initialize the list head
    ListNode* lastInserted = NULL; // Pointer to track the last inserted node in the list

    // Insert nodes into the first BST
    root1 = insertNode(root1, 5);
    insertNode(root1, 3);
    insertNode(root1, 2);
    insertNode(root1, 4);
    insertNode(root1, 7);
    insertNode(root1, 6);
    insertNode(root1, 8);

    // Perform in-order traversal on the first BST and append all nodes to the list
    inorderTraversal(root1, &listHead);

    // Insert nodes into the second BST
    root2 = insertNode(root2, 10);
    insertNode(root2, 5); // This might be a duplicate from the first BST
    insertNode(root2, 1); // This is unique and should be added to the list
    insertNode(root2, 7); // This might be a duplicate from the first BST
    insertNode(root2, 12); // This is unique and should be added to the list

    // Perform in-order traversal on the second BST and insert only non-repeating values into the list
    inorderTraversal2(root2, &listHead, &lastInserted);

    // Print the final list
    printf("Final sorted list (after merging two BSTs without duplicates): ");
    printList(listHead);

    // Free the BSTs and the list (omitted for brevity, should be implemented)

    return 0;
}


