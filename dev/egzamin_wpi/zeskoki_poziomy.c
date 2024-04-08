#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
    int value;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Cel zadania: sprawdzić czy dla każdego k, liczba węzłów o poziomie k jest równa liczbie węzłów o zeskoku ks

// Policz ile jest węzłów o każdym poziomie
void addLevels(TreeNode *node, int level, int* levelCounts) {
    if (node == NULL) return;
    levelCounts[level]++;
    addLevels(node->left, level + 1, levelCounts);
    addLevels(node->right, level + 1, levelCounts);
}

// Policz ile jest węzłów o każdym zeskoku
void addJumps(TreeNode *node, int level, int* jumpCounts, int treeHeight) {
    if (node == NULL) return;
    int jump = treeHeight - level;
    jumpCounts[jump]++;
    addJumps(node->left, level + 1, jumpCounts, treeHeight);
    addJumps(node->right, level + 1, jumpCounts, treeHeight);
}

int treeHeight(TreeNode *node) {
    if (node == NULL) return 0;
    int leftHeight = treeHeight(node->left);
    int rightHeight = treeHeight(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

bool jumps_and_levels(TreeNode *node) {
    int h = treeHeight(node); // Get the height of the tree
    int poziomy[h+1]; // Array to count levels, size h+1 to include index h
    int zeskoki[h+1]; // Array to count jumps, size h+1 to include index h

    // Variable Length Arrays (VLAs) such as poziomy[h] and zeskoki[h] cannot be initialized at declaration time in C. You'll need to set their values to 0 in a separate loop after declaring them.
    for (int i = 0; i <= h; ++i) {
        poziomy[i] = 0;
        zeskoki[i] = 0;
    }

    // Fill in the arrays
    addLevels(node, 0, poziomy);
    addJumps(node, 0, zeskoki, h);

    // Compare the arrays
    for (int i = 0; i <= h; ++i) {
        if (poziomy[i] != zeskoki[i]) {
            return false;
        }
    }

    return true; 
}
