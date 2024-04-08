// This will delete all nodes with the value 5 from the list. Remember to always pass the address of the head pointer (&head) to this function, as it may modify the head of the list.

void delete_current_node(node **head, int target) {
    if (*head == NULL) {
        return; // List is empty
    }

    node *current = *head;
    node *prev = NULL;

    while (current != NULL) {
        if (current->data == target) {
            if (prev == NULL) {
                // Node to be deleted is the head node
                *head = current->next;
                free(current);
                current = *head; // Continue traversal from the new head
            } else {
                // Node to be deleted is not the head node
                prev->next = current->next;
                free(current);
                current = prev->next; // Continue traversal from the next node
            }
        } else {
            // Move to the next node
            prev = current;
            current = current->next;
        }
    }
}

// USAGE

int target = 5; // Example target value to delete
delete_current_node(&head, target);

