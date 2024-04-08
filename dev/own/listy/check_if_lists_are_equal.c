// Check if lists are equal
int compare(struct node *p, struct node *q) {
    while (p != NULL && q != NULL) {
        if (p->num != q->num) {
            return 0;
        } else {
            p = p->next;
            q = q->next;
        }
    }
    if (p != NULL || q != NULL) {
        return 0;
    } else {
        return 1;
    }
}
