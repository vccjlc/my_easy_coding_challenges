#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int x;
    struct Node* next;
} Node;

void insert_end(Node ** root, int value) {
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        exit(1);
    }
    new_node->next = NULL;
    new_node->x = value;

    if (*root == NULL) {  // If the list is empty, set the new node as root
        *root = new_node;
        return;
    }

    Node* curr = *root;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
}

int main(int argc, char* argv[]) {
    Node* root = NULL;  // Initialize root to NULL to signify empty list

    insert_end(&root, 15);
    insert_end(&root, -2);
    insert_end(&root, 11);

    Node* curr = root;  // Declare and initialize curr to the start of the list
    while (curr != NULL) {
        printf("%d\n", curr->x);
        curr = curr->next;
    }

    // Freeing the allocated nodes
    curr = root;  // Reset curr to the start of the list
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }

    return 0;
}

