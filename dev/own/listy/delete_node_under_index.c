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
