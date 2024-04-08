#include <stdio.h>
#include <stdlib.h>
int main(){
int N; scanf("%d", &N);
int A[N]; for(int i = 0; i < N; i++) scanf("%d", &A[i]);
int wynik;
// Mamy ustalone N, zawartość tablicy A oraz zadeklarowaną zmienną wynik
// ---------------------------------------------------------------------
// Poniżej wpisz swój fragment programu:
//pocalunek - taka para 01, dla ktorej:
//liczba zer po lewej = liczba 1 po prawej
//(tam sie spotykaja Z i J)

wynik = 0;


int licznik_zer = 0;
int licznik_jedynek = 0;
int j = 0;

while (j < N) {
	if (A[j] == 1) {
		licznik_jedynek++;
		j++;
	} else {
		j++;
	}
}
int pocalunek = 0;

for (int i = 0; (i < N - 1) && (pocalunek == 0); i++) {
	if ((A[i] == 0) && (A[i+1] == 1)) {
		licznik_zer++;
		if (licznik_zer == licznik_jedynek) {
			pocalunek = 1;
		}
	} else if (A[i] == 0) {
		licznik_zer++;
	} else if (A[i] == 1) {
		licznik_jedynek--;
	}
}

wynik = pocalunek;

//sprawdzenie zbioru pustego i zakresu
if (N == 0) {
	wynik = 1;
}

int k = 0;

while (k < N) {
	if ((A[k] < 0) || (A[k] > 3)) {
		wynik = 0;
		k = N;
	}
	else {
		k++;
	}
}
printf("%d\n", wynik);
return 0;
}
