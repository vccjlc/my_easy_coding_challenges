include <stdio.h>

int main(void) {
	
	double s = 0;
	double k = 0;
	int n = 0;
	double result = 0;

	scanf("%lf", &s);
	scanf("%lf", &k);
	scanf("%d", &n);
	result = (n*(0.5)*(2*s+(n-1)*k));
	printf("%.6lf\n", result);
	return 0;
	}
