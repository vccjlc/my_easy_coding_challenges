#include <stdio.h>

void rozklad(int n)
{
	printf("%d ", n);
	printf("= ");
	while (n % 2 == 0) {
		printf("%d ", 2);
		printf("* ");
		n = n / 2;
	}

	for (int i = 3; i * i <= n; i = i + 2) {
		while (n % i == 0) {
			printf("%d ", i);
			printf("* ");
			n = n / i;
		}
	}

	if (n > 2)
		printf("%d\n", n);
}

int main()
{
	int n;
	scanf("%d", &n);
	rozklad(n);
	return 0;
}


