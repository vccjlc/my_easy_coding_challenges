// SORT USING MERGE SORT
// Function to split the linked list into two halves
// This function splits a linked list into two halves using the "fast and slow pointer" technique. It is used to divide the list into smaller sublists for sorting.
node* split_list(node* head) {
    node* fast = head;
    node* slow = head;
    node* previous = NULL;

    while (fast && fast->next) {
        previous = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (previous) {
        previous->next = NULL;
    }

    return slow;
}

// Function to merge two sorted lists
node* merge_sorted_lists(node* list1, node* list2) {
    node* result = NULL;

    if (!list1) return list2;
    if (!list2) return list1;

    if (list1->data <= list2->data) {
        result = list1;
        result->next = merge_sorted_lists(list1->next, list2);
    } else {
        result = list2;
        result->next = merge_sorted_lists(list1, list2->next);
    }

    return result;
}

// Main function for merge sort
node* merge_sort(node* head) {
    if (!head || !head->next) {
        return head;
    }

    node* second_half = split_list(head);
    head = merge_sort(head);
    second_half = merge_sort(second_half);

    return merge_sorted_lists(head, second_half);
}

