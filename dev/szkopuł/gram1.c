#include <stdio.h>
#include <stdlib.h>

int main() {
    int N; 
    scanf("%d", &N);
    int A[N]; 
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int wynik = 0;

    // czy pusty
    if (N == 0) {
        wynik = 1;
        printf("%d\n", wynik);
        exit(0);
    }

    // czy są elementy spoza {0,1,2,3}
    int i = N - 1;
    while (i >= 0) {
        if ((A[i] > 3) || (A[i] < 0)) {
            wynik = 0;
            printf("%d\n", wynik);
            exit(0);
        } else {
            i--;
        }
    }

    // czy zero na koncu
    i = N - 1;
    if (A[i] == 0) {
        wynik = 0;
        printf("%d\n", wynik);
        exit(0);
    }

    // czy sa dwa zera obok
    i = N - 2;
    while (i >= 0) {
        if ((A[i] == 0) && (A[i + 1] == 0)) {
            wynik = 0;
            printf("%d\n", wynik);
            exit(0);
        } else {
            i--;
        }
    }

    // czy po ostatnim 0 jest 1 (WK)
    i = N - 2;
    int j = -1;
    // znajdz indeks ostatniego 0
    while (i >= 0) {
        if (A[i] == 0) {
            j = i;
            break;
        } else {
            i--;
        }
    }
    
    if (j != -1) { 
        j++;
        // szukaj 1
        while (j < N) {
            if (A[j] == 1) {
                wynik = 1;
                break;
            } else {
                j++;
            }
        }
    }

    // jesli nie ma jedynki (czyli j doszlo do konca) wynik to zero)
    if (j == N) {
        wynik = 0;
        printf("%d\n", wynik);
        exit(0);
    }

    // czy są dwa niebezpośrednio sasiednie zera, pomiędzy którymi nie ma jedynki
    	i = 0;
    	int stan = 0; // 0 --> szukamy pierwszego zera, 1 -->jestesmy w ciagu 2 i 3
	wynik = 1;

	while (i < N) {
		switch(stan) {
			case 0:
				if(A[i] == 0) {
					stan = 1;
				}
				break;
			case 1:
				if(A[i] == 0) {
					wynik = 0;
					printf("%d\n", wynik);
					exit(0);
				} else if (A[i] == 1) {
					stan = 0;
				}
				break;
		}
		i++;
	}

    printf("%d\n", wynik);
    return 0;
}

