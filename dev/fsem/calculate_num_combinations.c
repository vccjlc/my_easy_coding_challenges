#include <stdio.h>
// ignore int range
int generate_factorial(int n) {
	if (n == 0 || n == 1) {
		return 1; 
	}
	else {
		return n * generate_factorial(n - 1); 
	}
}

int calculate_num_combinations(int n, int k) {
	int n_factorial = generate_factorial(n);
	int k_factorial = generate_factorial(k);
	int n_minus_k = n - k;
	int n_minus_k_factorial = generate_factorial(n_minus_k);
	int num_combinations = n_factorial / (k_factorial * n_minus_k_factorial);
	return num_combinations;
}

int main(void) {
	int n = 0;
	int k = 0;
	scanf("%d", &n);
	scanf("%d", &k);

	int result = calculate_num_combinations(n, k);

	printf("%d\n", result);

	return 0;
}
