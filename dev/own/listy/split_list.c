// SPLIT LIST
/*
To split a linked list into two lists based on a specific value (let's call it pivot), you need to traverse the original list and move nodes to one of the two new lists depending on whether their data is less than or equal to the pivot, or greater than the pivot. This function assumes that the original list may be modified and nodes will be transferred to the new lists without creating additional copies.
*/

void split_list(node *head, int pivot, node **less_or_equal, node **greater) {
    *less_or_equal = NULL;
    *greater = NULL;

    node **ptr_less_or_equal = less_or_equal;
    node **ptr_greater = greater;

    while (head != NULL) {
        if (head->data <= pivot) {
            *ptr_less_or_equal = head;
            ptr_less_or_equal = &((*ptr_less_or_equal)->next);
        } else {
            *ptr_greater = head;
            ptr_greater = &((*ptr_greater)->next);
        }
        head = head->next;
    }

    // Terminate both lists
    *ptr_less_or_equal = NULL;
    *ptr_greater = NULL;
}

//USAGE

   int pivot = 10; // Define your pivot value
    split_list(head, pivot, &less_or_equal, &greater);

