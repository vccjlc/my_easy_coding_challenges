void alternate_list(node **head) {
    if (*head == NULL || (*head)->next == NULL || (*head)->next->next == NULL) {
        return; // The list has fewer than 3 nodes
    }

    node *prev = *head;
    node *curr = (*head)->next;
    node *next = curr->next;

    while (next != NULL) {
        // Check for increasing or decreasing sequence
        if ((prev->data < curr->data && curr->data < next->data) ||
            (prev->data > curr->data && curr->data > next->data)) {
            // Swap curr and next
            curr->next = next->next;
            next->next = curr;
            prev->next = next;

            // Move prev two steps ahead
            prev = next;
            if (prev->next != NULL) {
                curr = prev->next;
            } else {
                break;
            }
        } else {
            // Move all pointers one step ahead
            prev = curr;
            curr = next;
        }

        if (curr->next != NULL) {
            next = curr->next;
        } else {
            break;
        }
    }
}

