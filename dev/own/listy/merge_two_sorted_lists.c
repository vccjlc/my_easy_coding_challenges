// Function to merge two sorted (asc) lists
node* merge_two_lists(node* list1, node* list2){
    // Handle empty lists
    if (!list1) return list2;
    if (!list2) return list1;

    node* iterator1, *back_of_new_list;

    // Ensure list1 starts with the smaller value
    if (list1->data > list2->data) {
        back_of_new_list = list2;
        list2 = list1;
        list1 = back_of_new_list;
    } else {
        back_of_new_list = list1;
    }

    iterator1 = list1->next;

    // Merge the two lists
    while (iterator1 && list2) {
        if (iterator1->data < list2->data) {
            back_of_new_list->next = iterator1;
            iterator1 = iterator1->next;
        } else {
            back_of_new_list->next = list2;
            list2 = list2->next;
        }
        back_of_new_list = back_of_new_list->next;
    }

    // Attach any remaining nodes
    back_of_new_list->next = iterator1 ? iterator1 : list2;

    return list1;
}


// MERGE DESCENDING
// Function to merge two sorted lists in descending order
node* merge_descending(node* list1, node* list2) {
    // Handle empty lists
    if (!list1) return list2;
    if (!list2) return list1;

    // Start with the larger element of list1 and list2
    if (list1->data >= list2->data) {
        list1->next = merge_descending(list1->next, list2);
        return list1;
    } else {
        list2->next = merge_descending(list1, list2->next);
        return list2;
    }
}
