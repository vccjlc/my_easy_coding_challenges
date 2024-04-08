#include "lpro.h"
#include <stdio.h>
#include <stdlib.h>

#define ASCII_OFFSET '0' 

// Częściowo zoptymalizowany kod
// Mocniejsze testy wydajnościowe by go zapewne pokonały

void Insert(Tlista **l, Tlista **kursor, int data);
void Delete(Tlista **l, Tlista **kursor, int ile);
void Forward(Tlista **l, Tlista **kursor, int ile);
void Home(Tlista **l, Tlista **kursor, int ile);
void Move(Tlista **l, Tlista **kursor, int ile);
void Reverse(Tlista **l, Tlista **kursor, int ile);

Tlista *prekursor = NULL;

void przetworz(char *program, Tlista **lista_ptr) {
    Tlista *kursor = *lista_ptr;
    for (int i = 0; program[i] != 0; i += 2) {
        int k = program[i + 1] - ASCII_OFFSET;
        switch (program[i]) {
        case 'I':
            Insert(lista_ptr, &kursor, k);
            break;
        case 'D':
            Delete(lista_ptr, &kursor, k);
            break;
        case 'F':
            Forward(lista_ptr, &kursor, k);
            break;
        case 'R':
            Reverse(lista_ptr, &kursor, k);
            break;
        case 'M':
            Move(lista_ptr, &kursor, k);
            break;
        case 'H':
            Home(lista_ptr, &kursor, k);
            break;
        }
    }
}

void Delete(Tlista **l, Tlista **kursor, int ile) {
    if (ile == 0 || *kursor == NULL) {
        return;
    }
    if (ile == 1) {
        Tlista *toDelete = *kursor;
        *kursor = toDelete->next;
        if (toDelete == *l) {
            *l = toDelete->next;
        } else {
            prekursor->next = toDelete->next;
        }
        free(toDelete);
        return;
    }
    Tlista *current = *kursor;
    while (ile > 0 && current != NULL) {
        Tlista *toDelete = current;
        current = current->next;
        free(toDelete);
        ile--;
    }
    if (prekursor && prekursor->next == *kursor) {
        prekursor->next = current;
    }
    if (*kursor == *l) {
        *l = current;
    }
    *kursor = current;
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
        fprintf(stderr, "Miejmy pogardę dla pychy zwycięskiej\n"
                        "I przyklaskiwać przemocy nie idźmy\n"
                        "Ale nie wielbmy poniesionej klęski\n"
                        "I ze słabości swojej się nie szczyćmy\n");
        return;
    }
    if (*l == *kursor || *l == NULL) {
        nowy_wezel->next = *l;
        *l = nowy_wezel;
        prekursor = NULL;
    } else {
        nowy_wezel->next = *kursor;
        prekursor->next = nowy_wezel;
    }
    prekursor = nowy_wezel;
}

void Home(Tlista **l, Tlista **kursor, int ile) {
    if (ile == 0) {
        *kursor = *l;
        prekursor = NULL;
    } else {
        Tlista *current = *l;
        Tlista *prev = NULL;
        while (ile > 0 && current != NULL) {
            prev = current;
            current = current->next;
            ile--;
        }
        *kursor = current;
        prekursor = prev;
    }
}

void Move(Tlista **l, Tlista **kursor, int ile) {
    if (ile == 0) {
        Forward(l, kursor, 1);
        return;
    } else if (ile == 1) {
        Reverse(l, kursor, 2);
        return;
    }
    Tlista *before_kursor = NULL;
    if (*l != *kursor) {
        before_kursor = *l;
        while (before_kursor != NULL && before_kursor->next != *kursor) {
            before_kursor = before_kursor->next;
        }
    }
    Tlista *element_kursorowy = *kursor;
    if (before_kursor != NULL) {
        before_kursor->next = element_kursorowy->next;
    } else {
        *l = element_kursorowy->next;
    }
    Tlista *current = element_kursorowy->next;
    for (int i = 1; i < ile && current->next != NULL; i++) {
        current = current->next;
    }
    element_kursorowy->next = current->next;
    current->next = element_kursorowy;
    *kursor = element_kursorowy->next;
    prekursor = element_kursorowy;
}

void Reverse(Tlista **l, Tlista **kursor, int ile) {
    if (ile <= 1) {
        Forward(l, kursor, ile);
        return;
    }
    Tlista *current = *kursor;
    Tlista *prev = NULL;
    Tlista *next = NULL;
    Tlista *last = *kursor;
    for (int i = 0; current != NULL && i < ile; i++) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    if (*kursor != *l) {
        Tlista *temp = *l;
        while (temp->next != *kursor) {
            temp = temp->next;
        }
        temp->next = prev;
    } else {
        *l = prev;
    }
    last->next = current;
    *kursor = current;
    prekursor = last;
}
