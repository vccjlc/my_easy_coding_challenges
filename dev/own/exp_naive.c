#include <stdio.h>

long expa(int a, int b) {
    int result = 1;
    while(b) {
	   result *= a;
	   b--;
    }
    return result;
}

int main(void) {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    long result = expa(a, b);
    printf("%li\n", result);
    return 0;
}
