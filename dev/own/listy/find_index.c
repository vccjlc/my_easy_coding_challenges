int find_index(node *head, int element) {
    int index = 0;
    int found = 0; // Flag to indicate if the element is found

    while (head != NULL && !found) {
        if (head->data == element) {
            found = 1; // Element found, set the flag and exit the loop
        } else {
            index++;           // Increment index only if element not found
            head = head->next; // Move to the next node
        }
    }

    if (found) {
        return index; // Return the index if element was found
    } else {
        return -1; // Element not found, return -1
    }
}
