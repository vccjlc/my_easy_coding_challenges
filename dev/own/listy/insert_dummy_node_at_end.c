void insert_dummy_at_end(node **head) {
    node *dummy = create_node(0); // Create a dummy node with value 0 (or any other value you choose)
    if (dummy == NULL) {
        // Handle memory allocation failure if needed
        return;
    }

    if (*head == NULL) {
        // If the list is empty, simply make the dummy node the new head
        *head = dummy;
    } else {
        // Otherwise, find the end of the list and attach the dummy node
        node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = dummy;
    }
}

