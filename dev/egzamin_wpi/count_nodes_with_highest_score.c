/*

There is a binary tree rooted at 0 consisting of n nodes. The nodes are labeled from 0 to n - 1. You are given a 0-indexed integer array parents representing the tree, where parents[i] is the parent of node i. Since node 0 is the root, parents[0] == -1.

Each node has a score. To find the score of a node, consider if the node and the edges connected to it were removed. The tree would become one or more non-empty subtrees. The size of a subtree is the number of the nodes in it. The score of the node is the product of the sizes of all those subtrees.

Return the number of nodes that have the highest score.
    
}
*/




#include <stdio.h>
#include <stdlib.h>

// Structure to represent an adjacency list node
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Function to create a new adjacency list node
Node* newNode(int value) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->value = value;
    n->next = NULL;
    return n;
}

// Function to add an edge to an undirected graph
void addEdge(Node** adjList, int src, int dest) {
    // Add an edge from src to dest. A new node is added to the adjacency list of src.
    Node* n = newNode(dest);
    n->next = adjList[src];
    adjList[src] = n;
}

long long dfs(Node** adjList, long long* scores, int node, int size) {
    long long prod = 1, sum = 1;
    Node* temp = adjList[node];
    while (temp != NULL) {
        int cnt = dfs(adjList, scores, temp->value, size);
        prod *= cnt;
        sum += cnt;
        temp = temp->next;
    }
    scores[node] = prod * (node != 0 ? (long long)size - sum : 1);
    return sum;
}

int countHighestScoreNodes(int* parents, int parentsSize) {
    Node** adjList = (Node**)malloc(parentsSize * sizeof(Node*));
    for (int i = 0; i < parentsSize; i++) {
        adjList[i] = NULL;
    }

    for (int i = 1; i < parentsSize; i++) {
        addEdge(adjList, parents[i], i);
    }

    long long* scores = (long long*)malloc(parentsSize * sizeof(long long));
    dfs(adjList, scores, 0, parentsSize);

    long long maxScore = 0;
    for (int i = 0; i < parentsSize; i++) {
        if (scores[i] > maxScore) {
            maxScore = scores[i];
        }
    }

    int count = 0;
    for (int i = 0; i < parentsSize; i++) {
        if (scores[i] == maxScore) {
            count++;
        }
    }

    // Cleanup
    for (int i = 0; i < parentsSize; i++) {
        Node* temp = adjList[i];
        while (temp != NULL) {
            Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(adjList);
    free(scores);

    return count;
}

