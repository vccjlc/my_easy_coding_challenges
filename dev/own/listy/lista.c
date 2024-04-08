#include <stdio.h>
#include <stdlib.h>

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

node *create_node(int data) {
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode != NULL) { // Check if memory allocation was successful
        newnode->data = data;
        newnode->next = NULL;
    }
    return newnode; // returns NULL if allocation failed, otherwise a pointer to
                    // a node
}

// Function to add note to the end of a list
/* Why node **head?: The reason for using a double pointer (node **head) is to
 * be able to modify the head pointer itself if necessary. Remember, in C,
 * function arguments are passed by value, meaning a copy of the argument is
 * passed to the function. If you pass the head pointer as a single pointer
 * (node *head), you'll only have a copy of the head pointer, and changes made
 * to this copy won't affect the original head pointer outside the function.
 */

// head is the first arrow, pointer that indicates where the first “cell” is.
// For empty list, it points to nowhere (is NULL)
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

void print_list(node *head) {
    while (head != NULL) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Repeat this function to learn
void delete_node(node **head, int key) {
    // Find the node with the given key and its previous node...
    // Assuming `to_delete` is the node to be deleted
    // and `prev` is the node before it

    if (to_delete != NULL) {
        if (prev != NULL) prev->next = to_delete->next;
        else *head = to_delete->next;

        free(to_delete); // Free the memory of the node to be deleted
    }
}

// Repeat this function to learn
void free_list(node **head) {
    node *current = *head;
    node *temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp); // Free each node
    }

    *head = NULL; // Set the head to NULL after freeing the list
}


int main(void) {
    int my_array[] = {0, 5, 10, 15, 20, 25, 3, 4};
    node *head = NULL;

    for (int i = 0; i < sizeof(my_array) / sizeof(my_array[0]); ++i) {
        append_node(&head, my_array[i]);
    }

    print_list(head);

    return 0;
}
