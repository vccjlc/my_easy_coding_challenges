//FIND FIRST COMMON ELEMENT
int find(struct node *p, struct node *q) {
    struct node *temp;

    while (p != NULL) {
        temp = q;
        while (temp != NULL) {
            if (temp->num == p->num) {
                return p->num;
            }
            temp = temp->next;
        }
        p = p->next;
    }

    /*Assuming 0 is not used in the list*/
    return 0;
}
