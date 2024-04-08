
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *ptrA = headA;
    struct ListNode *ptrB = headB;

    // Continue until both pointers are the same (either at intersection or both NULL)
    while (ptrA != ptrB) {
        // When reaching the end of one list, continue from the beginning of the other
        // If there's no intersection, both will eventually become NULL
        ptrA = ptrA == NULL ? headB : ptrA->next;
        ptrB = ptrB == NULL ? headA : ptrB->next;
    }

    // Either the intersection node or NULL
    return ptrA;
}
