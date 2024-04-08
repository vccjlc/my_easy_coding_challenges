// Point last node to the first, which will make a full cycle
void make_list_cyclic(node **head) {
    if (*head == NULL) {
        return; // Return if the list is empty
    }

    node *last_node = get_last_node(*head); // Pass the dereferenced head
    if (last_node != NULL) {
        last_node->next =
            *head; // Connect the last node to the head of the list
    }
}
