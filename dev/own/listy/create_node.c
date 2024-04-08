// CREATE NODE
node *create_node(int data) {
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode != NULL) { // Check if memory allocation was successful
        newnode->data = data;
        newnode->next = NULL;
    }
    return newnode; // returns NULL if allocation failed, otherwise a pointer to
                    // a node
}
