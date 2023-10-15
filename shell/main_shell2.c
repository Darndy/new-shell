#include "dpshell.h"
/**
 *
 *
 */

void printNumTokens(int num_token) {
    char num_tokens_str[10];
    int num_digits = snprintf(num_tokens_str, sizeof(num_tokens_str), "%d", num_token);

    write(STDOUT_FILENO, "Number of tokens: ", sizeof("Number of tokens: ") - 1);
    write(STDOUT_FILENO, num_tokens_str, num_digits);
    write(STDOUT_FILENO, "\n", sizeof("\n") - 1);
}

int main(void) {
    char buffer[50];
    char *token;
    int num_token = 0;
    const char *delim = " \n";

    write(STDOUT_FILENO, "Enter a string: ", sizeof("Enter a string: ") - 1);

    fgets(buffer, sizeof(buffer), stdin);

    // Tokenize the input string
    token = strtok(buffer, delim);
    while (token != NULL) {
        num_token++;
        token = strtok(NULL, delim);
    }

    printNumTokens(num_token); // Call the function to print the number of tokens
    return 0;
}

