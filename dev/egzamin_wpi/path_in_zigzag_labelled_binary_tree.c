/*

In an infinite binary tree where every node has two children, the nodes are labelled in row order.

In the odd numbered rows (ie., the first, third, fifth,...), the labelling is left to right, while in the even numbered rows (second, fourth, sixth,...), the labelling is right to left.

Given the label of a node in this tree, return the labels in the path from the root of the tree to the node with that label.

To find the path from the root of an infinite binary tree to a given node where the labeling alternates between left-to-right and right-to-left in successive rows, you can follow these steps. This method leverages the properties of a perfect binary tree and the pattern in which the nodes are labeled.

Understand the Labeling Pattern: In a perfect binary tree, for any given node with label x at level n (considering the root as level 1), the parent node's label can be derived by halving the label of the current node after adjusting for the row's ordering. The key is to understand how the labels are assigned in each row and how they relate to the parent nodes.

Calculate the Level of the Given Node: Since the tree is infinite and the labeling starts with 1 at the root, doubling at each level, you can determine the level of a node by its label value. For example, the first level has 1, the second level has labels 2 and 3, the third level has labels 4 to 7, and so on.

Trace Back to the Root: To find the path from the given node back to the root, repeatedly find the parent node until you reach the root. In odd-numbered rows, the labeling is left-to-right, and in even-numbered rows, it's right-to-left. You need to adjust for this when calculating the parent node's label.

Reverse the Path: Since you start from the given node and go up to the root, reverse the collected labels to get the path from the root to the given node.

*/



#include <stdio.h>
#include <stdlib.h>

int* pathInZigZagTree(int label, int* returnSize) {
    // Calculate the level of the node
    int level = 0;
    for (int x = label; x > 0; x >>= 1) {
        level++;
    }

    // Allocate memory for the path array
    *returnSize = level;
    int* path = (int*)malloc(*returnSize * sizeof(int));

    while (label > 0) {
        path[--level] = label; // Fill the path array from the end
        int levelMax = (1 << level) + (1 << (level - 1)) - 1; // Max label for the current level
        int levelMin = 1 << (level - 1); // Min label for the current level
        label = levelMax + levelMin - label; // Mirror label in the current level
        label >>= 1; // Move to the parent node
    }

    return path;
}

int main() {
    int label = 14; // Example node label
    int returnSize;
    int* path = pathInZigZagTree(label, &returnSize);

    printf("Path: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");

    free(path); // Remember to free the allocated memory
    return 0;
}

