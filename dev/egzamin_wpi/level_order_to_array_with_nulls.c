#include <limits.h> // For INT_MIN

// Assuming Queue structure and related functions (createQueue, enqueue, dequeue, isQueueEmpty) are defined elsewhere

int insertLevelOrder(struct TreeNode* root, int* arr) {
    if (!root) {
        arr[0] = INT_MIN; // If the root is NULL, the first element is INT_MIN
        return 1; // The array has one element, which is INT_MIN
    }

    int index = 0; // Initialize index for insertion into the array
    Queue* q = createQueue();

    // Enqueue root. If root is NULL, INT_MIN will be enqueued as a placeholder
    enqueue(q, root);

    while (!isQueueEmpty(q)) {
        struct TreeNode* current = dequeue(q);

        // Insert the current node's value into the array, or INT_MIN for a NULL node
        arr[index++] = current ? current->val : INT_MIN;

        // If current is not NULL, enqueue its children or INT_MIN placeholders
        if (current) {
            // Enqueue left child or INT_MIN placeholder if left child is NULL
            enqueue(q, current->left ? current->left : (struct TreeNode*)(long)INT_MIN);

            // Enqueue right child or INT_MIN placeholder if right child is NULL
            enqueue(q, current->right ? current->right : (struct TreeNode*)(long)INT_MIN);
        }
    }

    // Free the queue to prevent memory leaks
    while (!isQueueEmpty(q)) {
        dequeue(q); // This may also free the dequeued QueueNodes, depending on implementation
    }
    free(q); // Finally, free the queue structure itself

    return index; // Return the total number of elements inserted into the array
}


int main() {
    // Create the binary tree
    //       1
    //      / \
    //     2   3
    //    /
    //   4
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);

    // Estimate the array size (maximum possible size, considering it's a complete binary tree)
    int maxArraySize = 15; // This should be adjusted based on your tree's actual or expected size

    // Allocate memory for the array
    int* arr = (int*)malloc(sizeof(int) * maxArraySize);

    // Insert nodes into the array in level order and get the size of the array
    int arrSize = insertLevelOrder(root, arr); // For left to right
    // Or use the right to left function
    // int arrSize = insertLevelOrderRightToLeft(root, arr);

    // Print the array
    printf("Tree in array form: ");
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == INT_MIN) {
            printf("null ");
        } else {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    // Free allocated memory
    free(arr);

    return 0;
}
