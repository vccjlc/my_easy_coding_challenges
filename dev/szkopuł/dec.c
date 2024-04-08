#include <stdio.h>
#include <stdlib.h>
int main(void){
int N; scanf("%d", &N);
int A[N]; for(int i = 0; i < N; i++) scanf("%d", &A[i]);
int B[N]; for(int i = 0; i < N; i++) scanf("%d", &B[i]);
int C[N];
int D[N];
int wynik = 1;

int Aleading = 0;
int Atrailing = 0;

int Bleading = 0;
int Btrailing = 0;

for (int i = 0; i < N; ++i) { 
if (A[i] != 0) {
Aleading = i; i = N;}
}
for (int i = 0; i < N; ++i) { 
if (B[i] != 0)
{ Bleading = i; i = N;}
}
for (int i = N-1; i >= 0; --i) { 
if (A[i] != 0) {
Atrailing = i; 
i = 0;}
}
for (int i = N-1; i >= 0; --i) { 
if (B[i] != 0) {
Btrailing = i; 
i = 0;}
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
