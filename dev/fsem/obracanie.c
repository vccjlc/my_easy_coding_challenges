void obroc_w_kierunku(rodzaj_planszy plansza, int start_wier, int start_kol, int drow, int dcol, int tura) {
    if (!sprawdz_kierunek(plansza, start_wier, start_kol, drow, dcol, tura)) {
    printf("funkcja obroc_w_kierunku: nielegalny kierunek");
        return; // This direction is not legal, so no flipping
    }

    int zeton_wroga = (tura == TURA_CZARNY) ? BIALY : CZARNY;
    int i = start_wier + drow;
    int j = start_kol + dcol;

    while (w_zakresie(i) && w_zakresie(j) && plansza[i][j] == zeton_wroga) {
        plansza[i][j] = (tura == TURA_CZARNY) ? CZARNY : BIALY;
        i += drow;
        j += dcol;
    }
}


void obroc_kazdy(rodzaj_planszy plansza, int wier, int kol, int tura) {
    for (int drow = -1; drow <= 1; ++drow) {
        for (int dkol = -1; dkol <= 1; ++dkol) {
            if (drow == 0 && dkol == 0) continue; // Skip the no-move case
            if (sprawdz_kierunek(plansza, wier, kol, drow, dkol, tura)) {
                obroc_w_kierunku(plansza, wier, kol, drow, dkol, tura);
            }
        }
    }
}
