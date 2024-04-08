// Function to find the first element that occurs most times:

int find_max_occurrence(struct node *head) {
    struct node_occur *occur_list = NULL;
    occur(head, &occur_list);

    int max_occurrence = 0;
    int max_num = 0;
    struct node_occur *temp = occur_list;

    while (temp != NULL) {
        if (temp->times > max_occurrence) {
            max_occurrence = temp->times;
            max_num = temp->num;
        }
        temp = temp->next;
    }

    // Free the occur_list
    struct node_occur *curr;
    while (occur_list != NULL) {
        curr = occur_list;
        occur_list = occur_list->next;
        free(curr);
    }

    return max_num;
}

