#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LICZBA_LOSOWAN 6
#define MAKS_LICZBA 49

int sprawdz_czy_powtarza(const int *numery, int liczba, int dlugosc);
void losuj_lotto(int *numery);
int policz_trafienia(const int *wylosowane, const int *kupon);

//losuj lotto rowniez do wypelniania kuponow
void losuj_lotto(int *numery) {
        for (int i = 0; i < LICZBA_LOSOWAN; ++i) {
                int los;
                do {
                        los = rand() % MAKS_LICZBA + 1;
                        numery[i] = los;
                } while (sprawdz_czy_powtarza(numery, los, i));
        }
}

int sprawdz_czy_powtarza(const int *numery, int liczba, int dlugosc) {
        for (int i = 0; i < dlugosc; ++i) {
                if (numery[i] == liczba) {
                        return 1;
                }
        }
        return 0;
}

int policz_trafienia(const int *wylosowane, const int *kupon) {
        int trafienia = 0;
        for (int i = 0; i < LICZBA_LOSOWAN; ++i) {
                for (int j = 0; j < LICZBA_LOSOWAN; ++j) {
                        if (wylosowane[i] == kupon[j]) {
                                trafienia++;
                        }
                }
        } 	
        return trafienia;
}

int main(void) {
        int n;
        scanf("%d", &n);
	//losowanie w Polsacie
        srand(time(NULL));
        int wylosowane_numery[LICZBA_LOSOWAN];
        losuj_lotto(wylosowane_numery);

        int liczba_trafien[7] = {0};
        
	//wypelnianie kuponow i od razu spr. trafien
        for (int i = 0; i < n; ++i) {
                int kupon[LICZBA_LOSOWAN];
                losuj_lotto(kupon);
                int trafienia = policz_trafienia(wylosowane_numery, kupon);
                liczba_trafien[trafienia]++;
        }

        for (int i = 0; i < 7; ++i) {
                printf("%d: %d\n", i, liczba_trafien[i]);
        }

        return 0;
}

