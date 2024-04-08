#include <stdio.h>

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}


int main(void) {
	int a, b;
	printf("Enter a:\n");
	scanf("%d", &a);
	printf("Enter b:\n");
	scanf("%d", &b);
	int result = gcd(a, b);
	printf("GCD is: \n");
	printf("%d\n", result);
}
