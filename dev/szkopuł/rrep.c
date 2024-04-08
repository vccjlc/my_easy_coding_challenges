#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void zaneguj_bity(int *arr, int size);
void dodaj_jeden(int *arr, int size);
void dodaj_tablice_bitow(int *result, int *a, int *b, int size);
void odejmij_tablice_bitow(int *result, int *a, int *b, int size);
int twosComplementToDecimal(int *arr, int size);

int main(void) {
    int N;
    scanf("%d", &N);
    int M;
    scanf("%d", &M);
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
            int result[N+1];
    memset(result, 0, sizeof(result));

    int wynik = 1;

    int Aleading = 0;
    int Atrailing = 0;

    int Bleading = 0;
    int Btrailing = 0;

    for (int i = 0; i < N; ++i) {
        if (Amant[i] != 0) {
            Aleading = i;
            i = N;
        }
    }
    for (int i = 0; i < N; ++i) {
        if (Bmant[i] != 0) {
            Bleading = i;
            i = N;
        }
    }
    for (int i = N - 1; i >= 0; --i) {
        if (Amant[i] != 0) {
            Atrailing = i;
            i = 0;
        }
    }
    for (int i = N - 1; i >= 0; --i) {
        if (Bmant[i] != 0) {
            Btrailing = i;
            i = 0;
        }
    }

    printf("Aleading index: %d\n", Aleading);
    printf("Atrailing index: %d\n", Atrailing);
    printf("Bleading index: %d\n", Bleading);
    printf("Btrailing index: %d\n", Btrailing);

    printf("Array Acecha contents: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", Acecha[i]);
    }
    printf("\n");

    printf("Array Amant contents: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", Amant[i]);
    }
    printf("\n");

    printf("Array Bcecha contents: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", Bcecha[i]);
    }
    printf("\n");

    printf("Array Bmant contents: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", Bmant[i]);
    }
    printf("\n");

    odejmij_tablice_bitow(result, Acecha, Bcecha, N);
    int roznica_cech = twosComplementToDecimal(result, N+1);
    int przesuniecie = Aleading - Bleading;

    
    //mantissae sunt diversae quoad longitudinem
     if (Atrailing - Aleading != Btrailing - Bleading) {
        wynik = 0;
    }
    
    //differentia differt transeatum
    else if (przesuniecie != roznica_cech) {
     wynik  = 0;
     }

    //mantissae sunt in diversis digitis
    else {
        while (Aleading <= Atrailing) {
            if (Amant[Aleading] != Bmant[Bleading]) {
                wynik = 0;
            }
            Aleading++;
            Bleading++;
        }
    }
    
    
    
    printf("%d\n", wynik);

    return 0;
}	


void zaneguj_bity(int *arr, int size) {
 for (int i = 0; i < size; ++i) {
  arr[i] = arr[i] ^ 1; //XOR 
  }
  }
  
void dodaj_jeden(int *arr, int size) {
     int przeniesienie = 1;
     for (int i = size - 1; i >= 0; --i) {
     int suma =  arr[i] + przeniesienie;
     arr[i] = suma % 2;
     przeniesienie = suma / 2;
     if (!przeniesienie) i = size; //break;
     }
     }
     
void dodaj_tablice_bitow(int *result, int *a, int *b, int size) {
    int przeniesienie = 0;
    for (int i = 0; i < size; i++) {
        int suma = a[i] + b[i] + przeniesienie;
        result[i] = suma % 2;
        przeniesienie = suma / 2;
    }
    if (przeniesienie) {
        result[size] = przeniesienie; // nadmiar
    }
}

void odejmij_tablice_bitow(int *result, int *a, int *b, int size) {
//założenie: tablica result ma rozmiar a+1 oraz jest zainicjalizowana zerami
    zaneguj_bity(b, size);
    dodaj_jeden(b, size);
    // Dodaj A oraz -B
    dodaj_tablice_bitow(result, a, b, size);
}



int twosComplementToDecimal(int *arr, int size) {
    int decimal = 0;
    int isNegative = arr[0];

    // Handle negative numbers
    if (isNegative) {
        // Convert two's complement to positive value
        int carry = 1;
        for (int i = size - 1; i >= 0; i--) {
            arr[i] = arr[i] ^ 1; // Flip bits
            arr[i] += carry;
            carry = arr[i] / 2;
            arr[i] %= 2;
        }
    }

    // Convert binary to decimal
    for (int i = size - 1; i > 0; i--) {
        decimal = (decimal << 1) | arr[i];
    }

    // Add the sign bit (MSB)
    if (isNegative) {
        decimal = -((decimal << 1) | 1);
    } else {
        decimal = (decimal << 1) | arr[0];
    }

    return decimal;
}

