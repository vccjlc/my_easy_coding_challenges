/*
 Function takes a linked list head and counts the occurrences of each distinct element in the list. It then stores these counts in a separate linked list pointed to by result. Each node in the result list contains the value (num) from the original list and the number of times (times) it appears. 
*/

void occur(struct node *head, struct node_occur **result) {
    struct node *p;
    struct node_occur *temp, *prev;

    p = head;  // Start iterating from the head of the input list
    while (p != NULL) {  // Continue until the end of the list
        temp = *result;  // Start from the beginning of the result list
        while (temp != NULL && temp->num != p->num) {  // Search for a node in the result list with the same number
            prev = temp;  // Keep track of the previous node
            temp = temp->next;  // Move to the next node in the result list
        }
        if (temp == NULL) {  // If the number is not found in the result list
            temp = (struct node_occur *)malloc(sizeof(struct node_occur));  // Create a new node
            temp->num = p->num;  // Set the number
            temp->times = 1;  // Initialize the occurrence count to 1
            temp->next = NULL;  // Set the next pointer to NULL
            if (*result != NULL) {
                prev->next = temp;  // Link the new node to the end of the result list
            } else {
                *result = temp;  // If the result list is empty, set it to the new node
            }
        } else {
            temp->times += 1;  // If the number is found, increment the occurrence count
        }
        p = p->next;  // Move to the next node in the input list
    }
}

