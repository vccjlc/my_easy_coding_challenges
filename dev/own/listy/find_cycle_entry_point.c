// RETURN CYCLE ENTRY POINT
node *detect_cycle(node *list) {
    node *slow_p = list, *fast_p = list;

    // Detecting the cycle
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            // Cycle detected, now find the entry point
            slow_p = list;
            while (slow_p != fast_p) {
                slow_p = slow_p->next;
                fast_p = fast_p->next;
            }
            return slow_p; // This is the start of the cycle
        }
    }
    return NULL; // No cycle found
}


//USAGE 
If a cycle is present, the function returns a pointer to the node where the cycle begins.

