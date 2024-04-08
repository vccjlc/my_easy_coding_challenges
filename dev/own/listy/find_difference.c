// SET DIFFERENCE
// Helper function to check if a value exists in a list
int exists_in_list(node *head, int data) {
    node *current = head;
    while (current != NULL) {
        if (current->data == data) {
            return 1; // Data found in the list
        }
        current = current->next;
    }
    return 0; // Data not found
}

// Function to find the difference of two linked lists
node *difference_of_lists(node *head1, node *head2) {
    node *difference_head = NULL; // This will be the head of the difference list

    // Add elements from the first list that are not in the second list
    node *current = head1;
    while (current != NULL) {
        if (!exists_in_list(head2, current->data)) {
            append_node(&difference_head, current->data);
        }
        current = current->next;
    }

    return difference_head; // Return the head of the difference list
}

//USAGE
// Finding the difference of list1 and list2
node *difference = difference_of_lists(list1, list2);
