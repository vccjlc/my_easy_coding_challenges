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

