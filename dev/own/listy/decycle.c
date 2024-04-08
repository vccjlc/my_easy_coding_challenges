//DECYCLE
void full_decycle_list(node *head, int data) {
    if (head == NULL || head->next == NULL)
        return;

    // Use detect_cycle to find the entry point of the cycle
    node *entry = detect_cycle(head);
    if (entry == NULL)
        return; // The list is not cyclic

    // Iterate through the cycle and break it
    node *current = entry;
    do {
        if (current->next->data == data) {
            current->next = NULL;
            return;
        }
        current = current->next;
    } while (current != entry);
}
