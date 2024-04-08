//FIND DISTANCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h> // For using the abs() function

typedef struct node {
    int data;
    struct node *next;
} node;

// Function to find the index of a given node
int find_index(node *head, int data) {
    int index = 0;
    while (head != NULL) {
        if (head->data == data) {
            return index;
        }
        head = head->next;
        index++;
    }
    return -1; // If the node is not found
}

// Function to find the distance between two nodes
int find_distance(node *head, int data1, int data2) {
    int index1 = find_index(head, data1);
    int index2 = find_index(head, data2);

    if (index1 == -1 || index2 == -1) {
        printf("One or both of the nodes not found in the list.\n");
        return -1; // Indicates an error
    }

    return abs(index1 - index2); // Return the absolute difference of indices
}

// Main function for demonstration
int main() {
    node *head = NULL; // Create your linked list and populate it
    // ... Linked list creation and population code goes here ...

    int data1 = /* first node data */;
    int data2 = /* second node data */;
    int distance = find_distance(head, data1, data2);

    if (distance != -1) {
        printf("Distance between node %d and node %d is %d.\n", data1, data2, distance);
    }

    // Free the linked list
    // ... Freeing code goes here ...

    return 0;
}

