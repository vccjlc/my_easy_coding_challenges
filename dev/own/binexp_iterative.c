	#include <stdio.h>

	long binexp(int a, int b) {
	    long result = 1;
	    while(b) {
		    if(b%2 == 1) result *= a; //this line takes the last bit of current b, which if 1 means "multiply by this power"
		    a *= a;
		    b /= 2;
	    }
	    return result;
	}

	int main(void) {
	    int a, b;
	    scanf("%d", &a);
	    scanf("%d", &b);
	    long result = binexp(a, b);
	    printf("%li\n", result);
	    return 0;
	}
