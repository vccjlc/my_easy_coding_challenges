/**
 * @file        petlik_final.c
 * @brief       Program to interpret and execute "Petlik" language code.
 *
 * This program reads and executes code written in the "Petlik" programming
 * language, and outputs the values of specified variables. Variable values are
 * managed using an array of unsigned long long integers. Addition is based on
 * a number system with a base of 10^18, with a least significant digit on the
 * left.
 *
 * "Petlik" code is read in segments (called "partitions") delineated by
 * parentheses. Free-standing variables outside of these segments are simply
 * incremented. Segments within parentheses are processed recursively, with a
 * distinction made between those with nested parentheses and those without.
 *
 * Segments with nested parentheses are handled using a "while" loop, and
 * processing of segments without nested parentheses is optimized by adding the
 * value of the first variable directly to subsequent variables before clearing
 * the first.
 *
 * As per the task description, it is assumed that the input is correct and
 * calls to memory allocation functions with proper arguments will be
 * successful.
 */

#define _POSIX_C_SOURCE 200809L
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_VARIABLES 26         // Number of variables used
#define BASE 1000000000000000000 // Base of the number system
#define BASE_DIGITS 18
#define INIT_DIGITS 1 // Initial number of "big digits" in an array
#define SEC_CHAR 1    // Second input character
#define ASCII_OFFSET 'a'

// Array to track the current size of each variable's value
int current_sizes[NUM_VARIABLES];
typedef unsigned long long int **bignums;

bignums initialize_array(size_t digits);
void clear_variable(bignums array, char variable);
void print_value(bignums array, char variable);
void extend_array(bignums array, int index, int current_digits);
void add(bignums array, char incremented_variable, char addend);
void process_code(bignums array, const char *input);
void process_partition(bignums array, const char *start, const char *end);
void add_within_partition(bignums array, const char *start, const char *end);
void increment_variable(bignums array, char variable);
void decrement_variable(bignums array, char variable);
bool is_nonzero(bignums array, char variable);
const char *find_matching_parenthesis(const char *start, const char *end);

int main(void) {
    bignums array = initialize_array(INIT_DIGITS);
    char *line = NULL;
    size_t buffer = 0;
    ssize_t num_chars;

    while ((num_chars = getline(&line, &buffer, stdin)) != -1) {
        if (num_chars > 0) {
            if (line[0] == '=') {
                print_value(array, line[SEC_CHAR]);
            } else {
                process_code(array, line);
            }
        }
    }
    for (int i = 0; i < NUM_VARIABLES; ++i) {
        free(array[i]);
    }
    free(array);
    free(line);
    return 0;
}

bignums initialize_array(size_t digits) {
    bignums array = malloc(NUM_VARIABLES * sizeof(unsigned long long int *));

    for (size_t i = 0; i < NUM_VARIABLES; ++i) {
        // Set inital values to 0 using calloc
        array[i] = calloc(digits, sizeof(unsigned long long int));
        if (!array[i]) {
            // Free previously allocated memory
            while (i > 0) {
                free(array[--i]);
            }
            free(array);
            exit(EXIT_FAILURE);
        }
        current_sizes[i] =
            (int)digits; // Cast to int to match the current_sizes array type
    }
    return array;
}

// Check if the variable's value is greater than zero
bool is_nonzero(bignums array, char variable) {
    int index = variable - ASCII_OFFSET;
    int current_digits = current_sizes[index];
    // Check if any digit is non-zero
    for (int i = 0; i < current_digits; ++i) {
        if (array[index][i] != 0) {
            return true;
        }
    }
    return false;
}

// Set the variable value to 0
void clear_variable(bignums array, char variable) {
    int index = variable - ASCII_OFFSET;
    int current_digits = current_sizes[index];

    for (int i = 0; i < current_digits; ++i) {
        array[index][i] = 0;
    }
}

// Print variable's value as decimal
void print_value(bignums array, char variable) {
    int index = variable - ASCII_OFFSET;
    int current_digits = current_sizes[index];
    bool start_printing = false;
    bool found_non_zero_digit = false;

    for (int i = current_digits - 1; i >= 0; --i) {
        // Start printing once we find the first non-zero digit
        if (array[index][i] != 0) {
            found_non_zero_digit = true;
        }
        if (found_non_zero_digit) {
            if (start_printing) {
                // If we have already started printing, pad the number
                printf("%018llu", array[index][i]);
            } else {
                // This is the first non-zero digit, print as is
                printf("%llu", array[index][i]);
                start_printing =
                    true; // Set flag to start padding subsequent digits
            }
        }
    }

    // If we never found a non-zero digit, the number is zero
    if (!found_non_zero_digit) {
        putchar('0');
    }
    printf("\n");
}

// Extend array for addition of two values or to increment
void extend_array(bignums array, int index, int current_digits) {
    size_t new_size =
        (size_t)(current_digits + 1) * sizeof(unsigned long long int);
    unsigned long long int *temp = realloc(array[index], new_size);

    if (temp == NULL) {
        exit(EXIT_FAILURE);
    }

    array[index] = temp;
    // Explicitly set the newly allocated cell to 0
    array[index][current_digits] = 0;
    // Increment the size counter for the current variable
    current_sizes[index]++;
}

// Add two values
void add(bignums array, char incremented_variable, char addend) {
    int index1 = incremented_variable - ASCII_OFFSET;
    int index2 = addend - ASCII_OFFSET;

    // Ensure both variables have the same number of digits
    while (current_sizes[index1] < current_sizes[index2]) {
        extend_array(array, index1, current_sizes[index1]);
    }
    while (current_sizes[index2] < current_sizes[index1]) {
        extend_array(array, index2, current_sizes[index2]);
    }

    // Perform the addition with proper carry
    unsigned long long carry = 0;
    for (int i = 0; i < current_sizes[index1]; ++i) {
        unsigned long long sum = array[index1][i] + array[index2][i] + carry;
        carry = sum / BASE;
        array[index1][i] = sum % BASE;
    }

    // Handle case where carry is present after the final iteration
    if (carry > 0) {
        extend_array(array, index1, current_sizes[index1]);
        array[index1][current_sizes[index1] - 1] = carry;
    }
}

// Add 1 to variable's value
// Functions 'increment_variable' and 'add' are separated for clarity
void increment_variable(bignums array, char variable) {
    int index = variable - ASCII_OFFSET;

    int current_digits = current_sizes[index];
    unsigned long long int max_digit = BASE - 1;
    bool carry = true; // Flag to indicate if we need to carry

    // Increment the least significant digit
    if (array[index][0] < max_digit) {
        array[index][0]++;
        carry = false; // No carry needed, increment done
    }

    // Handle carry if needed
    int i = 0;
    while (carry && i < current_digits) {
        if (array[index][i] < max_digit) {
            array[index][i]++;
            carry = false; // Carry handled, no need to continue
        } else {
            array[index][i] = 0; // Set current digit to 0 and move to the next
            i++;
        }
    }

    // If went through all digits and still have a carry, extend the array
    if (carry) {
        extend_array(array, index, current_digits);
        array[index][current_digits] =
            1; // Set the new digit to 1 to represent the carry
    }
}

// Subtract 1 from variable's value
void decrement_variable(bignums array, char variable) {
    int index = variable - ASCII_OFFSET;
    int current_digits = current_sizes[index];

    // Check if the variable is already zero
    bool is_zero = true;
    for (int i = 0; i < current_digits; ++i) {
        if (array[index][i] != 0) {
            is_zero = false;
        }
    }

    if (!is_zero) {
        // Only proceed if the variable is not zero
        if (array[index][0] > 0) {
            array[index][0]--;
        } else {
            // Handle borrowing
            int i = 0;
            while (i < current_digits && array[index][i] == 0) {
                array[index][i] = BASE - 1; // Borrow from the next digit
                ++i;
            }
            // After finding a non-zero digit, decrement it
            if (i < current_digits) {
                array[index][i]--;
            }
        }
    }
}

// Perform optimized addition and clear of the first variable
void add_within_partition(bignums array, const char *start, const char *end) {
    if (start == end || *start == '(' || *start == ')')
        return;
    char first = *start;
    for (const char *q = start + 1; q < end; ++q) {
        if (*q != '(' && *q != ')') {
            add(array, *q, first);
        }
    }
    clear_variable(array, first);
}

// Function that accepts "Petlik" code and divides input line into segments
void process_code(bignums array, const char *input) {
    int bracket_depth = 0;
    const char *partition_start = NULL;

    for (const char *p = input; *p; ++p) {
        switch (*p) {
        case '(':
            if (bracket_depth == 0) {
                partition_start = p + 1; // Start of a new partition
            }
            bracket_depth++;
            break;
        case ')':
            bracket_depth--;
            if (bracket_depth == 0 && partition_start) {
                // End of the current partition, process it
                process_partition(array, partition_start, p);
                partition_start = NULL; // Reset partition_start
            }
            break;
        default:
            if (isalpha(*p) && bracket_depth == 0) {
                // We're outside brackets and have found a
                // single variable
                increment_variable(array, *p);
            }
            break;
        }
    }
}

// Function to process the partition of the input string from start to end
void process_partition(bignums array, const char *start, const char *end) {
    bool has_open_parenthesis = false;
    for (const char *p = start; p < end && !has_open_parenthesis; ++p) {
        if (*p == '(') {
            has_open_parenthesis = true;
        }
    }

    if (has_open_parenthesis) {
        char first_letter = *start;
        while (is_nonzero(array, first_letter) > 0) {
            decrement_variable(array, first_letter);

            for (const char *p = start + 1; p < end; ++p) {
                if (*p == '(') {
                    const char *nested_start = p + 1;
                    const char *nested_end =
                        find_matching_parenthesis(nested_start, end);
                    process_partition(array, nested_start, nested_end);
                    p = nested_end; // Skip to the end of the nested partition
                } else {
                    increment_variable(array, *p);
                }
            }
        }
    } else {
        add_within_partition(array, start, end);
    }
}

// Get the position of parenthesis that closes partition
const char *find_matching_parenthesis(const char *start, const char *end) {
    int depth = 1;
    for (const char *p = start; p < end; ++p) {
        if (*p == '(') {
            depth++;
        } else if (*p == ')') {
            depth--;
            if (depth == 0) {
                return p;
            }
        }
    }
    return end; // If no matching parenthesis is found
}
