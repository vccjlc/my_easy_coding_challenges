// Function to find the first element that occurs the least number of times:
int find_min_occurrence(struct node *head) {
    struct node_occur *occur_list = NULL;
    occur(head, &occur_list);

    int min_occurrence = INT_MAX;
    int min_num = 0;
    struct node_occur *temp = occur_list;

    while (temp != NULL) {
        if (temp->times < min_occurrence) {
            min_occurrence = temp->times;
            min_num = temp->num;
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

    return min_num;
}

