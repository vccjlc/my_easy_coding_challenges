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

void printList(FILE *f, Tlista *l, Tlista *kursor);

Tlista *prekursor = NULL;

void przetworz(char *program, Tlista **lista_ptr) {

    printList(stderr, *lista_ptr, *lista_ptr);

    Tlista *kursor = *lista_ptr;

    for (int i = 0; program[i] != 0; i += 2) {
        int k = program[i + 1] -
                ASCII_OFFSET; // konwersja cyfry na liczbę: '5' -> 5
        switch (program[i]) {
        case 'I': // insert
            // wstawianie nowego elementu zawierającego k
            Insert(lista_ptr, &kursor, k);
            break;

        case 'D': // delete
            // usuwanie k elementów
            Delete(lista_ptr, &kursor, k);
            break;

        case 'F': // forward
            // przesuwanie kursora o k elementów
            Forward(lista_ptr, &kursor, k);
            break;

        case 'R': // reverse
            // odwracanie k elementów
            Reverse(lista_ptr, &kursor, k);
            break;

        case 'M': // move
            // przesuwanie elementu o k w prawo
            Move(lista_ptr, &kursor, k);
            break;

        case 'H': // home
            // ustawianie kursora na k-tym elemencie od początku
            Home(lista_ptr, &kursor, k);
            break;
        }
    }

    printList(stderr, *lista_ptr, NULL);
}

void Delete(Tlista **l, Tlista **kursor, int ile) {
    if (ile == 0 || *kursor == NULL) {
        return;
    }

    Tlista *current = *kursor;
    Tlista *toDelete = NULL;

    for (int i = 0; i < ile && current != NULL; i++) {
        toDelete = current;
        current = current->next;
        free(toDelete);
    }

    // If the deletion started at the head of the list, update the list head
    if (*kursor == *l) {
        *l = current;
    }

    // If prekursor is not NULL, it should point to the node before the first deleted node
    if (prekursor != NULL) {
        prekursor->next = current;
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
        prekursor = NULL; // No predecessor when inserting at the head
    } else {
        // Find the insertion point
        Tlista *current = *l;
        while (current->next != *kursor && current->next != NULL) {
            current = current->next;
        }

        // Insert the new node before the cursor
        nowy_wezel->next = current->next;
        current->next = nowy_wezel;
        prekursor = current; // Update prekursor to the node before the new node
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

  
    // Wyjmij element kursorowy z listy
    Tlista *element_kursorowy = *kursor;
    if (prekursor != NULL) {
        prekursor->next = element_kursorowy->next;
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
    prekursor = element_kursorowy;
    *kursor = element_kursorowy->next;
}


