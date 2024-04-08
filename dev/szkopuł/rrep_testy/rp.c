#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int U2_to_dec(int arr[], int size);
void zaneguj_bity(int *arr, int size);
void dodaj_jeden(int *arr, int size);

void extendArray(int original[], int extended[], int size);
int main(void) {
    int N;
    scanf("%d", &N);
    //    printf("Zeskanowano N: %d\n", N);
    int M;
    scanf("%d", &M);
   //     printf("Zeskanowano M: %d\n", M);
    int Acecha[N];
    for (int i = 0; i < N; ++i)
        scanf("%d", &Acecha[i]);
    int Amant[M];
    for (int i = 0; i < M; ++i)
        scanf("%d", &Amant[i]);
    int Bcecha[N];
    for (int i = 0; i < N; ++i)
        scanf("%d", &Bcecha[i]);
    int Bmant[M];
    for (int i = 0; i < M; ++i)
        scanf("%d", &Bmant[i]);

    int wynik = 1;
    if (M == 0) {
     printf("%d\n", wynik);
     exit(0);
     }

    int Aleading = 0;
    int Atrailing = 0;

    int Bleading = 0;
    int Btrailing = 0;

    for (int i = 0; i < M; ++i) {
        if (Amant[i] != 0) {
            Aleading = i;
            break;
        }
    }
    for (int i = 0; i < M; ++i) {
        if (Bmant[i] != 0) {
            Bleading = i;
            break;
        }
    }
    for (int i = M - 1; i >= 0; --i) {
        if (Amant[i] != 0) {
            Atrailing = i;
            break;
        }
    }
    for (int i = M - 1; i >= 0; --i) {
        if (Bmant[i] != 0) {
            Btrailing = i;
            break;
        }
    }
/*
    printf("Aleading index: %d\n", Aleading);
    printf("Atrailing index: %d\n", Atrailing);
    printf("Bleading index: %d\n", Bleading);
    printf("Btrailing index: %d\n", Btrailing);

*/
    printf("Array Acecha contents: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", Acecha[i]);
    }
    printf("\n");

/*
    printf("Array Amant contents: ");
    for (int i = 0; i < M; i++) {
        printf("%d ", Amant[i]);
    }
    printf("\n");
    
    */

    printf("Array Bcecha contents: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", Bcecha[i]);
    }
    printf("\n");

/*
    printf("Array Bmant contents: ");
    for (int i = 0; i < M; i++) {
        printf("%d ", Bmant[i]);
    }
    printf("\n");
    */
    
    zaneguj_bity(Bcecha, N);
    
      printf("Zanegowano bity do Bcecha: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", Bcecha[i]);
    }
    printf("\n");
    
    dodaj_jeden(Bcecha, N);
    
      
      printf("Zanegowano bity ORAZ dodano jeden do Bcecha: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", Bcecha[i]);
    }
    printf("\n");
    
    

    int sum[N];

    int przeniesienie = 0;
    // Bitwise addition with carry
    for (int i = N - 1; i >= 0; --i) {
        int bit_sum = Acecha[i] + Bcecha[i] + przeniesienie;
        sum[i] = bit_sum % 2;
        przeniesienie = bit_sum / 2;
    }



 int roznica_cech = 0;
if (Acecha[0] == 1 && Bcecha[0] == 1) {

    int newSize = N + 1;
        int extended[newSize];
            extendArray(sum, extended, newSize);
    printf("roznica_cech_binarnie: ");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", extended[i]);
    }
        printf("\n");
      roznica_cech = U2_to_dec(extended, newSize);
    }
 else {

printf("roznica_cech_binarnie: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", sum[i]);
        }
            roznica_cech = U2_to_dec(sum, N);
        }
        
              printf("\n");


    int przesuniecie = Aleading - Bleading;
    printf("różnica cech: %d \n", roznica_cech);
   printf("przesuniecie: %d \n", przesuniecie);
   
    

    // mantissae sunt diversae quoad longitudinem
    if (Atrailing - Aleading != Btrailing - Bleading) {
        //printf("mantysy mają różną długość, zwracam 0 \n");
        wynik = 0;
    }

    // differentia differt transeatum
    if (przesuniecie != roznica_cech) {
            //printf("przesunięcie jest różne od różnicy cech, zwracam 0 \n");
        wynik = 0;
    }

    // mantissae sunt in diversis digitis
   
        while (Aleading <= Atrailing) {
            if (Amant[Aleading] != Bmant[Bleading]) {
               // printf("mantysy są różne, zwracam 0 \n");
                wynik = 0;
            }
            Aleading++;
            Bleading++;
        }
    
    printf("%d\n", wynik);
    return 0;
}

void zaneguj_bity(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = arr[i] ^ 1; // XOR
    }
}

void dodaj_jeden(int *arr, int size) {
    int przeniesienie = 1;
    for (int i = size - 1; i >= 0; --i) {
        int suma = arr[i] + przeniesienie;
        arr[i] = suma % 2;
        przeniesienie = suma / 2;
        if (!przeniesienie)
            break;
    }
}

int U2_to_dec(int arr[], int size) {

    int result = 0;
    int jest_ujemna = arr[0];

    // Jesli ujemna, odwroc bity i dodaj jeden
    if (jest_ujemna) {
        for (int i = 0; i < size; i++) {
            arr[i] = !arr[i];
        }
        int carry = 1;
        for (int i = size - 1; i >= 0; i--) {
            int sum = arr[i] + carry;
            arr[i] = sum % 2;
            carry = sum / 2;
        }
    }

    // Zamien na dziesietny
    for (int i = size - 1; i >= 0; i--) {
        result += arr[i] << (size - 1 - i);
    }

    return jest_ujemna ? -result : result;
}


void extendArray(int original[], int extended[], int size) {
    extended[0] = 1; // Set the first element to zero
    for (int i = 1; i < size; i++) {
        extended[i] = original[i - 1];
    }
}

