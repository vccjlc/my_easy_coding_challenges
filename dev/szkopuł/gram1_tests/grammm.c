#include <stdio.h>
#include <stdlib.h>
int main(){
int N; scanf("%d", &N);
int A[N]; for(int i = 0; i < N; i++) scanf("%d", &A[i]);
int wynik;
// Mamy ustalone N, zawartość tablicy A oraz zadeklarowaną zmienną wynik
// ---------------------------------------------------------------------
// Poniżej wpisz swój fragment programu:


wynik = 1;
int stan_A = -1; //ostatnio nie bylo zera
int stan_B = -2; // bylo zero, szukamy 1

int stan = stan_A;
for (int i = 0; i < N && wynik; i++) {
	if (stan == stan_A) {
		 if (A[i] == 0) {
			 stan = stan_B;
		 } else if (A[i] < 0 || A[i] > 3) {
			 wynik = 0;
		 }
	} else {
		if (A[i] < 1 || A[i] > 3) {
			wynik = 0;
		} else if (A[i] == 1) {
			stan = stan_A;
		}
}
}

if (wynik){
	wynik = (stan == stan_A);
}
			
printf("%d\n", wynik);
return 0;
}
