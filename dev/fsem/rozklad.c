#include <stdio.h>


int main(void) {
	int n;
	int i, j, isPrime;

	scanf("%d", &n);

	for (i = 2; i <= n; i++) {
		isPrime = 1;
		for(j = 2; j <= i/2; j++)
		{
			if ((i % j) == 0)
			{
				isPrime = 0;
				break;
			}
		}

		if(isPrime == 1)
		{
			printf("%d\n", i);
		}
	}

	return 0;
}
