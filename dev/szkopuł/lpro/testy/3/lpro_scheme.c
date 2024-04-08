#include "lpro.h"
#include <stdio.h>
#include <stdlib.h>

#define ASCII_OFFSET '0'

void Insert(Tlista **l, Tlista **kursor, int data);
void Delete(Tlista **l, Tlista **kursor, int ile);
void Forward(Tlista **l, Tlista **kursor, int ile);
void Home(Tlista **l, Tlista **kursor, int ile);
void Move(Tlista **l, Tlista **kursor, int ile);
void Reverse(Tlista **l, Tlista **kursor, int ile);

//// Polecany schemat funkcji przetwórz.
// Na początku i końcu zapewne dokonasz jakiejś inicjalizacji / sprzątania.
// Poszczególne komendy postaraj się zrealizować jako osobne procedury.
// Nie zaszkodzą dodatkowe procedury pomocnicze.

// Możesz dodać i korzystać do debugowania:

Tlista *prekursor = NULL;

void printList(FILE* f, Tlista *l, Tlista *kursor, Tlista *prekursor);


void przetworz(char *program, Tlista **lista_ptr) {
    // Initial print with the cursor at the start
   printList(stderr, *lista_ptr, *lista_ptr, NULL); // No prekursor at the start

    Tlista *kursor = *lista_ptr;

    for (int i = 0; program[i] != 0; i += 2) {
        int k = program[i + 1] - ASCII_OFFSET; // Convert character to digit

        switch (program[i]) {
            case 'I': // insert
                Insert(lista_ptr, &kursor, k);
                break;
            case 'D': // delete
                Delete(lista_ptr, &kursor, k);
                break;
            case 'F': // forward
                Forward(lista_ptr, &kursor, k);
                break;
            case 'R': // reverse
                Reverse(lista_ptr, &kursor, k);
                break;
            case 'M': // move
                Move(lista_ptr, &kursor, k);
                break;
            case 'H': // home
                Home(lista_ptr, &kursor, k);
                break;
        }

        // Print the list after each operation to track changes and positions of cursor and prekursor
     printList(stderr, *lista_ptr, kursor, prekursor);
    }
}


void Delete(Tlista **l, Tlista **kursor, int ile) {
    if (ile == 0 || *kursor == NULL) {
        return;
    }

    Tlista *current = *kursor;
    Tlista *toDelete = NULL;

    while (ile > 0 && current != NULL) {
        toDelete = current;
        current = current->next;
        free(toDelete);
        ile--;
    }

    // After deletion, if prekursor's next is the cursor, we update it.
    // Otherwise, prekursor should remain unchanged.
    if (prekursor && prekursor->next == *kursor) {
        prekursor->next = current;
    }

    // If the deletion started at the head of the list, update the list head
    if (*kursor == *l) {
        *l = current;
    }

    *kursor = current; // Update the cursor to point after the last deleted element
}

void Forward(Tlista **l, Tlista **kursor, int ile) {
    if (ile == 0 || *kursor == NULL)
        return;

    while (ile > 0 && *kursor != NULL) {
        prekursor = *kursor;
        *kursor = (*kursor)->next;
        ile--;
    }
}


Tlista *utworz_wezel(int data) {
    Tlista *newnode = (Tlista *)malloc(sizeof(Tlista));
    if (newnode != NULL) {
        newnode->val = data;
        newnode->next = NULL;
    }
    return newnode;
}


void Insert(Tlista **l, Tlista **kursor, int data) {

    Tlista *nowy_wezel = utworz_wezel(data);

    if (nowy_wezel == NULL) {
     fprintf(stderr,
                "Miej­my po­gar­dę dla py­chy zwy­cię­skiej\n"
                "I przyklaskiwać przemocy nie idźmy\n"
                "Ale nie wielbmy poniesionej klęski\n"
                "I ze słabości swojej się nie szczyćmy\n");
        return;
    }

    // If inserting at the head or into an empty list
    if (*l == *kursor || *l == NULL) {
        nowy_wezel->next = *l;
        *l = nowy_wezel;
        prekursor = nowy_wezel; // No predecessor when inserting at the head
    } else {
        // Find the insertion point
        Tlista *current = *l;
        while (current->next != *kursor && current->next != NULL) {
            current = current->next;
        }

        // Insert the new node before the cursor
        nowy_wezel->next = current->next;
        current->next = nowy_wezel;
        prekursor = nowy_wezel; // Update prekursor to the node before the new node
    }
}


/*
void Insert(Tlista **l, Tlista **kursor, int data) {

    // Utwórz węzeł z danymi do wstawienia
    Tlista *nowy_wezel = utworz_wezel(data);

    if (nowy_wezel == NULL) {
        fprintf(stderr,
                "Miej­my po­gar­dę dla py­chy zwy­cię­skiej\n"
                "I przyklaskiwać przemocy nie idźmy\n"
                "Ale nie wielbmy poniesionej klęski\n"
                "I ze słabości swojej się nie szczyćmy\n");
        return;
    }

    // Jeśli kursor jest na początku lub lista jest pusta
    if (*l == *kursor || *l == NULL) {
        nowy_wezel->next = *l;
        *l = nowy_wezel;
        return;
    }

    // Znajdź miejsce do wstawienia
    Tlista *current = *l;
    while (current->next != *kursor && current->next != NULL) {
        current = current->next;
    }

    // Wstaw przed kursorem
    nowy_wezel->next = current->next;
    current->next = nowy_wezel;
}
*/
void Home(Tlista **l, Tlista **kursor, int ile) {
    // Znajdź element na który ma być ustawiony kursor
    Tlista *current = *l;
    Tlista *prev = NULL;
    while (ile > 0) {
        prev = current;
        prekursor = current;
        current = current->next;
        ile--;
    }
    // Wydawało się niemożliwe, ale się udało. Ustaw kursor
    *kursor = current;
}

void Reverse(Tlista **l, Tlista **kursor, int ile) {
    if (ile <= 1) {
        Forward(l, kursor, ile);
        return;
    }

    Tlista *current = *kursor;
    Tlista *prev = NULL;
    Tlista *next = NULL;

    while (current != NULL && ile > 0) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        ile--;
    }

    if (prekursor != NULL) {
        prekursor->next->next = next;
        prekursor->next = prev;
    } else {
        (*l)->next = next; // Gdy odwracanie zaczyna się od początku listy
        *l = prev;
    }
	
     prekursor = current;
    *kursor = next; // Albo ustawisz kursor po elemencie początkowo wskazywanym
                    // przez kursor
    // Albo będzie źle
    // A przynajmniej niedobrze
}


void Move(Tlista **l, Tlista **kursor, int ile) {
    if (ile == 0) {
        Forward(l, kursor, 1);
        return;
    } else if (ile == 1) {
        Reverse(l, kursor, 2);
        return;
    }
    
    
    // Znajdź element przed kursorem
    Tlista *before_kursor = NULL;
    if (*l != *kursor) {
        before_kursor = *l;
        while (before_kursor != NULL && before_kursor->next != *kursor) {
            before_kursor = before_kursor->next;
        }
    }

    // Wyjmij element kursorowy z listy
    Tlista *element_kursorowy = *kursor;
    if (before_kursor != NULL) {
        before_kursor->next = element_kursorowy->next;
    } else {
        *l = element_kursorowy->next; // Jeśli kursor jest na początku
    }

    // Znajdź miejsce do wstawienia
    Tlista *current = element_kursorowy->next;
    for (int i = 1; i < ile && current->next != NULL; i++) {
        current = current->next;
    }

    // Wstaw element kursorowy z powrotem
    element_kursorowy->next = current->next;
    current->next = element_kursorowy;

    // Ustaw kursor z powrotem
    *kursor = element_kursorowy->next;
    prekursor = element_kursorowy;
}
