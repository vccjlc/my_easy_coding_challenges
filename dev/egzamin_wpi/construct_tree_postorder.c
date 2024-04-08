/*

To construct a binary tree from given inorder and postorder traversal sequences, the approach is similar to using inorder and preorder sequences, but with a few key adjustments. In the postorder sequence, the last element is always the root of the tree. We use this to identify the root nodes, and the inorder sequence to identify the left and right subtrees.

Algorithm:
The last element of the postorder sequence is the root of the tree.
Find the root in the inorder sequence. Elements to the left of the root in the inorder sequence form the left subtree, and elements to the right form the right subtree.
Recursively apply the above steps to construct the left and right subtrees, using the next-to-last element in the postorder sequence for the next root, and so on.

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
TreeNode* buildTreeHelper(int in[], int post[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd)
        return NULL;

    // Pick current node from Postorder traversal using postIndex and decrement postIndex
    TreeNode* node = createNode(post[*postIndex]);
    (*postIndex)--;

    // If this node has no children then return
    if (inStart == inEnd)
        return node;

    // Else find the index of this node in Inorder traversal
    int inIndex = search(in, inStart, inEnd, node->value);

    // Using index in Inorder traversal, construct right and left subtrees
    // Note: We first construct the right subtree because in postorder, the last node is the rightmost node
    node->right = buildTreeHelper(in, post, inIndex + 1, inEnd, postIndex);
    node->left = buildTreeHelper(in, post, inStart, inIndex - 1, postIndex);

    return node;
}

// The main function to construct binary tree from given inorder and postorder traversals
TreeNode* buildTree(int in[], int post[], int n) {
    int postIndex = n - 1; // Start from the last element in postorder
    return buildTreeHelper(in, post, 0, n - 1, &postIndex);
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
    int post[] = {20, 40, 50, 30, 10};
    int len = sizeof(in) / sizeof(in[0]);
    TreeNode* root = buildTree(in, post, len);

    printf("Inorder traversal of the constructed tree is \n");
    printInorder(root);
    printf("\n");
    return 0;
}


/*

Explanation:
createNode(int value): Creates a new tree node.
search(int arr[], int start, int end, int value): Finds the index of a value in the array; used to find the root in the inorder sequence.
buildTreeHelper(int in[], int post[], int inStart, int inEnd, int* postIndex): The recursive helper function to construct the tree. It uses postIndex to pick the current node from the postorder sequence, finds this node's index in the inorder sequence, and constructs the right and left subtrees.
buildTree(int in[], int post[], int n): This is the main function that initializes the necessary variables and calls buildTreeHelper.
printInorder(TreeNode* node): Prints the inorder traversal of the tree to verify the correctness of the constructed tree.
The program constructs the tree from the given inorder and postorder traversal sequences and then prints the inorder traversal of the constructed tree to verify its correctness.
*/
