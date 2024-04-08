void remove_duplicates(node **head) {
    if (*head == NULL) {
        return; // Empty list, no duplicates to remove
    }

    node *current = *head;
    while (current != NULL && current->next != NULL) {
        node *runner = current;
        while (runner->next != NULL) {
            if (runner->next->data == current->data) {
                // Duplicate found, remove it
                node *temp = runner->next;
                runner->next = runner->next->next;
                free(temp); // Free the memory of the duplicate node
            } else {
                runner = runner->next; // Move to next element
            }
        }
        current = current->next; // Move to next unique element
    }
}



How it works:
current is used to iterate over each element in the list.
For each current, runner checks the rest of the list for duplicates.
If a duplicate is found, it is removed from the list, and its memory is freed.
The process continues until all elements have been checked for duplicates.


//USAGE 

int main() {
    node *head = NULL;

    // Populate the list with some data, including duplicates
    // ...

    printf("Original list:\n");
    print_list(head);

    // Removing duplicates
    remove_duplicates(&head);

    printf("List after removing duplicates:\n");
    print_list(head);

    // Free the list
    free_list(&head);

    return 0;
}

