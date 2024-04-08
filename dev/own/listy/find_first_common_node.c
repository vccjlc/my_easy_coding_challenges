// Find the first common node
node* find_first_common_node(node* head1, node* head2) {
    int length1 = list_length(head1);
    int length2 = list_length(head2);
    
    int length_diff = abs(length1 - length2);
    
    node* current1 = head1;
    node* current2 = head2;
    
    // Advance the pointer for the longer list by the difference in lengths
    for (int i = 0; i < length_diff; i++) {
        if (length1 > length2) {
            current1 = current1->next;
        } else {
            current2 = current2->next;
        }
    }
    
    // Traverse both lists together until a common node is found
    while (current1 != NULL && current2 != NULL) {
        if (current1 == current2) {
            return current1; // Found the common node
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    
    return NULL; // No common node found
}
