/*


You are given a 2D integer array edges representing a tree with n nodes, numbered from a to n 1, rooted at node 0, where edges [i] = [u, vi] means there is an edge between the nodes v1 and u1.

You are also given a 0-indexed integer array colors of size n, where colors[i] is the color assigned to node 1.

We want to find a node v such that every node in the subtree of v has the same color.
Return the size of such subtree with the maximum number of nodes possible.


***

To solve this problem, we will need to do a depth-first search (DFS) traversal of the given tree. During the traversal, we will keep track of the color of each node and the size of the subtree rooted at that node where all nodes have the same color.

Here's the algorithm:

Build a tree structure from the given edges array. Since the tree is rooted at node 0, we can represent the tree using an adjacency list.

Perform DFS traversal starting from the root node. During the DFS, maintain a count of each color in the subtree rooted at the current node.

After visiting all children of the current node, check if the count of the current node's color equals the size of the subtree. If it does, update the answer with the size of this subtree if it's larger than the current answer.

Return the size of the largest such subtree found.



*/

int maxSubtreeSize = 0;

struct Node {
    int color;
    List children;
};

// Helper method for DFS that returns the size of the subtree and updates the maximum size
int dfs(Node node, int color[], int[] subtreeColorCount) {
    int currentColorCount = 0;
    int subtreeSize = 1;  // Count the current node

    // Traverse all children
    for (Node child : node.children) {
        int childSubtreeSize = dfs(child, color, subtreeColorCount);
        subtreeSize += childSubtreeSize;

        // If the child's color is the same as the current node's color, increment the count
        if (color[child.id] == color[node.id]) {
            currentColorCount += childSubtreeSize;
        }
    }

    // Update the color count for the current subtree
    subtreeColorCount[color[node.id]] += currentColorCount;

    // If the color count matches the subtree size, we found a valid subtree
    if (subtreeColorCount[color[node.id]] == subtreeSize) {
        maxSubtreeSize = max(maxSubtreeSize, subtreeSize);
    }

    return subtreeSize;
}

// Function to find the size of the largest valid subtree
int findLargestColorSubtree(int n, int edges[][], int colors[]) {
    Node nodes[n];
    // Initialize nodes and build the tree from edges

    int subtreeColorCount[n];  // Array to count colors in the subtree
    // Initialize subtreeColorCount to zero

    // Perform DFS from the root node
    dfs(nodes[0], colors, subtreeColorCount);

    return maxSubtreeSize;
}

