// DECYCLE FULL CYCLE
void decycle_list(node *head, int data) {
    if (head == NULL || head->next == head)
        return; // Empty list or single node pointing to itself

    node *current = head;
    node *previous = NULL;

    do {
        if (current->data == data) {
            if (previous != NULL) {
                previous->next = NULL; // Break the cycle
            }
            return;
        }
        previous = current;
        current = current->next;
    } while (current != head); // Loop until we come back to the start
}
