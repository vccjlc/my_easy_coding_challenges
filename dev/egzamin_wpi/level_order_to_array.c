int countNodes(struct TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void insertLevelOrder(struct TreeNode* root, int* arr, int* index) {
    if (!root) return;

    Queue* q = createQueue();
    enqueue(q, root);

    while (!isQueueEmpty(q)) {
        struct TreeNode* current = dequeue(q);

        // Insert the current node's value into the array
        arr[(*index)++] = current->val;

        // Enqueue left child
        if (current->left != NULL) {
            enqueue(q, current->left);
        }

        // Enqueue right child
        if (current->right != NULL) {
            enqueue(q, current->right);
        }
    }

    // Don't forget to free the queue to prevent memory leaks
    while (!isQueueEmpty(q)) {
        dequeue(q); // This will also free the dequeued QueueNodes
    }
    free(q); // Finally, free the queue structure itself
}

// Example usage
int main() {
    struct TreeNode* root; // Assume root is initialized and points to your tree
    int n = countNodes(root);
    int* arr = (int*)malloc(n * sizeof(int));
    int index = 0;

    insertLevelOrder(root, arr, &index);

    // Now arr contains the tree node values in level order
    // Remember to free arr when done
    free(arr);
}

