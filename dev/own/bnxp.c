#include <stdio.h>


long bnxpi(int base, int exponent) {
	
	long result = 1;
	
	while(exponent) {
		if (exponent % 2 == 1) result *= base;
		base *= base; // tu chyba czasami niepotrzebnie się liczy na końcu
		exponent /= 2;
	}
	return result;
}



int main(void) {

	int base, exponent;
	scanf("%d", &base);
	scanf("%d", &exponent);
	int res;
	
	res = bnxpi(base, exponent);
	
	printf("%d\n", res);


/*
	int base2, exponent2;
	scanf("%d", &base2);
	scanf("%d", &exponent2);
	int res2;
	
	res2 = bnxpi(base2, exponent2);
	
	printf("%d\n", res2);
	
	return 0;
*/
	
}
	
