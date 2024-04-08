// Function to check if list1 is a subset of list2
int is_subset(node *list1, node *list2) {
    node *current = list1;
    while (current != NULL) {
        if (!exists_in_list(list2, current->data)) {
            return 0; // Element not found in list2, so list1 is not a subset
        }
        current = current->next;
    }
    return 1; // All elements of list1 are in list2
}


// Function to check if list1 is a superset of list2
int is_superset(node *list1, node *list2) {
    return is_subset(list2, list1); // Just reverse the order of the arguments
}

//USAGE 

 // Find symmetric difference
    node *sym_diff = symmetric_difference(list1, list2);
    printf("Symmetric Difference: ");
    print_list(sym_diff);

    // Check if list1 is a subset of list2
    if (is_subset(list1, list2)) {
        printf("List1 is a subset of List2\n");
    } else {
        printf("List1 is not a subset of List2\n");
    }

    // Check if list1 is a superset of list2
    if (is_superset(list1, list2)) {
        printf("List1 is a superset of List2\n");
    } else {
        printf("List1 is not a superset of List2\n");
    }

    // Free all lists
    free_list(&list1);
    free_list(&list2);
    free_list(&sym_diff);
