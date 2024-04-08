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

node *merge_increasing_into_one(node *list1, node *list2) {
    node *mergedHead = NULL, **tail = &mergedHead;

    while (list1 && list2) {
        if (list1->data < list2->data) {
            *tail = list1;
            list1 = list1->next;
        } else {
            *tail = list2;
            list2 = list2->next;
        }
        tail = &(*tail)->next;
    }

    *tail = (list1 ? list1 : list2);

    return mergedHead;
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

    node *mergedHead = merge_increasing_into_one(head, head2);
    print_list(mergedHead);

    printf("\n");

    return 0;
}
