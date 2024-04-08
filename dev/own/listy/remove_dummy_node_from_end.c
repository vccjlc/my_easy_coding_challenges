void clear_dummy_from_end(node **head) {
    if (*head == NULL || (*head)->next == NULL) {
        // If the list is empty or has only one node (possibly the dummy), clear it
        free(*head);
        *head = NULL;
        return;
    }

    // Traverse the list to find the second-last node
    node *current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    // Remove the dummy node
    free(current->next);
    current->next = NULL;
}

