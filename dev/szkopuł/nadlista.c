#include<stdlib.h>
#include<stdio.h>
#include "lnad.h"

Tlista *create_node(int data) {
    Tlista *newnode = (Tlista *)malloc(sizeof(Tlista));
    if (newnode != NULL) { // Check if memory allocation was successful
        newnode->val = data;
        newnode->next = NULL;
    }
    return newnode; // returns NULL if allocation failed, otherwise a pointer to
                    // a node
}

void append_node(Tlista **head, int data) {
    Tlista *newnode = create_node(data);
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    Tlista *last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newnode;
}


void nadlista(int N, int A[N], int B[N], Tlista **lista_ptr) {
	
	Tlista *head = NULL;

	int a = 0;
	int b = 0;
	while(a < N || b < N) {
		if (b == N || a < N && A[a] < B[b]) {
		    append_node(lista_ptr, A[a]); a++;
		} else {
		    append_node(lista_ptr, B[b]); b++;
		}
	}
}
	

	
	
		
