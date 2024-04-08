int list_length(node *head) {
    int length = 0;
    node *current = head;

    while (current != NULL) {
        length++;
        current = current->next;
    }

    return length;
}
