// SIMPLE MERGE

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

// Alternating simple merge (assume equal length)
node *simple_merge(node *list1, node *list2) {
    if (!list1 || !list2) return NULL; // If either list is empty, return NULL

    node *merge_head = list2; // Assuming we start with list2's first node
    node *temp1 = NULL;
    node *temp2 = NULL;

    while (list1 && list2) {
        temp2 = list2->next; // Save the next node of list2
        temp1 = list1->next; // Save the next node of list1

        list2->next = list1; // Point current node of list2 to current node of list1
        if (temp2) { // If there is a next node in list2
            list1->next = temp2; // Point current node of list1 to next node of list2
        }

        list2 = temp2; // Move to the next node in list2
        list1 = temp1; // Move to the next node in list1
    }

    return merge_head; // Return the head of the merged list
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
