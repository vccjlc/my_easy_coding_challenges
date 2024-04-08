struct node* reverse_list_copy(struct node* head) {
    struct node *prev = NULL, *current = head, *next = NULL, *new_node;

    while (current != NULL) {
        new_node = malloc(sizeof(struct node));
        if (new_node == NULL) {
            // Handle memory allocation failure
            return NULL;
        }
        new_node->num = current->num;
        new_node->next = prev;
        prev = new_node;
        current = current->next;
    }
    return prev;
}

int is_list_palindrome(struct node* head) {
    struct node *reversed = reverse_list_copy(head);
    struct node *original = head, *rev = reversed;
    int is_palindrome = 1;

    while (original != NULL && rev != NULL) {
        if (original->num != rev->num) {
            is_palindrome = 0;
            break;
        }
        original = original->next;
        rev = rev->next;
    }

    // Free the memory allocated for the reversed copy
    struct node *temp;
    while (reversed != NULL) {
        temp = reversed;
        reversed = reversed->next;
        free(temp);
    }

    return is_palindrome;
}



/* USAGE
int result = is_palindrome(head);
if (result == 1) {
    printf("The list is a palindrome.\n");
} else if (result == 0) {
    printf("The list is not a palindrome.\n");
} else {
    printf("Error occurred.\n");
}
*/





// O(n^2) BELOW

int palin_check(struct node *p, int count) {
    // Handle the case where the list is empty or has only one node
    if (p == NULL || p->next == NULL) {
        return 1; // An empty list or a single-node list is a palindrome
    }

    int i = 0, j;
    struct node *front, *rear;

    while (i != count / 2) {
        front = rear = p;

        for (j = 0; j < i; j++) {
            front = front->next;
        }

        for (j = 0; j < count - (i + 1); j++) {
            rear = rear->next;
        }

        if (front->num != rear->num) {
            return 0;
        } else {
            i++;
        }
    }

    return 1;
}


