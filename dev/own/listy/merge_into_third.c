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

// Undestructive merge
node *merge_increasing_into_third(node *head1, node *head2) {
    node *head3 = NULL;
    
    if (!list1) return list2;
    if (!list2) return list1;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            append_node(&head3, head1->data);
            head1 = head1->next;
        } else {
            append_node(&head3, head2->data);
            head2 = head2->next;
        }
    }

    // Append remaining nodes of head1 or head2
    while (head1 != NULL) {
        append_node(&head3, head1->data);
        head1 = head1->next;
    }
    while (head2 != NULL) {
        append_node(&head3, head2->data);
        head2 = head2->next;
    }

    return head3;
}



void print_list(node *head) {
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

    node *head3 = NULL;
    head3 = merge_increasing(head, head2);
    print_list(head3);

    return 0;
}
