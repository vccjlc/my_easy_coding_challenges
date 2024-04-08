/*

Start from the root nodes of both input trees.
At each step, compare the values of the current nodes from both trees.
If both nodes exist, create a new node for the resulting tree with the greater value.
If only one node exists, copy that node and its subtree.
If both nodes are NULL, return NULL for that branch.
Recursively apply the same logic for the left and right children of the current nodes.
Return the root of the newly formed tree.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode *left, *right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to merge two trees to create supremum
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 == NULL && t2 == NULL) return NULL; // If both nodes are NULL, return NULL
    if (t1 == NULL) return t2; // If t1 is NULL, return t2
    if (t2 == NULL) return t1; // If t2 is NULL, return t1

    // Create a new node with the greater value among t1 and t2
    TreeNode* root = createNode(t1->value > t2->value ? t1->value : t2->value);

    // Recursively merge the left and right subtrees
    root->left = mergeTrees(t1->left, t2->left);
    root->right = mergeTrees(t1->right, t2->right);

    return root;
}

// Helper function to print the tree in inorder traversal for verification
void printInorder(TreeNode* node) {
    if (node == NULL) return;
    printInorder(node->left);
    printf("%d ", node->value);
    printInorder(node->right);
}

int main() {
    // Example trees construction
    // Tree 1
    TreeNode *t1n1 = createNode(1);
    TreeNode *t1n2 = createNode(3);
    TreeNode *t1n3 = createNode(2);
    t1n1->left = t1n2;
    t1n1->right = t1n3;

    // Tree 2
    TreeNode *t2n1 = createNode(3);
    TreeNode *t2n2 = createNode(1);
    TreeNode *t2n3 = createNode(7);
    t2n1->left = t2n2;
    t2n1->right = t2n3;

    // Merge Trees
    TreeNode* mergedTree = mergeTrees(t1n1, t2n1);

    // Print merged tree in inorder
    printf("Inorder traversal of merged tree: ");
    printInorder(mergedTree);
    printf("\n");

    return 0;
}

