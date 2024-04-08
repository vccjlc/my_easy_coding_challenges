//COUNT UNIQUE TAILS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

#define HASH_SIZE 1024 // A larger size may be needed for a bigger list

typedef struct hash_table {
    node *table[HASH_SIZE];
} hash_table;

// Simple hash function for node addresses
unsigned int hash(node *ptr) {
    return ((unsigned long)ptr) % HASH_SIZE;
}

// Add a node to the hash table
void add_to_hash_table(hash_table *ht, node *ptr) {
    int index = hash(ptr);
    ht->table[index] = ptr;
}

// Check if a node is in the hash table
int is_in_hash_table(hash_table *ht, node *ptr) {
    int index = hash(ptr);
    return ht->table[index] == ptr;
}

// Count unique tails in the array of linked lists
int count_unique_tails(node **lists, int num_lists) {
    hash_table ht = {0};
    int unique_tails = 0;

    for (int i = 0; i < num_lists; i++) {
        node *current = lists[i];
        // Traverse to the end of the list
        while (current != NULL && current->next != NULL) {
            current = current->next;
        }
        // Add the tail to the hash table if not already present
        if (current != NULL && !is_in_hash_table(&ht, current)) {
            add_to_hash_table(&ht, current);
            unique_tails++;
        }
    }

    return unique_tails;
}

// Example usage
int main() {
    // Example lists creation and initialization code should go here

    // Assuming lists is an array of node* with num_lists elements
    node **lists; 
    int num_lists;

    int unique_tails_count = count_unique_tails(lists, num_lists);
    printf("Number of unique tails: %d\n", unique_tails_count);

    return 0;
}

