#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to add one to a negabinary number
void addOneToNegabinary(char *num) {
    int len = strlen(num);

    // Case 1: Number is even (ends with 0)
    if (num[len - 1] == '0') {
        num[len - 1] = '1'; // Simply invert the last bit
    }
    // Case 2: Number is odd (ends with 1)
    else {
        if (len >= 2 && num[len - 2] == '1') {
            // If the number ends with 11, change both bits to 00
            num[len - 1] = '0';
            num[len - 2] = '0';
        } else if (len >= 2 && num[len - 2] == '0') {
            // If the number ends with 01, swap them to make 10 and add 1 to the preceding number
            num[len - 1] = '0';
            num[len - 2] = '1';

            // Add 1 to the binary number before these bits
            for (int i = len - 3; i >= 0; i--) {
                if (num[i] == '0') {
                    num[i] = '1';
                    break;
                } else {
                    num[i] = '0';
                }
            }
        } else {
            // If the number is just 1, it becomes 110
            char newNum[len + 3];
            newNum[0] = '1';
            newNum[1] = '1';
            for (int i = 2; i < len + 2; i++) {
                newNum[i] = num[i - 2];
            }
            newNum[len + 2] = '\0';
            strcpy(num, newNum);
        }
    }
}

int main() {
    char input[1024]; // Buffer to store the input negabinary number

    printf("Enter a negabinary number: ");
    scanf("%1023s", input); // Read input from user

    // Allocate enough memory to handle potential increase in length
    char *num = malloc(strlen(input) + 3);
    if (num == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    strcpy(num, input); // Copy input to dynamically allocated memory

    // Call the function to add one to the negabinary number
    addOneToNegabinary(num);

    printf("Result after adding 1: %s\n", num);

    free(num); // Free the dynamically allocated memory
    return 0;
}
