void delete_duplicates(struct node **head) {
    struct node *current, *next, *prev, *temp;

    current = *head;
    while (current != NULL && current->next != NULL) {
        prev = current;
        next = current->next;

        while (next != NULL) {
            if (current->num == next->num) {
                // Duplicate found, remove it
                temp = next;
                next = next->next;
                prev->next = next;
                free(temp);
            } else {
                // Move prev and next pointers if no duplicate
                prev = next;
                next = next->next;
            }
        }
        current = current->next; // Move to the next node
    }
}

