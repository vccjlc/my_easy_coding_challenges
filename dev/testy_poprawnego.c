#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Twezel {
    int val;
    struct Twezel *Lsyn; // Left child
    struct Twezel *Psyn; // Right child
} Twezel;

typedef struct Tlista {
    int val;
    struct Tlista *next;
} Tlista;

// Function declarations
bool dfs(Twezel *d, Tlista *L);
bool helper(Twezel *d, Tlista *L);

// Function to create a new tree node
Twezel* newTreeNode(int value) {
    Twezel* node = (Twezel*)malloc(sizeof(Twezel));
    node->val = value;
    node->Lsyn = NULL;
    node->Psyn = NULL;
    return node;
}

// Function to create a new list node
Tlista* newList(int value) {
    Tlista* node = (Tlista*)malloc(sizeof(Tlista));
    node->val = value;
    node->next = NULL;
    return node;
}

// Function to build the tree from an array representation
Twezel* buildTree(int* arr, int index, int size) {
    if (index >= size || arr[index] == -1) { // Using -1 to represent NULL
        return NULL;
    }

    Twezel* root = newTreeNode(arr[index]);
    root->Lsyn = buildTree(arr, 2 * index + 1, size);
    root->Psyn = buildTree(arr, 2 * index + 2, size);
    return root;
}

// Function to build the list from an array representation
Tlista* buildList(int* arr, int size) {
    if (size == 0) {
        return NULL;
    }

    Tlista* head = newList(arr[0]);
    Tlista* current = head;

    for (int i = 1; i < size; ++i) {
        current->next = newList(arr[i]);
        current = current->next;
    }

    return head;
}


bool helper(Twezel *d, Tlista *L) {
    if (!d && L) return false;
    if (!d && !L) return false;
    if (!L) return false;

    return dfs(d, L) || helper(d->Lsyn, L) || helper(d->Psyn, L);
}

bool dfs(Twezel *d, Tlista *L) {

    if (!d || !L) return false;
    
    if (L->next == NULL && d->Lsyn == NULL && d->Psyn == NULL && L->val == d->val) return true;

    if (d->val != L->val) return false;
    
    return dfs(d->Lsyn, L->next) || dfs(d->Psyn, L->next);
}



void printTree(Twezel *root, int space) {
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 10;

    // Process right child first
    printTree(root->Psyn, space);

    // Print current node after space count
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->val);

    // Process left child
    printTree(root->Lsyn, space);
}

// Function to print the list
void printList(Tlista *head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// Your existing dfs and helper functions...

int main() {
    // Example: Array representation of the tree (using -1 for NULL)
    int treeArr[] = {1, 2, 3, 4, 5, 6, 7, 8};

    int listArr[] = {1, 3, 6}; // Example: List to match with the tree path

    bool expected_value = true;

    // Size of the tree array
    int treeSize = sizeof(treeArr) / sizeof(treeArr[0]);

    // Size of the list array
    int listSize = sizeof(listArr) / sizeof(listArr[0]);

    // Build the tree
    Twezel* root = buildTree(treeArr, 0, treeSize);

    // Build the list
    Tlista* list = buildList(listArr, listSize);

    // Print the tree and the list
    printf("Binary Tree:\n");
    printTree(root, 0);
    printf("\n");
    printList(list);

    // Test and print the result
    bool result = helper(root, list);
    printf("For this test case, the function returns %s\n", result ? "true" : "false");

    if (result == expected_value) {
        printf("Test: Algorithm works\n");
    } else {
        printf("Test: Algorithm does not work\n");
    }

    // TODO: Free the allocated memory for tree and list

    return 0;
}


