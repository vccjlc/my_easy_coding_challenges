#include <stdio.h>

int main(void) {
	long long int a, b, c;

	// Wczytywanie
	scanf("%lld", &a);
	scanf("%lld", &b);
	scanf("%lld", &c);

	//Mediana
	if ((a >= b && a <= c) || (a <= b && a >= c)) {
		printf("%lld\n", a);
	} else if ((b >= a && b <= c) || (b <= a && b >= c)) {
		printf("%lld\n", b);
	} else {
		printf("%lld\n", c);
	}

	return 0;
}

