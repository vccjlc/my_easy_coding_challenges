void swap_nodes(node **head, int data1, int data2) {
    if (*head == NULL || data1 == data2) {
        return; // If the list is empty or the data values are the same, do nothing
    }

    node **node1Prev = NULL, **node2Prev = NULL;
    node *node1 = *head, *node2 = *head;

    // Find nodes and their previous nodes
    while (node1 && node1->data != data1) {
        node1Prev = &node1->next;
        node1 = node1->next;
    }

    while (node2 && node2->data != data2) {
        node2Prev = &node2->next;
        node2 = node2->next;
    }

    // If either node is not found, do nothing
    if (node1 == NULL || node2 == NULL) {
        return;
    }

    // Swap the nodes
    if (node1Prev) {
        *node1Prev = node2;
    } else {
        *head = node2; // node1 was the head
    }

    if (node2Prev) {
        *node2Prev = node1;
    } else {
        *head = node1; // node2 was the head
    }

    // Swap the next pointers of the nodes
    node *temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;
}

//USAGE

    // Swap two nodes
    swap_nodes(&head, data1, data2);
