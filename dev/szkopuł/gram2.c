#include <stdio.h>
#include <stdlib.h>
int main(){
int N; scanf("%d", &N);
int A[N]; for(int i = 0; i < N; i++) scanf("%d", &A[i]);
int wynik;
// Mamy ustalone N, zawartość tablicy A oraz zadeklarowaną zmienną wynik
// ---------------------------------------------------------------------
// Poniżej wpisz swój fragment programu:


//gramatyka - 0 i 1 musza sie pocalowac w ktoryms miejscu (01 musi byc fragmentem)
//moze byc tylko jedno takie miejsce
//na lewo od tego miejsca musi byc tyle samo 0 co jedynek na prawo od tego miejsca
//nie mozemy wykroczyc poza zbior {0,1,2,3} chyba ze slowo jest puste
//nie moze byc jednej cyfry


int wynik_zbior = 1;
int wynik_pocalunek = 1;
int balans = 1;
int jedna_cyfra_test = 1;
int puste_test = 1;

int i = 0;
int j = 0;

//czy jedna cyfra

if (N == 1) {
	jedna_cyfra_test = 0;
}


//tu wszystko powinno byc w if ale nie chce mi sie bo normalnie dalbym exit

//czy zbior
while (i < N) {
	if(A[i] < 0 || A[i] > 3) {
		wynik_zbior = 0;
		i = N;
	} else {
		wynik_zbior = 1;
		i++;
	}
}

//czy jeden pocalunek
int byl_pocalunek = 100;
int nie_bylo_pocalunku = 50;
int stan = nie_bylo_pocalunku;
int kontynuuj = 1;
int indeks_zera_calujacego = 0;

for (int i = 0; i < N - 1 && kontynuuj; i++) {
	if (stan == nie_bylo_pocalunku) {
		if (A[i] == 0 && A[i+1] == 1) {
			indeks_zera_calujacego = i;
			stan = byl_pocalunek;
		}
	} else {
		if (A[i] == 0 && A[i+1] == 1) {
			byl_pocalunek = 200;
			kontynuuj = 0;
		}
	}
}

if ((stan == byl_pocalunek) && (byl_pocalunek == 100) && (kontynuuj == 1)) {
		wynik_pocalunek = 1;
		} else {
			wynik_pocalunek = 0;
		}

//balans
i = 0;
j = 0;

int liczba_zer = 0;
int liczba_jedynek = 0;

if (wynik_pocalunek == 1) {

	i = indeks_zera_calujacego - 1;
	while (i >= 0) {
		if (A[i] == 0) {
			liczba_zer++;
		}
		i--;
	}

	j = indeks_zera_calujacego + 2;
	while (j < N) {
		if (A[j] == 1) {
			liczba_jedynek++;
		}
		j++;
	}
	

	if (liczba_zer == liczba_jedynek) {
		balans = 1;
	} else {
		balans = 0;
	}

}




if (wynik_zbior && wynik_pocalunek && balans && jedna_cyfra_test) {
	wynik = 1;
} else {
	wynik = 0;
}

if (N == 0) {
	wynik = 0;
}

printf("%d\n", wynik);
return 0;
}
