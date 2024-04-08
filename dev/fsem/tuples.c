#include <stdio.h>

void drukuj_wacpan_rotacje(int *tuple, int size, int N) {
    int rotated[N];
    // inicjalizuj tablicę indeksami
    for (int i = 0; i < N; i++) {
        rotated[i] = i;
    }

    // wydrukuj wszystkie rotacje
    for (int rot = 1; rot < size; rot++) {
        // wykonaj rotację
        for (int i = 0; i < size; i++) {
            rotated[tuple[i]] = tuple[(i + rot) % size];
        }

        // wydrukuj rotowaną tablicę
        printf("Q[");
        for (int i = 0; i < N; i++) {
            printf("%d", rotated[i]);
            if (i < N - 1)
                printf(",");
        }
        printf("]\n");
    }
}

void licznik_samochodowy(int N, int K) {
    int tuple[K];

    for (int size = K; size >= 2; size--) {
        // ustaw początkową kombinację
        for (int i = 0; i < size; i++) {
            tuple[i] = i;
        }

        // generuj pozostałe kombinacje
        do {
            // wygeneruj zrotowane elementy dla bieżącej kombinacji
            drukuj_wacpan_rotacje(tuple, size, N);

            // znajdź element do inkrementacji
            int i;
            for (i = size - 1; i >= 0 && (tuple[i] == N - size + i); i--)
                ;

            // sprawdź, czy są jeszcze kombinacje
            if (i < 0)
                break;

            // inkrementuj element i zresetuj następne
            tuple[i]++;
            for (int j = i + 1; j < size; j++) {
                tuple[j] = tuple[j - 1] + 1;
            }
        } while (tuple[0] <= N - size);
    }
}

int main() {
    int N, K;

    printf("Podaj waćpan n: ");
    scanf("%d", &N);
    printf("Podaj waćpan k: ");
    scanf("%d", &K);

    if (N > 0 && K > 0 && K <= N) {
        licznik_samochodowy(N, K);

        printf("Q[");
        for (int i = 0; i < N; i++) {
            printf("%d", i);
            if (i < N - 1) {
                printf(",");
            }
        }
        printf("]\n");
    } else {
        printf("ojoj, wartości muszą być większe od zera i k nie może "
               "przekraczać n");
    }

    return 0;
}
