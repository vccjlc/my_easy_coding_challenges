typedef struct node {
    int data;
    struct node *next;
} node;

// Definition of the Node Structure
node* create_list() {
    node* sentinel = (node*)malloc(sizeof(node));
    if (sentinel == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    sentinel->next = NULL; // Initially, the list is empty, so next is NULL.
    return sentinel;
}

// Function to Create a New List with a Sentinel Node
void insert_node(node* sentinel, int data) {
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = sentinel->next;
    sentinel->next = new_node;
}

// Function to Delete the First Actual Node (After the Sentinel)
void delete_first_node(node* sentinel) {
    if (sentinel->next == NULL) {
        printf("List is empty!\n");
        return;
    }
    node* first_node = sentinel->next;
    sentinel->next = first_node->next;
    free(first_node);
}

// Example usage
int main() {
    node* my_list = create_list();

    insert_node(my_list, 10); // Insert first element
    insert_node(my_list, 20); // Insert second element

    // Delete first actual element (which is '10')
    delete_first_node(my_list);

    // Clean up: delete remaining elements and the sentinel node
    delete_first_node(my_list); // This will delete '20'
    free(my_list); // Delete the sentinel node

    return 0;
}

