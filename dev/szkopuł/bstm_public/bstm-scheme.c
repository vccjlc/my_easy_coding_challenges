#include "drzewo.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

drzewo czytaj_drzewo(int *liczba_wezlow) {
    char b[5];
    scanf("%s", b);
    if (b[0] == 'N') {
        return NULL;
    } else { // b='W'
        (*liczba_wezlow)++;
        drzewo pom = malloc(sizeof(Twezel));
        scanf("%d", &pom->val);
        pom->lsyn = czytaj_drzewo(liczba_wezlow);
        pom->psyn = czytaj_drzewo(liczba_wezlow);
        return pom;
    }
}

void free_drzewo(drzewo d) {
    if (!d) {
        return;
    } else {
        free_drzewo(d->lsyn);
        free_drzewo(d->psyn);
        free(d);
    }
}

/* ROZWIĄZANIE **************************************************************/

int znajdz_k(drzewo d, int k, int *counter) {
    if (!d)
        return INT_MAX;

    int lewy = znajdz_k(d->lsyn, k, counter);
    if (lewy != INT_MAX)
        return lewy;
    if (*counter == k - 1)
        return d->val;

    (*counter)++;

    return znajdz_k(d->psyn, k, counter);
}

int mediana(drzewo d, int *liczba_wezlow) {
    int k = (*liczba_wezlow / 2) + 1;
    int counter = 0;
    return znajdz_k(d, k, &counter);
}

int main() {
    int liczba_wezlow = 0;
    drzewo d = czytaj_drzewo(&liczba_wezlow);

    int med = mediana(d, &liczba_wezlow);

    if (med != INT_MAX) {
        printf("%d\n", med);
    } else {
        printf("Miejmy odwagę!... nie tę jednodniową,\n"
               "Co w rozpaczliwym przedsięwzięciu pryska,\n"
               "Lecz tę, co wiecznie z podniesioną głową\n"
               "Nie da się zepchnąć z swego stanowiska.\n");
    }

    free_drzewo(d);
    return 0;
}
