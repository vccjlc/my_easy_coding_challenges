#include "lnad.h"
#include <stdio.h>
#include <stdlib.h>

Tlista *create_node(int data) {
    Tlista *newnode = (Tlista *)malloc(sizeof(Tlista));
    if (newnode != NULL) {
        newnode->val = data;
        newnode->next = NULL;
    }
    return newnode;
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

void nadlista(int n, int A[n], int B[n], Tlista **lista_ptr) {
    *lista_ptr = NULL;
    int i = 0;
    int j = 0;
    while (i < n && j < n) {
        if (A[i] == B[j]) { // Check if yo nexts are bros
            append_node(lista_ptr, A[i]);
            i++;
            j++;                  // Skip'm
        } else if (A[i] < B[j]) { // Them not equal, A small
            append_node(lista_ptr, A[i]);
            i++;
        } else { // A big
            append_node(lista_ptr, B[j]);
            j++;
        }
    }

    if (j < n) {
        while (j < n) {
            append_node(lista_ptr, B[j]);
            j++;
        }
    }

    if (i < n) {
        while (i < n) {
            append_node(lista_ptr, A[i]);
            i++;
        }
    }
}
