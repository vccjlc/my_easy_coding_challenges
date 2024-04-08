#include "drzewo.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int trojki(drzewo d);
void siegaj_w_rodzine(drzewo dziadek, drzewo ojczym, drzewo synek, int *wynik);
void genealoguj(drzewo d, int *wynik);

drzewo czytaj_drzewo(void) {
    char b[5];
    scanf("%s", b);
    if (b[0] == 'N') {
        return NULL;
    } else { // b='W'
        drzewo pom = malloc(sizeof(Twezel));
        scanf("%d", &pom->val);
        pom->lsyn = czytaj_drzewo();
        pom->psyn = czytaj_drzewo();
        return pom;
    }
}

void free_drzewo(drzewo d) {
    if (d == NULL) {
        return;
    } else {
        free_drzewo(d->lsyn);
        free_drzewo(d->psyn);
        free(d);
    }
}

/* ROZWIĄZANIE **************************************************************/

int trojki(drzewo d) {
    int wynik = 0;
    genealoguj(d, &wynik);
    return wynik;
}

void siegaj_w_rodzine(drzewo dziadek, drzewo ojczym, drzewo synek, int *wynik) {
    if (dziadek && ojczym && synek && ojczym->val > dziadek->val &&
        synek->val > ojczym->val) {
        (*wynik)++;
    }
}

void genealoguj(drzewo d, int *wynik) {
    if (!d) {
        return;
    }

    if (d->lsyn) {
        siegaj_w_rodzine(d, d->lsyn, d->lsyn->lsyn, wynik);
        siegaj_w_rodzine(d, d->lsyn, d->lsyn->psyn, wynik);
        genealoguj(d->lsyn, wynik);
    }

    if (d->psyn) {
        siegaj_w_rodzine(d, d->psyn, d->psyn->lsyn, wynik);
        siegaj_w_rodzine(d, d->psyn, d->psyn->psyn, wynik);
        genealoguj(d->psyn, wynik);
    }
}

int main() {
    drzewo d = czytaj_drzewo();
    printf("%d\n", trojki(d));
    free_drzewo(d);
    return 0;
}
