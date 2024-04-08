// DUTCH FLAG by merge 

void rearrange_list(node **head) {
    node *negHead = NULL, *zeroHead = NULL, *posHead = NULL;
    node *negTail = NULL, *zeroTail = NULL, *posTail = NULL;
    node *current = *head;

    // Distribute nodes into three lists: negative, zero, and positive
    while (current != NULL) {
        if (current->data < 0) {
            // Add to negative list
            if (negTail != NULL) {
                negTail->next = current;
            } else {
                negHead = current;
            }
            negTail = current;
        } else if (current->data == 0) {
            // Add to zero list
            if (zeroTail != NULL) {
                zeroTail->next = current;
            } else {
                zeroHead = current;
            }
            zeroTail = current;
        } else {
            // Add to positive list
            if (posTail != NULL) {
                posTail->next = current;
            } else {
                posHead = current;
            }
            posTail = current;
        }
        current = current->next;
    }

    // Combine the three lists: neg -> zero -> pos
    if (negTail != NULL) {
        negTail->next = zeroHead;
    }
    if (zeroTail != NULL) {
        zeroTail->next = posHead;
    }
    if (posTail != NULL) {
        posTail->next = NULL;
    }

    // Update the head of the original list
    *head = negHead ? negHead : (zeroHead ? zeroHead : posHead);
}

