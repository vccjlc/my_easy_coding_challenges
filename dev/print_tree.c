#include <stdio.h>
#include <stdlib.h>

// Define the Tree Node structure with updated names
typedef struct Twezel {
    int val;                // Node value
    struct Twezel *Lsyn;    // Left child
    struct Twezel *Psyn;    // Right child (previously 'parent', now 'Psyn' for consistency with your print function)
    struct Twezel *parent;  // Pointer to the parent node
} Twezel;

// Function prototypes
void reverseTreeAndCollectLeafNodes(Twezel *node, Twezel *parent, Twezel ***leafArray, int *leafCount);
Twezel **createLeafArray(Twezel *root, int *leafCount);
void addLeafNodeToArray(Twezel ***leafArray, int *leafIndex, Twezel *node);
void printTree(Twezel *root, int space);

// Main function to demonstrate functionality
int main() {
    // Example usage similar to the previous example, with variable names adjusted

    Twezel *root = (Twezel *)malloc(sizeof(Twezel));
    root->val = 1;
    root->Lsyn = (Twezel *)malloc(sizeof(Twezel));
    root->Psyn = (Twezel *)malloc(sizeof(Twezel));
    root->Lsyn->val = 2;
    root->Psyn->val = 3;
    root->Lsyn->Lsyn = (Twezel *)malloc(sizeof(Twezel));
    root->Lsyn->Lsyn->val = 4;

    // Initialize children's Lsyn, Psyn, and parent pointers to NULL
    root->Lsyn->Psyn = root->Lsyn->parent = root->Psyn->Lsyn = root->Psyn->Psyn = root->Psyn->parent = NULL;
    root->Lsyn->Lsyn->Lsyn = root->Lsyn->Lsyn->Psyn = root->Lsyn->Lsyn->parent = NULL;

    int leafCount = 0;
    Twezel **leafArray = createLeafArray(root, &leafCount);

    // Reverse the tree and print
    printf("Reversed Tree:\n");
    printTree(root, 0);

    // Print leaf node values
    printf("\nLeaf nodes: ");
    for (int i = 0; i < leafCount; i++) {
        printf("%d ", leafArray[i]->val);
    }
    printf("\n");

    // Free allocated memory
    free(leafArray);
    // Note: Ensure to free all allocated nodes to avoid memory leaks

    return 0;
}

// Function implementations remain largely the same, with variable names adjusted
// ...

// Function to print the tree, adjusted for the reversed tree structure
void printTree(Twezel *root, int space) {
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 10;

    // Process right child first (which is now the 'parent' in the reversed tree)
    printTree(root->parent, space);

    // Print current node after space count
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->val);

    // Process left child (which remains as 'Lsyn' in the reversed tree)
    printTree(root->Lsyn, space);
}

