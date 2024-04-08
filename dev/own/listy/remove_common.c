// MERGE TWO SORTED LISTS INTO THIRD ONE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the node structure
// The structure below represents each node in a linked list

typedef struct node {
    int data;
    struct node *next;
} node;

/* Equivalent way to define the node structure:

struct node {
      int data;
      struct node* next;
 }
 typedef struct node node;

*/
// Check if lists are equal

node *create_node(int data) {
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode != NULL) { // Check if memory allocation was successful
        newnode->data = data;
        newnode->next = NULL;
    }
    return newnode; // returns NULL if allocation failed, otherwise a pointer to
                    // a node
}

void append_node(node **head, int data) {
    node *newnode = create_node(data);
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    node *last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newnode;
}

void remove_common(node *list1, node *list2) {
    if (!list2) {
    } else {
        node *current1 = list1;
        node *current2 = list2;

        while (current1 != NULL && current2 != NULL) {
            if (current1->data == current2->data) {
                node* temp = current1->next;
                current1-next = temp->next;
            } else {
                while (current2 != NULL && current2->data < current1->data) {
                    current2 = current2->next;
                }
                if (current1->data == current2->data) {
               		 node* temp = current1->next;
               		 current1-next = temp->next;
                } else {
                    current1 = current1->next;
                }
            }
        }
    }
}

void remove_common(node **list1, node *list2) {
    // Check if either list is empty; if so, return as there's nothing to do
    if (!*list1 || !list2) return;

    // Initialize pointers for traversal
    node *current1 = *list1, *prev1 = NULL, *temp;
    node *current2 = list2;

    // Traverse through list1
    while (current1 != NULL) {
        // Find the first element in list2 that is not smaller than current1
        while (current2 != NULL && current2->data < current1->data) { 
            current2 = current2->next;
        }

        // If current2 is NULL or its data is greater than current1's data
        // then current1's data is not in list2; move to the next node in list1
        if (current2 == NULL || current2->data > current1->data) {
            prev1 = current1;
            current1 = current1->next;
        } else { 
            // If elements are equal, remove current1 from list1
            temp = current1; // Store the node to be removed
            current1 = current1->next; // Advance current1

            // Re-link previous node to the next node, effectively removing current node
            if (prev1) {
                prev1->next = current1;
            } else {
                // If removing the head, update the head pointer of list1
                *list1 = current1;
            }

            // Free the memory of the removed node if dynamically allocated
            free(temp); 
        }
    }
}




        void print_list(node * head) {
            while (head != NULL) {
                printf("%d->", head->data);
                head = head->next;
            }
            printf("NULL\n");
        }

        // Simple main
        int main(void) {
            int my_array[] = {0, 5, 10, 15, 20, 25, 30, 35};
            node *head = NULL;

            for (int i = 0; i < sizeof(my_array) / sizeof(my_array[0]); ++i) {
                append_node(&head, my_array[i]);
            }

            int my_array2[] = {1, 2, 3, 4, 5};
            node *head2 = NULL;

            for (int i = 0; i < sizeof(my_array2) / sizeof(my_array2[0]); ++i) {
                append_node(&head2, my_array2[i]);
            }

            print_list(head);
            printf("\n");
            print_list(head2);
            printf("\n");

	    remove_common(head, head2);

            print_list(head);
            printf("\n");
            print_list(head2);
            printf("\n");

            return 0;
        }
