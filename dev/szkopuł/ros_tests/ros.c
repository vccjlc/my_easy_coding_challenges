#include <stdio.h>
#include <stdlib.h>
int main(){
int N; scanf("%d", &N);
int A[N]; for(int i = 0; i < N; i++) scanf("%d", &A[i]);
int wynik;
// Mamy ustalone N, zawartość tablicy A oraz zadeklarowaną zmienną wynik
// ---------------------------------------------------------------------
// Poniżej wpisz swój fragment programu:
int i = 1;
if (N == 0) {
	wynik = 1;
	printf("%d\n", wynik);
	exit(0);
}

while((i < N) && A[i - 1] < A[i]) {
	i++;
}

wynik = (i == N);

printf("%d\n", wynik);
return 0;
}
