#include <stdio.h>


int main(void) {
	long int n = 0;
	long int m = 0;
	scanf("%ld", &n);
	m = n;
	int first_loop = 1;
	printf("%ld = ", n);

	if (n == 2) {
		printf("2\n");
	}
	else {
		for (long int i = 2; i * i <= n; i++) {
			while (n % i == 0) {
				if(!first_loop) {
					printf("* ");
				}
				printf("%ld ", i);
				n = n / i;
				first_loop = 0;
			}
		}
	}
	if (n > 2) {
		if (m != n) {
			printf("*%ld ", n);
		}
		else {
			printf("%ld ", m);
		}
	}
	printf("\n");
	return 0;
}	
