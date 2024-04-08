
void reverse_first_n_nodes(node **head, int n) {
    if (*head == NULL || n <= 0) {
        return; // List is empty or no need to reverse
    }

    node *current = *head;
    node *prev = NULL, *next = NULL;
    int count = 0;

    // Reverse the first n nodes of the linked list
    while (current != NULL && count < n) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // Now next points to (n+1)th node
    // If n was greater than or equal to length of list, no need to attach
    if (next != NULL) {
        (*head)->next = next;
    }

    *head = prev; // prev is now the new head of the reversed list
}
