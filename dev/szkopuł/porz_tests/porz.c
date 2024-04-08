#include <stdio.h>
#include <stdlib.h>
int main(){
int N; scanf("%d", &N);
int A[N]; for(int i = 0; i < N; i++) scanf("%d", &A[i]);
// Mamy ustalone N oraz zawartość tablicy A 
// ---------------------------------------------------------------------
// Poniżej wpisz swój fragment programu:
int wynik = 0;
if ((N == 0) && (N == 1)) {
	printf("%d\n", wynik);
	exit(0);
}
//znajdz pierwsza ujemna 
int pierwsza_ujemna_indeks = -1;
int i = 0;

while (i < N) {
	if((A[i]) < 0) {
		pierwsza_ujemna_indeks = i;
		break;
	} else {
		i++;
	}
}

if (pierwsza_ujemna_indeks == -1) {
	printf("%d\n", wynik);
	exit(0);
}
		
//zlicz wszystkie dodatnie i zera (nazwane "dodatnie") po pierwszej ujemnej

int dodatnie = 0;
int j = pierwsza_ujemna_indeks + 1;

while (j < N) {
	if (A[j] >= 0) {
		dodatnie++;
		j++;
	} else {
		j++;
	}
}

wynik = dodatnie;

//idac od pierwszej ujemnej do kolejnej, dodaj tylko nastepne dodatnie

int niepotrzebne_dodatnie = 0;
int k = pierwsza_ujemna_indeks + 1;

while(k < N) {
	if (A[k] < 0) {
		wynik = wynik + dodatnie - niepotrzebne_dodatnie;
		k++;
	} else {
		niepotrzebne_dodatnie++;
		k++;
	}
}




// ---------------------------------------------------------------------
printf("%d\n", wynik);
return 0;
}
