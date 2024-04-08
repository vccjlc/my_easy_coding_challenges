#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    int B[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &B[i]);

    int wynik = 1;

    int Aleading = 0;
    int Atrailing = 0;
    int Bleading = 0;
    int Btrailing = 0;

    int i = 0, j = N - 1;
    while (i < N) {
        if (A[i] != 0 && Aleading == -1)
            Aleading = i;
        if (B[i] != 0 && Bleading == -1)
            Bleading = i;
        if (Aleading != -1 && Bleading != -1)
            break;
        ++i;
    }
    while (j >= 0) {
        if (A[j] != 0 && Atrailing == -1)
            Atrailing = j;
        if (B[j] != 0 && Btrailing == -1)
            Btrailing = j;
        if (Atrailing != -1 && Btrailing != -1)
            break;
        --j;
    }

    printf("Aleading value: %d\n", Aleading);
    printf("Atrailing value: %d\n", Atrailing);
    printf("Bleading value: %d\n", Bleading);
    printf("Btrailing value: %d\n", Btrailing);

    printf("Array A contents: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    printf("Array B contents: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");

    if (Atrailing - Aleading != Btrailing - Bleading) {
        wynik = 0;
    }

    else {
        while (Aleading <= Atrailing) {
            if (A[Aleading] != B[Bleading]) {
                wynik = 0;
            }
            Aleading++;
            Bleading++;
        }
    }
    printf("%d\n", wynik);
    return 0;
}
