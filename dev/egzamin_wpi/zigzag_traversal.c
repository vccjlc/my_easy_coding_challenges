#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode *left, *right;
} TreeNode;

typedef struct StackNode {
    TreeNode *tNode;
    struct StackNode *next;
} StackNode;

void push(StackNode **top, TreeNode *tNode) {
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->tNode = tNode;
    newNode->next = *top;
    *top = newNode;
}

TreeNode* pop(StackNode **top) {
    if (*top == NULL) return NULL;
    StackNode *temp = *top;
    TreeNode *tNode = temp->tNode;
    *top = (*top)->next;
    free(temp);
    return tNode;
}

int isStackEmpty(StackNode *top) {
    return top == NULL;
}

void zigzagTraversal(TreeNode *root) {
    if (root == NULL) return;
    
    StackNode *currentLevel = NULL;
    StackNode *nextLevel = NULL;
    
    push(&currentLevel, root);
    int leftToRight = 1;

    while (!isStackEmpty(currentLevel)) {
        TreeNode *node = pop(&currentLevel);
        printf("%d ", node->value);

        if (leftToRight) {
            if (node->left) push(&nextLevel, node->left);
            if (node->right) push(&nextLevel, node->right);
        } else {
            if (node->right) push(&nextLevel, node->right);
            if (node->left) push(&nextLevel, node->left);
        }

        if (isStackEmpty(currentLevel)) {
            leftToRight = !leftToRight;
            StackNode *temp = currentLevel;
            currentLevel = nextLevel;
            nextLevel = temp;
        }
    }
}

