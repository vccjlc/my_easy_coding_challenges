#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double randof(void) {
	return (double)rand() / RAND_MAX;
}

int main(void) 
{
	srand((unsigned) time(NULL));

	int liczba_losowan = 0;
	int punkty_w_cwiartce = 0;
	scanf("%ld", &liczba_losowan);

	if(liczba_losowan == 0) 
	{
		printf("0\n");
		exit(0);
	}

	for (int i = 0; i < liczba_losowan; i++) {
		double x = randof();
		double y = randof(); 
		if ((x * x + y * y) <= 1) {
			punkty_w_cwiartce++;
		}
	}
	
	double przyblizenie_pi = 0;
	przyblizenie_pi = ((double)punkty_w_cwiartce / liczba_losowan) * 4;
	printf("%f\n", przyblizenie_pi);

	return 0;
}			
