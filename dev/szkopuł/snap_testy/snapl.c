#include <stdio.h>
#include <stdlib.h>

int main() {
    int N; scanf("%d", &N);
    int A[N]; for(int i = 0; i < N; i++) scanf("%d", &A[i]);
    int wynik = 0;
    int aktualna_suma = 0;
    int poprzedni_znak = 0;
    int maks_suma = 0;

    if (N == 0) {
        wynik = 0;
    } else if (N == 1) {
        wynik = (A[0] > 0) ? A[0] : 0;
    } else {
        // N ma 2 lub więcej elementów
       
            
                // główny algorytm dla przemiennych znaków
                for (int i = 0; i < N; i++) {
                    // określ znak bieżącego elementu
                    int biezacy_znak = (A[i] > 0) ? 1 : -1;

                    // jeśli bieżący element ma taki sam znak jak poprzedni,
                    // zacznij na nowo
                    if (biezacy_znak == poprzedni_znak) {
                        aktualna_suma = A[i];
                    } else {
                        aktualna_suma += A[i];
                    }
                    poprzedni_znak = biezacy_znak;

                    // zresetuj aktualna_suma jeśli jest ujemna
                    if (aktualna_suma < 0) {
                        aktualna_suma = 0;
                        poprzedni_znak = 0; //oraz znak
                    }

                    // zaktualizuj maks_suma jeśli trzeba
                    if (maks_suma < aktualna_suma) {
                        maks_suma = aktualna_suma;
                    }
                }
                wynik = maks_suma;
            }
        
        
    
    
    printf("%d\n", wynik);
    return 0;
}

