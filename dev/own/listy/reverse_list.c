void reverse_list(node **head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    // prev should be set to NULL because the first node in the
    // reversed list will have its next set to NULL
    node *prev = NULL; 
    node *current = *head;
    node *next = *head;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    // At the end of the while loop, current will be NULL
    *head = prev; // assign *head to prev instead of current to point to the new
                  // head of the list.
}
