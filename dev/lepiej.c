/**
 * @file        lepszy_pomysl.c
 * @brief       Program sprawdzający, czy kończąca się liściem ścieżka w kopcu binarnym odpowiada
 * danej liście.
 * @author Jan Paraniak
 *
 * Rekurencyjnie:
 * Dla (!d || !l) od razu zwracamy false. Jeśli wartość w aktualnym węźle drzewa jest większa niż
 * wartość z listy, również zwracamy false, ponieważ kolejne wartości w drzewie będą jeszcze większe. Jeśli
 * jest mniejsza, sprawdzamy poddrzewa, ale tylko gdy jesteśmy na lstartm elemencie listy.
 * Jeśli wartości są równe, sprawdzamy czy węzeł drzewa jest liściem i czy element listy jest ostatnim. Zwracamy true
 * jeśli tak, w przeciwnym wypadku porównujemy podścieżki z kolejnymi elementami listy.
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Twezel {
    int val;
    struct Twezel *lsyn;
    struct Twezel *psyn;
} Twezel;

typedef struct Tlista {
    int val;
    struct Tlista *next;
} Tlista;

Twezel *nowy_wezel_drzewa(int value);
Tlista *nowy_element_listy(int value);
Twezel *buduj_drzewo(int *tab, int ind, int rozm);
Tlista *buduj_liste(int *tab, int rozm);
void drukuj_drzewo(Twezel *d, int odstep);
void drukuj_liste(Tlista *l);
void zwolnij_drzewo(Twezel *d);
void zwolnij_liste(Tlista *l);
bool czy_sciezka(Twezel *d, Tlista *l, Tlista *lstart);

bool sciezka(Twezel *d, Tlista *l) {
    Tlista *lstart = l;
    return czy_sciezka(d, l, lstart);
}

bool czy_sciezka(Twezel *d, Tlista *l, Tlista *lstart) {
    if (!l || !d)
        return false;

    if (d->val == l->val) {
        if (d->lsyn == NULL && d->psyn == NULL && l->next == NULL) {
            return true;
        } else {
            return czy_sciezka(d->lsyn, l->next, lstart) || czy_sciezka(d->psyn, l->next, lstart);
        }
    }

    if (d->val > l->val)
        return false;

    if (d->val < l->val) {
        if (l == lstart) {
            return czy_sciezka(d->lsyn, l, lstart) || czy_sciezka(d->psyn, l, lstart);
        } else {
            return false;
        }
    }
}

int main() {
    int drzewo[] = {12, 14, 16, -1, 17, -1, 18}; // wpisywać poziomami
    int lista[] = {12, 16, 18};

    bool oczekiwany_wynik = true;

    int rozmiar_drzewa = sizeof(drzewo) / sizeof(drzewo[0]);
    int rozmiar_listy = sizeof(lista) / sizeof(lista[0]);
    Twezel *d = buduj_drzewo(drzewo, 0, rozmiar_drzewa);
    Tlista *l = buduj_liste(lista, rozmiar_listy);

    printf("Drzewo:\n");
    drukuj_drzewo(d, 0);
    printf("\n");
    drukuj_liste(l);

    bool wynik = sciezka(d, l);
    printf("W tym przypadku funkcja zwraca %s\n", wynik ? "true" : "false");

    if (wynik == oczekiwany_wynik) {
        printf("Test: Algorytm działa dla tego przypadku\n");
    } else {
        printf("Test: Algorytm zwraca inny wynik. Czy oczekiwana wartość jest dobrze wpisana?\n");
    }

    zwolnij_drzewo(d);
    zwolnij_liste(l);

    return 0;
}

Twezel *nowy_wezel_drzewa(int value) {
    Twezel *node = (Twezel *)malloc(sizeof(Twezel));
    node->val = value;
    node->lsyn = NULL;
    node->psyn = NULL;
    return node;
}

Tlista *nowy_element_listy(int value) {
    Tlista *node = (Tlista *)malloc(sizeof(Tlista));
    node->val = value;
    node->next = NULL;
    return node;
}

Twezel *buduj_drzewo(int *tab, int ind, int rozm) {
    if (ind >= rozm || tab[ind] == -1) {
        return NULL;
    }

    Twezel *d = nowy_wezel_drzewa(tab[ind]);
    d->lsyn = buduj_drzewo(tab, 2 * ind + 1, rozm);
    d->psyn = buduj_drzewo(tab, 2 * ind + 2, rozm);
    return d;
}

Tlista *buduj_liste(int *tab, int rozm) {
    if (rozm == 0) {
        return NULL;
    }

    Tlista *l = nowy_element_listy(tab[0]);
    Tlista *akt = l;

    for (int i = 1; i < rozm; ++i) {
        akt->next = nowy_element_listy(tab[i]);
        akt = akt->next;
    }

    return l;
}

void drukuj_drzewo(Twezel *d, int odstep) {
    if (d == NULL)
        return;

    odstep += 8;

    drukuj_drzewo(d->psyn, odstep);

    printf("\n");
    for (int i = 10; i < odstep; ++i)
        printf(" ");
    printf("%d\n", d->val);

    drukuj_drzewo(d->lsyn, odstep);
}

void drukuj_liste(Tlista *l) {
    printf("Lista: ");
    while (l != NULL) {
        printf("%d ", l->val);
        l = l->next;
    }
    printf("\n");
}

void zwolnij_drzewo(Twezel *d) {
    if (d != NULL) {
        zwolnij_drzewo(d->lsyn);
        zwolnij_drzewo(d->psyn);
        free(d);
    }
}

void zwolnij_liste(Tlista *l) {
    while (l != NULL) {
        Tlista *tmp = l;
        l = l->next;
        free(tmp);
    }
}
