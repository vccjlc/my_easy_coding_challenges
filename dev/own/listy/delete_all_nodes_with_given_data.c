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
