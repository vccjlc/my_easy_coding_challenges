#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;


// We look if any list (in the array of singly linked lists ending with NULL) is the full sublist of another
node *create_node(int data) {
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode != NULL) {
        newnode->data = data;
        newnode->next = NULL;
    }
    return newnode;
}

void free_inserted_nodes(node* A[], int n) {
    for (int i = 0; i < n; ++i) {
        if (A[i] != NULL && A[i]->next != NULL) {
            // Assuming the second node is the inserted dummy node
            node* dummy = A[i]->next;
            A[i]->next = dummy->next;  // Bypass the dummy node
            free(dummy);  // Free the dummy node
        }
    }
}

bool podlista(node* A[], int n) {
    if (n <= 1) {
        return false;
    }

    // Insert dummy value after each first node
    for (int i = 0; i < n; ++i) {
        node* temp = A[i]->next;
        node* nowy = create_node(INT_MAX);
        if (nowy != NULL) {
            nowy->next = temp;
            A[i]->next = nowy;
        }
    }

    for (int i = 0; i < n; ++i) {
        node *last = A[i];
        int licznik = 0;
        while (last != NULL && last->next != NULL) {
            last = last->next;
            if (last->data == INT_MAX) {
                licznik++;
                if (licznik == 2) {
                    free_inserted_nodes(A, n);
                    return true;
                }
            }
        }
    }

    free_inserted_nodes(A, n);
    return false;
}

int main(void) {
    // Example usage and list initialization would go here
    return 0;
}

