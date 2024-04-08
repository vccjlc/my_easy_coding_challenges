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

// Display the list
void print_list(node *head) {
    while (head != NULL) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
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

int find_index(node *head, int element) {
    int index = 0;
    int found = 0; // Flag to indicate if the element is found

    while (head != NULL && !found) {
        if (head->data == element) {
            found = 1; // Element found, set the flag and exit the loop
        } else {
            index++;           // Increment index only if element not found
            head = head->next; // Move to the next node
        }
    }

    if (found) {
        return index; // Return the index if element was found
    } else {
        return -1; // Element not found, return -1
    }
}

// Delete first node with a given data
void delete_node(node **head, int data_to_delete) {
    if (*head == NULL) {
        return; // List is empty
    }

    node *temp = *head, *prev = NULL;

    // Check if head node itself holds the data to be deleted
    if (temp != NULL && temp->data == data_to_delete) {
        *head = temp->next; // Changed head
        free(temp);         // Free old head
        return;
    }

    // Search for the data to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != data_to_delete) {
        prev = temp;
        temp = temp->next;
    }

    // If data was not present in linked list
    if (temp == NULL) {
        return;
    }

    prev->next = temp->next; // Unlink the node from linked list
    free(temp);              // Free memory
}

// Delete all nodes with a given data
void delete_nodes(node **head, int data_to_delete) {
    if (*head == NULL) {
        return; // List is empty
    }

    node *temp = *head;
    node *prev = NULL;

    // Check and delete head nodes
    while (temp != NULL && temp->data == data_to_delete) {
        *head = temp->next; // Change head
        free(temp);         // Free old head
        temp = *head;       // Update temp to the new head
    }

    // Traverse the list starting from the new head
    while (temp != NULL) {
        if (temp->data == data_to_delete) {
            // Node found, remove it
            prev->next = temp->next;
            free(temp);
            temp = prev->next; // Continue from the next node
        } else {
            // Move to the next node
            prev = temp;
            temp = temp->next;
        }
    }
}

// Delete node under a given index
void delete_at_index(node **head, int index_to_delete) {
    if (*head == NULL || index_to_delete < 0) {
        return; // List is empty or index is invalid
    }

    node *temp = *head, *prev = NULL;
    int current_index = 0;

    // Check if the first node (head) is to be deleted
    if (index_to_delete == 0) {
        *head = temp->next; // Change head to the next node
        free(temp);         // Free the old head
        return;
    }

    // Traverse the list to find the node at the given index
    while (temp != NULL && current_index != index_to_delete) {
        prev = temp;
        temp = temp->next;
        current_index++;
    }

    // If the index is beyond the end of the list
    if (temp == NULL) {
        return;
    }

    // Unlink the node from the linked list and free memory
    prev->next = temp->next;
    free(temp);
}

void reverse_list(node **head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    // prev should be set to NULL because the first node in the
    // reversed list will have its next set to NULL
    node *prev = NULL; 
    node *current = *head;
    node *next = *head;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    // At the end of the while loop, current will be NULL
    *head = prev; // assign *head to prev instead of current to point to the new
                  // head of the list.
}


void reverse_first_n_nodes(node **head, int n) {
    if (*head == NULL || n <= 0) {
        return; // List is empty or no need to reverse
    }

    node *current = *head;
    node *prev = NULL, *next = NULL;
    int count = 0;

    // Reverse the first n nodes of the linked list
    while (current != NULL && count < n) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // Now next points to (n+1)th node
    // If n was greater than or equal to length of list, no need to attach
    if (next != NULL) {
        (*head)->next = next;
    }

    *head = prev; // prev is now the new head of the reversed list
}


// Push node (insert at the beginning)
void insert_first(node **head, int data) {
    node *node_to_insert =
        create_node(data);        // Assuming create_node returns a node*
    node_to_insert->next = *head; // Set the new node's next to the current head
    *head = node_to_insert;       // Update head to point to the new node
}

// Get the address of the last node in the list
node *get_last_node(node *head) {
    if (head == NULL) {
        return NULL; // Return NULL if the list is empty
    }

    node *last_node = head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    return last_node; // Return the last node in the list
}

// Point last node to the first, which will make a full cycle
void make_list_cyclic(node **head) {
    if (*head == NULL) {
        return; // Return if the list is empty
    }

    node *last_node = get_last_node(*head); // Pass the dereferenced head
    if (last_node != NULL) {
        last_node->next =
            *head; // Connect the last node to the head of the list
    }
}

// Boolean determine if cyclic
int check_if_cyclic(node *list) {
    node *slow_p = list, *fast_p = list;

    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            return 1;
        }
    }
    return 0;
}

// Find cycle entry point
node *detect_cycle(node *list) {
    node *slow_p = list, *fast_p = list;

    // Detecting the cycle
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            // Cycle detected, now find the entry point
            slow_p = list;
            while (slow_p != fast_p) {
                slow_p = slow_p->next;
                fast_p = fast_p->next;
            }
            return slow_p; // This is the start of the cycle
        }
    }
    return NULL; // No cycle found
}

// Decycle list that has the entry point
void full_decycle_list(node *head, int data) {
    if (head == NULL || head->next == NULL)
        return;

    // Use detect_cycle to find the entry point of the cycle
    node *entry = detect_cycle(head);
    if (entry == NULL)
        return; // The list is not cyclic

    // Iterate through the cycle and break it
    node *current = entry;
    do {
        if (current->next->data == data) {
            current->next = NULL;
            return;
        }
        current = current->next;
    } while (current != entry);
}

// Decycle list assuming it makes a full cycle
void decycle_list(node *head, int data) {
    if (head == NULL || head->next == head)
        return; // Empty list or single node pointing to itself

    node *current = head;
    node *previous = NULL;

    do {
        if (current->data == data) {
            if (previous != NULL) {
                previous->next = NULL; // Break the cycle
            }
            return;
        }
        previous = current;
        current = current->next;
    } while (current != head); // Loop until we come back to the start
}

// Function to calculate the length of the list
int list_length(node *head) {
    int length = 0;
    node *current = head;

    while (current != NULL) {
        length++;
        current = current->next;
    }

    return length;
}

// Find the first common node
node* find_first_common_node(node* head1, node* head2) {
    int length1 = list_length(head1);
    int length2 = list_length(head2);
    
    int length_diff = abs(length1 - length2);
    
    node* current1 = head1;
    node* current2 = head2;
    
    // Advance the pointer for the longer list by the difference in lengths
    for (int i = 0; i < length_diff; i++) {
        if (length1 > length2) {
            current1 = current1->next;
        } else {
            current2 = current2->next;
        }
    }
    
    // Traverse both lists together until a common node is found
    while (current1 != NULL && current2 != NULL) {
        if (current1 == current2) {
            return current1; // Found the common node
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    
    return NULL; // No common node found
}
/////////////// MERGE SORT START ///////////////

// Function to split the linked list into two halves
node* split_list(node* head) {
    node* fast = head;
    node* slow = head;
    node* previous = NULL;

    while (fast && fast->next) {
        previous = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (previous) {
        previous->next = NULL;
    }

    return slow;
}

// Function to merge two sorted lists
node* merge_sorted_lists(node* list1, node* list2) {
    node* result = NULL;

    if (!list1) return list2;
    if (!list2) return list1;

    if (list1->data <= list2->data) {
        result = list1;
        result->next = merge_sorted_lists(list1->next, list2);
    } else {
        result = list2;
        result->next = merge_sorted_lists(list1, list2->next);
    }

    return result;
}

/////////////// MERGE SORT  END ///////////////
/*
// Simple main
int main(void) {
    int my_array[] = {0, 5, 10, 15, 20, 25, 3, 4};
    node *head = NULL;

    for (int i = 0; i < sizeof(my_array) / sizeof(my_array[0]); ++i) {
        append_node(&head, my_array[i]);
    }

    print_list(head);

    int data_to_delete = 10; // Example: delete node with data 10
    delete_node(&head, data_to_delete);

    printf("List after deletion:\n");
    print_list(head);

    return 0;
}
*/

// Interactive main


int main(void) {
    int my_array[] = {0, 5, 10, 15, 20, 25, 3, 4};

    node *head = NULL;

    for (int i = 0; i < sizeof(my_array) / sizeof(my_array[0]); ++i) {
        append_node(&head, my_array[i]);
    }

    printf("\nInitial state of the list:\n");
    print_list(head);
    printf("\n");

    int option;
    int data, index;

    while (1) {
        printf("Select a function by entering its number:\n");
        printf("1. append_node\n2. print_list\n3. delete_node\n4. insert_first\n");
        printf("5. make_list_cyclic\n6. check_if_cyclic\n7. decycle_list\n");
        printf("8. delete_nodes\n9. delete_at_index\n10. reverse_list\n");
        printf("11. find_index\n12. full_decycle_list\n 13. list_length\n);
        printf("Enter option number (Ctrl+D to exit): ");

        if (scanf("%d", &option) == EOF) {
            break; // Exit loop if EOF is encountered
        }

 switch(option) {
        case 1:
            printf("Enter data to append: ");
            scanf("%d", &data);
            append_node(&head, data);
            break;
        case 2:
            print_list(head);
            break;
        case 3:
            printf("Enter data to delete: ");
            scanf("%d", &data);
            delete_node(&head, data);
            break;
        case 4:
            printf("Enter data to insert at the beginning: ");
            scanf("%d", &data);
            insert_first(&head, data);
            break;
        case 5:
            make_list_cyclic(&head);
            break;
        case 6:
            printf("Is list cyclic? %s\n", check_if_cyclic(head) ? "Yes" : "No");
            break;
        case 7:
            printf("Enter data to decycle at: ");
            scanf("%d", &data);
            decycle_list(head, data);
            break;
        case 8:
            printf("Enter data to delete all occurrences: ");
            scanf("%d", &data);
            delete_nodes(&head, data);
            break;
        case 9:
            printf("Enter index to delete at: ");
            scanf("%d", &index);
            delete_at_index(&head, index);
            break;
        case 10:
            reverse_list(&head);
            break;
        case 11:
            printf("Enter data to find index: ");
            scanf("%d", &data);
            printf("Index of %d: %d\n", data, find_index(head, data));
            break;
        case 12:
            printf("Enter data to decycle at: ");
            scanf("%d", &data);
            full_decycle_list(head, data);
            break;
         case 13:
            list_length(head, data);
            break;
        default:
            printf("Invalid option.\n");
    }

        printf("\n\n\nCurrent state of the list:\n");
        print_list(head);
        printf("\n\n\n");
    }

    // Free memory and exit
    free_list(&head);
    printf("Exiting program.\n");
    return 0;
}
