#include <stdio.h>

int main(void) {
    int a = 1;
    int b = a + a;
    int c = b + a;
    int z = c + c;
    printf("%d\n", z);
    return 0;
}
