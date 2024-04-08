#include <stdio.h>
#include <stdlib.h>

int main()
{
        int N; 
        scanf("%d", &N);
        int A[N]; 
        for(int i = 0; i < N; i++) 
                scanf("%d", &A[i]);
        
        int wynik;
        // Mamy ustalone N, zawartość tablicy A oraz zadeklarowaną zmienną wynik
        // ---------------------------------------------------------------------
        // Poniżej wpisz swój fragment programu:
        // ---------------------------------------------------------------------

        int L = 0;
        int R = N - 1;
        int lewy = 0;
        int prawy = 0;

        if (N == 1) 
        {
                wynik = 1;
        } 
        else 
        {
                while (L < R) 
                {
                        int mid = L + (R - L) / 2;

                        if (A[mid] < A[mid + 1])  // jestesmy z lewej
                        { 
                                L = mid + 1;
                        }
                        else if (A[mid] > A[mid + 1] || A[mid] == A[mid + 1])  // jestesmy z prawej lub na plwz
                        { 
                                R = mid;
                        }

                        if (L == R) 
                        {
                                lewy = L;
                        }

                }
		L = 0;
		R = N - 1;

                while (L < R) 
                {
                        int mid = L + (R - L) / 2;

                        if (A[mid] < A[mid + 1] || A[mid] == A[mid + 1])  // jestesmy z lewej lub na plwz
                        { 
                                L = mid + 1;
                        }
                        else if (A[mid] > A[mid + 1])  // jestesmy z prawej lub na plwz
                        { 
                                R = mid;
                        }

                        if (L == R) 
                        {
                                prawy = R; 
                        }


                }


                wynik = prawy - lewy + 1;
        }

        printf("%d\n", wynik);
        return 0;
}

