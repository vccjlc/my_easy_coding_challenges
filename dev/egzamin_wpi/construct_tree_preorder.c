/*


To construct a binary tree from given inorder and preorder traversal sequences, we can follow a systematic approach where we use the preorder sequence to determine the root nodes, and the inorder sequence to identify the left and right subtrees.

Algorithm:
The first element of the preorder sequence is always the root of the tree.
Find the root in the inorder sequence. Elements to the left of the root in the inorder sequence form the left subtree, and elements to the right form the right subtree.
Recursively apply the above steps to construct the left and right subtrees.

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
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find the index of value in arr[start...end]
int search(int arr[], int start, int end, int value) {
    int i;
    for (i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// Recursive function to construct binary tree
TreeNode* buildTreeHelper(int in[], int pre[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd)
        return NULL;

    // Pick current node from Preorder traversal using preIndex and increment preIndex
    TreeNode* node = createNode(pre[*preIndex]);
    (*preIndex)++;

    // If this node has no children then return
    if (inStart == inEnd)
        return node;

    // Else find the index of this node in Inorder traversal
    int inIndex = search(in, inStart, inEnd, node->value);

    // Using index in Inorder traversal, construct left and right subtrees
    node->left = buildTreeHelper(in, pre, inStart, inIndex - 1, preIndex);
    node->right = buildTreeHelper(in, pre, inIndex + 1, inEnd, preIndex);

    return node;
}

// The main function to construct binary tree from given inorder and preorder traversals
TreeNode* buildTree(int in[], int pre[], int n) {
    int preIndex = 0;
    return buildTreeHelper(in, pre, 0, n - 1, &preIndex);
}

// Function to print inorder traversal of the tree
void printInorder(TreeNode* node) {
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->value);
    printInorder(node->right);
}

// Driver program to test above functions
int main() {
    int in[] = {20, 10, 40, 30, 50};
    int pre[] = {10, 20, 30, 40, 50};
    int len = sizeof(in) / sizeof(in[0]);
    TreeNode* root = buildTree(in, pre, len);

    printf("Inorder traversal of the constructed tree is \n");
    printInorder(root);
    printf("\n");
    return 0;
}

/*

Explanation:
createNode(int value): Creates a new tree node.
search(int arr[], int start, int end, int value): Finds the index of a value in the array; used to find the root in the inorder sequence.
buildTreeHelper(int in[], int pre[], int inStart, int inEnd, int* preIndex): The recursive helper function to construct the tree. It uses preIndex to pick the current node from the preorder sequence, finds this node's index in the inorder sequence, and constructs the left and right subtrees.
buildTree(int in[], int pre[], int n): This is the main function that initializes the necessary variables and calls buildTreeHelper.
printInorder(TreeNode* node): Prints the inorder traversal of the tree to verify the correctness of the constructed tree.
The program constructs the tree from the given inorder and preorder traversal sequences and then prints the inorder traversal of the constructed tree to verify its correctness.

*/
