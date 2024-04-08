#include <stdio.h>
#include <stdlib.h>
int main(){
int N; scanf("%d", &N);
int A[N]; for(int i = 0; i < N; i++) scanf("%d", &A[i]);
// Mamy ustalone N oraz zawartość tablicy A 
// ---------------------------------------------------------------------
// Poniżej wpisz swój fragment programu:

int wynik = 0;
int i = 0;
int j = 1;

if ((N == 0) || (N == 1)) {
	printf("%d\n", wynik);
	exit(0);
}
while(i < N) {
	if (A[i] < 0) {
		while (j < N) {
			if (A[j] >= 0) {
				wynik++;
				j++;
			} else {
				j++;
			}
		}
		i++;
	} else {
		j = i + 1;
		i++;
	}
}


// ---------------------------------------------------------------------
printf("%d\n", wynik);
return 0;
}
