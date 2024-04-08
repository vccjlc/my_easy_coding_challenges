#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randof11() {
	return (int)(rand() % 11);
}

void generuj(long int n, long int lista[11]) {
	for (int i = 0; i < 11; i++) {
		lista[i] = 0;
	}

	for (long int i = 0; i < n; i++) {
		long int x = randof11();
		lista[x]++;
	}
}

int main(void) {
	srand((unsigned)time(NULL));

    	long int n = 0;
    	scanf("%ld", &n);
	if (n <= 0) {
		exit(0);
	}

	if (n <= 10) {
		printf("zbyt mala proba\n");
	}

    	long int lista[11] = {0};
    	generuj(n, lista);

	//skrajne wartosci
	long int maks = lista[0];
	long int min = lista[0];

    	for (int i = 0; i < 11; i++) {
		if (lista[i] > maks) {
			maks = lista[i];
		}
	}
    	
	for (int i = 0; i < 11; i++) {
		if (lista[i] < min) {
			min = lista[i];
		}
	}
	
	long int zakres = maks - min;
	
	//skalowanie	
	long int zeskalowana_lista[11] = {0};

	if (maks != min) {
    		for (int i = 0; i < 11; i++) {
			if (lista[i] == maks) {
				zeskalowana_lista[i] = 20;
				} else if (lista[i] == min) {
					zeskalowana_lista[i] = 3;
				} else {
					zeskalowana_lista[i] = (int) ((((double)lista[i] - min) / zakres) * 17 + 3);
				}
			}
	} else {
		for (int i = 0; i < 11; i++) {
			zeskalowana_lista[i] = 20;
		}
	}

	//pisz
	
	printf("+");
	printf("-----------------------");
	printf("+\n");

	for (int i = 0; i < 20; i++) {
		printf("| ");
		for (int j = 0; j < 11; j++) {
			if (zeskalowana_lista[j] >= (20 - i)) {
				printf("* ");
			} else {
				printf("  ");
			}
		}
		printf("|\n");
	}

	
	printf("+");
	printf("-----------------------");
	printf("+\n");


	return 0;
}
