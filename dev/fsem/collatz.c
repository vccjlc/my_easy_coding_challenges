#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

bool przekracza_max(int liczba) {
    return liczba > (INT_MAX - 1) / 3;
}

bool jest_potega_2(int n) { 
    return n > 0 && (n & (n - 1)) == 0;
}

void przetworz_zakres(int *poczatek, int koniec, int *maks_iteracji) {
    *maks_iteracji = 0;
    while (*poczatek <= koniec) {
        int warunek = 1;
        int x = *poczatek;
        int znaleziono_jedynke = 0;
        int licznik_iteracji = 0;

        while (warunek) {
            if (przekracza_max(x)) {
                warunek = 0;
            } 

            if (x == 1) {
                znaleziono_jedynke = 1;
                warunek = 0;
            }

            licznik_iteracji++;

            if (x % 2 == 0) {
                x = x / 2;
            } else {
                x = 3 * x + 1;
            }
        }

        if (licznik_iteracji > *maks_iteracji) {
            *maks_iteracji = licznik_iteracji;
        }

        if (warunek == 0 && znaleziono_jedynke == 0) {
            printf("%d?\n", *poczatek);
            exit(0);
        }

        (*poczatek)++;
    }
}

int main(void) {
    int a = 0;
    int b = 0;
    int maks_iteracji = 0;

    scanf("%d", &a);
    scanf("%d", &b);

    przetworz_zakres(&a, b, &maks_iteracji);
    printf("%d ", a);
    printf("%d\n", maks_iteracji);

    return 0;
}
