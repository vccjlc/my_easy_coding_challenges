//REMOVE COMMON UP TO MULTISET (MULTISET DIFFERENCE) 

void remove_common_up_to_multiset(node **list1, node *list2) {
    if (!*list1 || !list2) return;

    node *current1 = *list1, *prev1 = NULL, *temp;
    node *current2 = list2;

    while (current1 != NULL && current2 != NULL) {
        // If current element in list1 is less than current element in list2,
        // move to the next element in list1
        if (current1->data < current2->data) {
            prev1 = current1;
            current1 = current1->next;
        } else if (current1->data > current2->data) {
            // If current element in list1 is greater, move to the next element in list2
            current2 = current2->next;
        } else {
            // If elements are equal, remove current1 from list1
            temp = current1;
            current1 = current1->next;

            // Re-link previous node to the next node, effectively removing the current node
            if (prev1) {
                prev1->next = current1;
            } else {
                *list1 = current1;
            }

            // Free the memory of the removed node if dynamically allocated
            free(temp);

            // Move to the next element in list2 to ensure multiset behavior
            current2 = current2->next;
        }
    }
}

