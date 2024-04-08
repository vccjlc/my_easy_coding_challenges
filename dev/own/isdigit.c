#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char input[] = "Hello, 123 World! 456";
    int length = strlen(input);
    char *ptr;

    for (int i = 0; i < length; ) {
        if (isdigit(input[i])) {
            // strtol converts the substring starting at input[i] into a long integer
            long val = strtol(&input[i], &ptr, 10);

            // Print the integer
            printf("Found integer: %ld\n", val);

            // Move the index i to the end of the current number
            i = ptr - input;
        } else {
            // If it's not a digit, just move to the next character
            i++;
        }
    }

    return 0;
}

