int count_subsets_util(node *head, int sum, int currentSum) {
    // Base cases
    if (head == NULL) {
        return (currentSum == sum) ? 1 : 0;
    }

    // Include the current node's value in the sum
    int include = count_subsets_util(head->next, sum, currentSum + head->data);

    // Exclude the current node's value from the sum
    int exclude = count_subsets_util(head->next, sum, currentSum);

    return include + exclude;
}

int count_subsets(node *head, int sum) {
    return count_subsets_util(head, sum, 0);
}

//USAGE 

int main() {
    // Create and populate a sorted linked list of positive integers
    node *head = NULL;
    // ... Code to populate the list ...

    int targetSum = 10; // Set your target sum here

    int numberOfSubsets = count_subsets(head, targetSum);
    printf("Number of subsets with sum %d: %d\n", targetSum, numberOfSubsets);

    // Free the linked list
    // ... Code to free the list ...
    return 0;
}

