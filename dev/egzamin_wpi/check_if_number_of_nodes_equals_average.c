/*


Write a function in C that returns true if and only if the number of edges is equal to the average of the tree of integers. Average of the tree is the average of all tree values

*/

#include <stdbool.h>

// A structure to represent a node in a binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to calculate the total number of nodes in the tree
int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to calculate the sum of all node values in the tree
int calculateSum(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->data + calculateSum(root->left) + calculateSum(root->right);
}

// Function to check the condition 
bool checkEdgeAverage(struct Node* root) {
    int numNodes = countNodes(root);
    int sum = calculateSum(root);
    float average = (float)sum / numNodes;

    // A tree has n - 1 edges where n is the number of nodes
    return (numNodes - 1) == average; 
}

int main() {
    // Example usage: Create a sample tree
    struct Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(2);
    root->left->right = newNode(8);

    if (checkEdgeAverage(root)) {
        printf("The number of edges is equal to the average of the tree.\n");
    } else {
        printf("The number of edges is not equal to the average of the tree.\n");
    }

    return 0;
}

