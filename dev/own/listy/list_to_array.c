//LIST TO ARRAY

#include <stdio.h>
#include <stdlib.h>

// Function to count the number of nodes in the list
int count_nodes(node *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to transform the list into an array
int *list_to_array(node *head) {
    int count = count_nodes(head);
    int *array = (int *)malloc(count * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL; // Return NULL if memory allocation fails
    }

    int i = 0;
    while (head != NULL) {
        array[i++] = head->data;
        head = head->next;
    }

    return array;
}


//USAGE 

int main() {
    // Create and populate your linked list here
    node *head = NULL;
    // ... Code to populate the list ...

    // Convert list to array
    int *array = list_to_array(head);
    if (array != NULL) {
        int count = count_nodes(head);
        printf("Array: ");
        for (int i = 0; i < count; ++i) {
            printf("%d ", array[i]);
        }
        printf("\n");

        // Don't forget to free the allocated array memory
        free(array);
    }

    // Free the linked list
    // ... Code to free the list ...
    return 0;
}

