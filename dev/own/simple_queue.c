#include <stdio.h>

#define MAX_SIZE 100

// Define the structure "Queue"
struct Queue {
	int arr[MAX_SIZE];
	int front;
	int back;
}

// Function to set initial values
void initializeQueue(struct Queue *queue) {
	queue->front = -1;
	queue->back = -1;
}

//
