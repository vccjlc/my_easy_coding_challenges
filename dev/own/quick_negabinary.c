#include <stdio.h>
#include <stdlib.h>

char* quickNegabinary(int number) {
    unsigned int mask = 0xAAAAAAAA;
    unsigned int result = (number + mask) ^ mask;
    char* binaryString = (char*) malloc(sizeof(char) * 33); // 32 bits for int and 1 for null terminator

    // Convert the result to a binary string
    for (int i = 31; i >= 0; i--) {
        binaryString[31 - i] = (result & (1 << i)) ? '1' : '0';
    }

    binaryString[32] = '\0'; // Null-terminate the string
    return binaryString;
}

int main() {
    int number = 0;
    printf("Please enter the number to convert\n");
    scanf("%d", &number);
    char* binaryRepresentation = quickNegabinary(number);
    printf("Negabinary representation of %d is %s\n", number, binaryRepresentation);
    free(binaryRepresentation); // Free the allocated memory
    return 0;
}

