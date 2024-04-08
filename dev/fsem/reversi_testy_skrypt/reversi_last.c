#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define PUSTY 0
#define CZARNY 1
#define BIALY 2
#define LEGALNE 7
#define WYMIAR 8
#define TURA_CZARNY 10
#define TURA_BIALY 20

typedef int rodzaj_planszy[WYMIAR][WYMIAR];

void inicjalizuj_plansze(rodzaj_planszy plansza) {
    for (int i = 0; i < WYMIAR; ++i) {
        for (int j = 0; j < WYMIAR; ++j) {
            plansza[i][j] = PUSTY;
        }
    }
}

void ustaw_stan_poczatkowy(rodzaj_planszy plansza) {
    plansza[3][3] = BIALY;
    plansza[3][4] = CZARNY;
    plansza[4][3] = CZARNY;
    plansza[4][4] = BIALY;
}

int zmien_ture(int tura) {
    if (tura == TURA_CZARNY) {
        return TURA_BIALY;
    } else {
        return TURA_CZARNY;
    }
}

bool w_zakresie(int i) { return i >= 0 && i < WYMIAR; }

bool sprawdz_kierunek(rodzaj_planszy plansza, int wier, int kol, int dwier,
                      int dkol, int tura) {
    int i, j;
    int zeton_wroga = (tura == TURA_CZARNY) ? BIALY : CZARNY;

    if (plansza[wier][kol] != 0) {
        return false;
    }
    if (!w_zakresie(wier + dwier) || !w_zakresie(kol + dkol)) {
        return false;
    }

    if (plansza[wier + dwier][kol + dkol] != zeton_wroga ||
        plansza[wier + dwier][kol + dkol] == 0) {
        return false;
    }

    for (i = wier + dwier, j = kol + dkol;
         w_zakresie(i) && w_zakresie(j) && plansza[i][j] == zeton_wroga;
         i += dwier, j += dkol) {
        if (plansza[i][j] == 0) {
            return false;
        }
    }

    if (!w_zakresie(i) || !w_zakresie(j) || plansza[i][j] == zeton_wroga ||
        plansza[i][j] == PUSTY) {
        return false;
    }

    return true;
}

bool sprawdz_kazdy(rodzaj_planszy plansza, int wier, int kol, int tura) {
    return sprawdz_kierunek(plansza, wier, kol, -1, -1, tura) ||
           sprawdz_kierunek(plansza, wier, kol, -1, 0, tura) ||
           sprawdz_kierunek(plansza, wier, kol, -1, 1, tura) ||
           sprawdz_kierunek(plansza, wier, kol, 0, -1, tura) ||
           sprawdz_kierunek(plansza, wier, kol, 0, 1, tura) ||
           sprawdz_kierunek(plansza, wier, kol, 1, -1, tura) ||
           sprawdz_kierunek(plansza, wier, kol, 1, 0, tura) ||
           sprawdz_kierunek(plansza, wier, kol, 1, 1, tura);
}

void znajdz_legalne_pola(rodzaj_planszy plansza, int tura,
                         rodzaj_planszy legalne_pola) {
    for (int i = 0; i < WYMIAR; ++i) {
        for (int j = 0; j < WYMIAR; ++j) {
            if (sprawdz_kazdy(plansza, i, j, tura)) {
                legalne_pola[i][j] = LEGALNE;
            }
        }
    }
}

void wypisz_legalne_pola(rodzaj_planszy legalne_pola, int tura) {
    if (tura == TURA_CZARNY) {
        printf("C");
    } else {
        printf("B");
    }

    for (int j = 0; j < WYMIAR; ++j) {
        for (int i = 0; i < WYMIAR; ++i) {
            if (legalne_pola[i][j] == LEGALNE) {
                printf(" %c%d", 'a' + j, i + 1);
            }
        }
    }
    printf("\n");
}

typedef struct {
    int wier, kol;
    bool pas;
    bool przerwij;
} ruch_gracza;

ruch_gracza pobierz_ruch(void) {
    ruch_gracza input = {0, 0, false, false};

    int ch = getchar();

    if (ch == EOF) {
        exit(0);
    }

    if (ch == '-') {
        input.pas = true;
        while ((ch = getchar()) != '\n') {
            if (ch == EOF)
                exit(0);
        }
        return input;
    } else if (ch == '=') {
        input.przerwij = true;
        return input;
    }

    input.kol = ch - 'a';
    ch = getchar();
    if (ch == EOF)
        exit(0);
    input.wier = ch - '1';

    while ((ch = getchar()) != '\n') {
        if (ch == EOF)
            exit(0);
    }

    return input;
}

void obroc_w_kierunku(rodzaj_planszy plansza, int start_wier, int start_kol,
                      int dwier, int dkol, int tura) {
    if (!sprawdz_kierunek(plansza, start_wier, start_kol, dwier, dkol, tura)) {
        return;
    }

    int zeton_wroga = (tura == TURA_CZARNY) ? BIALY : CZARNY;
    int zeton = (tura == TURA_CZARNY) ? CZARNY : BIALY;
    int i = start_wier + dwier;
    int j = start_kol + dkol;

    while (w_zakresie(i) && w_zakresie(j) && plansza[i][j] == zeton_wroga) {
        plansza[i][j] = zeton;
        i += dwier;
        j += dkol;
    }
}

void obroc_kazdy(rodzaj_planszy plansza, int wier, int kol, int tura) {
    obroc_w_kierunku(plansza, wier, kol, -1, -1, tura);
    obroc_w_kierunku(plansza, wier, kol, -1, 0, tura);
    obroc_w_kierunku(plansza, wier, kol, -1, 1, tura);
    obroc_w_kierunku(plansza, wier, kol, 0, -1, tura);
    obroc_w_kierunku(plansza, wier, kol, 0, 1, tura);
    obroc_w_kierunku(plansza, wier, kol, 1, -1, tura);
    obroc_w_kierunku(plansza, wier, kol, 1, 0, tura);
    obroc_w_kierunku(plansza, wier, kol, 1, 1, tura);
}

void wykonaj_ruch(rodzaj_planszy plansza, ruch_gracza input, int *tura) {
    if (input.przerwij) {
        exit(0);
    } else if (input.pas) {
        *tura = zmien_ture(*tura);
        return;
    } else {
        int aktualna_tura = *tura;
        int zeton = (aktualna_tura == TURA_CZARNY) ? CZARNY : BIALY;
        obroc_kazdy(plansza, input.wier, input.kol, aktualna_tura);
        plansza[input.wier][input.kol] = zeton;
        *tura = zmien_ture(*tura);
    }
}

int main(void) {

    rodzaj_planszy plansza;
    rodzaj_planszy legalne_pola;

    inicjalizuj_plansze(plansza);
    ustaw_stan_poczatkowy(plansza);

    int tura = TURA_CZARNY;

    while (true) {
        inicjalizuj_plansze(legalne_pola);
        znajdz_legalne_pola(plansza, tura, legalne_pola);
        wypisz_legalne_pola(legalne_pola, tura);
        ruch_gracza input = pobierz_ruch();
        wykonaj_ruch(plansza, input, &tura);
    }
    return 0;
}
