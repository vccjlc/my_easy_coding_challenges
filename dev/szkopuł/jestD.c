#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int D; scanf("%d", &D);
	int N; scanf("%d", &N);
	int A[N]; for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
	int jestD = 0;


	int niema = 1;
	int p = 0; //poczatek gasienicy 
	int k = 0; //koniec gasienicy
	int suma = 0;

	//dla indeksow < p nie ma dobrego segmentu

	while (k < N && niema) {
		if (A[k] == D) {
			niema = 0;
		} else if (A[k] > D) {
			suma = 0;
			k++;
			p = k;
		} else { //A[k] < D
			suma += A[k];
			if (suma == D) {
				niema = 0;
			} else if (suma < D) {
				k++;
			} else { //suma > D, wiec sprawdzamy podsegmenty
				while (p < k && niema) {
					suma -= A[p];
					if (suma == D) {
						niema = 0;
					} else {
						p++;
					} 
				}
				k++;
			}
		}
	}

	jestD = !(niema)
	
	
	printf("%d\n", jestD);
	return 0;
}

