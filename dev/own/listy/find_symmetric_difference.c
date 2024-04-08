// SET SYMMETRIC DIFFERENCE
// Function to find the symmetric difference of two linked lists
node *symmetric_difference(node *head1, node *head2) {
    node *sym_diff = NULL;

    // Add elements from the first list that are not in the second list
    node *current = head1;
    while (current != NULL) {
        if (!exists_in_list(head2, current->data)) {
            append_node(&sym_diff, current->data);
        }
        current = current->next;
    }

    // Add elements from the second list that are not in the first list
    current = head2;
    while (current != NULL) {
        if (!exists_in_list(head1, current->data)) {
            append_node(&sym_diff, current->data);
        }
        current = current->next;
    }

    return sym_diff;
}

