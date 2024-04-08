#include <stdio.h>

int sum_of_squares(int n) {
	if (n == 1) {
		return 1;
	}

	return n*n + sum_of_squares(n-1);
}

int main(void) {
	int n;
	scanf("%d", &n);
	int res = sum_of_squares(n);
	printf("%d\n", res);
	return 0;
}
