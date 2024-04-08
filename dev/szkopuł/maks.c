#include <stdio.h>
int main(void) {
	int x; scanf("%d", &x);
	int y; scanf("%d", &y);
	int z;
// mamy ustalone wartości zmiennych x i y oraz zadeklarowaną zmienną z
// --------------------------
// Poniżej wpisz swój fragment programu:

if (x >= y) {
	z = x;
} else {
	z = y;
}
printf("%d\n",z);
return 0;
}
