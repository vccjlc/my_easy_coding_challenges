// Function to check if an element is the arithmetic mean of its neighbors
bool hasMeanValue(node *head) {
    if (!head || !head->next || !head->next->next) {
        return false; // List is too short to satisfy the condition
    }

    node *prev = head;
    node *current = head->next;
    node *next = current->next;

    while (next) {
        if (current->data == (prev->data + next->data) / 2) {
            return true; // Found a node that is the mean of its neighbors
        }
        prev = current;
        current = next;
        next = next->next;
    }

    return false; // No such node found
}

