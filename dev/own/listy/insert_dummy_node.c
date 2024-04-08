void insert_dummy_node(node **head, int position) {
    if (position < 0 || head == NULL) {
        return; // Invalid position or NULL head pointer
    }

    node *dummy = create_node(0); // Creating a dummy node with data '0' or any arbitrary value
    if (dummy == NULL) {
        return; // Memory allocation failed
    }

    if (position == 0 || *head == NULL) {
        // Insert at the beginning or in an empty list
        dummy->next = *head;
        *head = dummy;
    } else {
        // Insert at a specific position (not at the beginning)
        node *current = *head;
        for (int i = 0; current != NULL && i < position - 1; i++) {
            current = current->next;
        }

        if (current != NULL) {
            dummy->next = current->next;
            current->next = dummy;
        } else {
            // Position is beyond the end of the list, free dummy
            free(dummy);
        }
    }
}

// Function to Find Position of an Element
int find_position(node *head, int element) {
    int position = 0;
    node *current = head;

    while (current != NULL) {
        if (current->data == element) {
            return position; // Element found, return its position
        }
        current = current->next;
        position++;
    }

    return -1; // Element not found in the list
}

// USAGE

int element = 5; // Example element to find
int position = find_position(head, element);

if (position != -1) {
    printf("Element %d found at position %d\n", element, position);
} else {
    printf("Element %d not found in the list\n", element);
}

