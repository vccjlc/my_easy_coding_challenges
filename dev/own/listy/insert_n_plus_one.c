// Insert 1 between "each" 0 and 2
void insert_missing_nodes(node **head) {
    if (!*head || !(*head)->next) {
        return;
    }

    node *current = *head;
    while (current->next) {
        if (current->data + 2 == current->next->data) {
            node *new_node = create_node(current->data + 1);
            new_node->next = current->next;
            current->next = new_node;
            current = new_node->next; // Move two nodes forward
        } else {
            current = current->next; // Move to the next node
        }
    }
}

