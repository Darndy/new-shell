#include <stdio.h>
#include <string.h>
#include <unistd.h> // Include the header for the write function

int main(void) {
    char buffer[100]; // Buffer size adjusted to 100 to handle newline and null terminator
    char *token;
    int num_token = 0;
    const char *delim = " \n";

    write(STDOUT_FILENO, "Enter a string: ", sizeof("Enter a string: ") - 1); // Using write instead of printf

    fgets(buffer, sizeof(buffer), stdin);

    // Tokenize the input string
    token = strtok(buffer, delim);
    while (token != NULL) {
        num_token++;
        token = strtok(NULL, delim);
    }

    char num_tokens_str[10]; // Buffer to store the number of tokens as a string
    int num_digits = snprintf(num_tokens_str, sizeof(num_tokens_str), "%d", num_token);

    write(STDOUT_FILENO, "Number of tokens: ", sizeof("Number of tokens: ") - 1);
    write(STDOUT_FILENO, num_tokens_str, num_digits);
    write(STDOUT_FILENO, "\n", sizeof("\n") - 1);

    return 0;
}

