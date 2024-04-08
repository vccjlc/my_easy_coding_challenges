#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("The range for int is from %d to %d\n", INT_MIN, INT_MAX);
    printf("The range for long int is from %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("The range for double is from %e to %e\n", DBL_MIN, DBL_MAX);

    return 0;
}
