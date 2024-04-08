/*


You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.

If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

Note that the nodes have no values and that we only use the node numbers in this problem.


***


To determine if the given nodes form exactly one valid binary tree, we need to check the following conditions:

There is exactly one root node (which has no parents).
All other nodes have exactly one parent.
There are no cycles in the graph formed by the nodes.
The graph is connected (there are no disconnected subtrees).
We can use a combination of a hash table to track the parent of each node and a union-find data structure to check for cycles and ensure that the graph is connected. However, a simpler approach can be to use an array to keep track of the in-degree (number of parents) for each node, and then validate the above conditions.


*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool validateBinaryTreeNodes(int n, int* leftChild, int* rightChild) {
    // Array to store the in-degree of each node
    int inDegree[n];
    // Initialize all in-degrees to 0
    for (int i = 0; i < n; i++) {
        inDegree[i] = 0;
    }

    // Process left and right children arrays to update in-degrees
    for (int i = 0; i < n; i++) {
        if (leftChild[i] != -1) {
            if (++inDegree[leftChild[i]] > 1) {
                // If any node ends up with more than one parent
                return false;
            }
        }
        if (rightChild[i] != -1) {
            if (++inDegree[rightChild[i]] > 1) {
                // If any node ends up with more than one parent
                return false;
            }
        }
    }

    // Find the root node (in-degree of 0) and count the number of roots
    int rootCount = 0;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            rootCount++;
        }
    }

    // There must be exactly one root node and no cycles (rootCount == 1 ensures no cycle)
    return rootCount == 1;
}

int main() {
    int n = 4;
    int leftChild[] = {1, -1, 3, -1};
    int rightChild[] = {2, -1, -1, -1};

    bool isValid = validateBinaryTreeNodes(n, leftChild, rightChild);
    printf("The nodes form a valid binary tree: %s\n", isValid ? "true" : "false");

    return 0;
}

