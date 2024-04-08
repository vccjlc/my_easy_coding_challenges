// SET UNION 
int exists_in_list(node *head, int data) {
    node *current = head;
    while (current != NULL) {
        if (current->data == data) {
            return 1; // Data found in the list
        }
        current = current->next;
    }
    return 0; // Data not found
}

node *union_of_lists(node *head1, node *head2) {
    node *union_head = NULL; // This will be the head of the union list

    // Add unique elements from the first list to the union list
    node *current = head1;
    while (current != NULL) {
        if (!exists_in_list(union_head, current->data)) {
            append_node(&union_head, current->data);
        }
        current = current->next;
    }

    // Add unique elements from the second list to the union list
    current = head2;
    while (current != NULL) {
        if (!exists_in_list(union_head, current->data)) {
            append_node(&union_head, current->data);
        }
        current = current->next;
    }

    return union_head; // Return the head of the union list
}


//USAGE 
int main() {
    node *list1 = NULL;
    node *list2 = NULL;

    // Populate list1 and list2 with some data
    // ...

    // Find the union (sum) of list1 and list2
    node *sum_list = union_of_lists(list1, list2);
    printf("Sum of the two sets: ");
    print_list(sum_list);

    // Free all lists
    free_list(&list1);
    free_list(&list2);
    free_list(&sum_list);

    return 0;
}

