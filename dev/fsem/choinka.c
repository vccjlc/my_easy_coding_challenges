#include <stdio.h>

int main(void) {
    int n, i, j, s;
    scanf("%d", &n);

    if (n >= 0) {
	//s - szerokosc - liczba gwiadek przy pniu lub dla n == 1 liczba pomocnicza
	if (n == 1) {
		s = 2;
	} else {
    		s = 2 * n - 1;
	}
	//galezie
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= (s / 2) - i + 1; j++) {
                printf(" ");
            }
            for(j = 1; j <= 2*i-1; j++) {
                printf("*");
            }
            for(j = 1; j <= (s / 2) - i + 1; j++) {
                printf(" ");
            }
            printf("\n");
        }
	//pien
        for(i = 1; i <= 3; i++) {
            for(j = 1; j <= s / 2 - 1; j++) {
                printf(" ");
            }
            for(j = 1; j <= 3; j++) {
                printf("*");
            }
            for(j = 1; j <= s / 2 - 1; j++) {
                printf(" ");
            }
            printf("\n");
        }
    
    //dywagacje filozoficzne nasunely wniosek, ze ujemne n oznacza 
    //choinke pniem do gory
    } else {
        n = -n;
	if (n == 1) {
		s = 2;
	} else {
    		s = 2 * n - 1;
	}
        for(i = 1; i <= 3; i++) {
            for(j = 1; j <= s / 2 - 1; j++) { 
                printf(" ");
            }
            for(j = 1; j <= 3; j++) {
                printf("*");
            }
            for(j = 1; j <= s / 2 - 1; j++) {
                printf(" ");
            }
            printf("\n");
        }

        for(i = n; i >= 1; i--) {
            for(j = 1; j <= (s / 2) - i + 1; j++) {
                printf(" ");
            }
            for(j = 1; j <= 2*i-1; j++) {
                printf("*");
            }
            for(j = 1; j <= (s / 2) - i + 1; j++) {
                printf(" ");
            }
            printf("\n");
        }   
    }	

    return 0;
}

