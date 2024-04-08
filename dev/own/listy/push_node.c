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
